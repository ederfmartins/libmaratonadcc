#include <iostream>
#include <stdlib.h>

using namespace std;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : abs(x);
}

int main()
{
    int a, b, c, d, den, num;
    cin >> a >> b >> c >> d;
    den = b*d;
    num = (a*d + b*c);
    cout << num/gcd(num, den) << " " << den/gcd(num, den) << endl;

    return 0;
}