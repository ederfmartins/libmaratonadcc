long long axbmodc(long long a, long long b, long long c)
{
   return a ? (axbmodc(c % a, (a - b % a) % a, a) * c + b) / a : 0;
}
