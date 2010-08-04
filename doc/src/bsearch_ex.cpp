int compareMyType (const void * a, const void * b)
{
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a <  *(MyType*)b ) return -1;
}

int key = 40;
item = (int*) bsearch (&key, values, n, sizeof (int), compareMyType);

