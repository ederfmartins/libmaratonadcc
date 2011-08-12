int mpow(int a, int b, int n = 10)
{
  if(b == 0)
    return 1;
  else {
    long long res = mpow(a, b/2, n);
    res = (res*res) % n;
    if(b%2 == 1)
      res = (res*a) % n;
    return (int) res;
  }
}
