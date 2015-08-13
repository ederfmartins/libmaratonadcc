const int DIG = 4;
const int BASE = 10000; // BASE**3 < 2**51
const int TAM = 1000;

struct BigInt
{
	int num[TAM], numDigits;
	BigInt(int x = 0): numDigits(1)
	{
		memset(num, 0, sizeof(num));
		num[numDigits++] = x; fixInvariant();
	}
	BigInt(char *s): numDigits(1)
	{
		memset(num, 0, sizeof(num));
		int sign = 1;

		while (*s && !isdigit(*s))
		{
			if (*s++ == '-') sign *= -1;
		}

		char *t = strdup(s), *p = t + strlen(t);

		while (p > t)
		{
			*p = 0; p = max(t, p - DIG);
			sscanf(p, "%d", &num[numDigits]);
			num[numDigits++] *= sign;
		}

		free(t);
		fixInvariant();
	}

	BigInt& fixInvariant(int m = 0)
	{
		numDigits = max(m, numDigits);
		int sign = 0;

		for (int i = 1, carry = 0; i <= numDigits || carry && (numDigits = i); i++)
		{
			num[i] += carry;
			carry = num[i] / BASE;
			num[i] %= BASE;
			if (num[i]) sign = (num[i] > 0) ? 1 : -1;
		}

		for (int i = 1; i < numDigits; i++)
		{
			if (num[i] * sign < 0)
			{
				num[i] += sign * BASE;
				num[i+1] -= sign;
			}
		}

		while (numDigits && !num[numDigits]) numDigits--;
		return *this;
	}

	//Comparacao
	int cmp(const BigInt& x = 0) const
	{
		int i = max(numDigits, x.numDigits), t = 0;
		while (1)
		{
			if ((t = ::cmp(num[i], x.num[i])) || i-- == 0) return t;
		}
	}

	bool operator <(const BigInt& x) const { return cmp(x) < 0; }
	bool operator >(const BigInt& x) const { return cmp(x) > 0; }
	bool operator <=(const BigInt& x) const { return cmp(x) <= 0; }
	bool operator >=(const BigInt& x) const { return cmp(x) >= 0; }
	bool operator ==(const BigInt& x) const { return cmp(x) == 0; }
	bool operator !=(const BigInt& x) const { return cmp(x) != 0; }

	//operacoes fundamentais
	BigInt& operator +=(const BigInt& x)
	{
		for (int i = 1; i <= x.numDigits; i++) num[i] += x.num[i];
		return fixInvariant(x.numDigits);
	}
	BigInt& operator -=(const BigInt& x)
	{
		for (int i = 1; i <= x.numDigits; i++) num[i] -= x.num[i];
		return fixInvariant(x.numDigits);
	}

	void multiAndAcumWithShift(const BigInt& x, int m, int b)
	{ // *this += (x * m) << b;
		for (int i = 1, carry = 0; (i <= x.numDigits || carry) && (numDigits = i + b); i++)
		{
			num[i+b] += x.num[i] * m + carry;
			carry = num[i+b] / BASE;
			num[i+b] %= BASE;
		}
	}

	BigInt operator *(const BigInt& x) const
	{
		BigInt r;
		for (int i = 1; i <= numDigits; i++) r.multiAndAcumWithShift(x, num[i], i-1);
		return r;
	}

	BigInt div(const BigInt& x)
	{
		if (x == 0) return 0;

		BigInt q;
		q.numDigits = max(numDigits - x.numDigits + 1, 0);
		int d = x.num[x.numDigits] * BASE + x.num[x.numDigits-1];

		for (int i = q.numDigits; i > 0; i--)
		{
			int j = x.numDigits + i - 1;
			q.num[i] = int((num[j] * double(BASE) + num[j-1]) / d);
			multiAndAcumWithShift(x, -q.num[i], i-1);
			if (i == 1 || j == 1) break;
			num[j-1] += BASE * num[j];
			num[j] = 0;
		}

		fixInvariant(x.numDigits);
		return q.fixInvariant();
	}

	BigInt& operator *=(const BigInt& x) { return *this = (*this) * x; }
	BigInt operator +(const BigInt& x) { return BigInt(*this) += x; }
	BigInt operator -(const BigInt& x) { return BigInt(*this) -= x; }
	BigInt operator -() { BigInt r = 0; return r -= *this; }
	BigInt& operator /=(const BigInt& x) { return *this = div(x); }
	BigInt& operator %=(const BigInt& x) { div(x); return *this; }
	BigInt operator /(const BigInt& x) { return BigInt(*this).div(x); }
	BigInt operator %(const BigInt& x) { return BigInt(*this) %= x; }

	// I/O
	operator string() const
	{
		ostringstream s; s << num[numDigits];
		for (int i = numDigits - 1; i > 0; i--)
		{
			s.width(DIG);
			s.fill('0');
			s << abs(num[i]);
		}

		return s.str();
	}

	friend ostream& operator <<(ostream& o, const BigInt& x)
	{
		return o << (string) x;
	}

	friend istream& operator >>(istream& in, BigInt& x)
	{
		string num;
		in >> num;
		x = BigInt((char*) num.c_str());
		return in;
	}

	// potencia e raiz
	BigInt pow(int x)
	{
		if (x < 0) return (*this == 1 || *this == -1) ? pow(-x) : 0;
		BigInt r = 1;
		for (int i = 0; i < x; i++) r *= *this;
		return r;
	}

	BigInt root(int x)
	{
		if (cmp() == 0 || cmp() < 0 && x % 2 == 0) return 0;
		if (*this == 1 || x == 1) return *this;
		if (cmp() < 0) return -(-*this).root(x);
		BigInt a = 1, d = *this;
		while (d != 1)
		{
			BigInt b = a + (d /= 2);
			if (cmp(b.pow(x)) >= 0) { d += 1; a = b; }
		}

		return a;
	}
};
