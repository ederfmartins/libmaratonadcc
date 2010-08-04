#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
  // using function as comp
  sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
  // using object as comp
  sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // if stable is need
  stable_sort (myvector.begin(), myvector.end(), myfunction);

  // Rearranges the elements in the range [first,last), in such a way that the subrange [first,middle)
  // contains the smallest elements of the entire range sorted in ascending order, and the subrange 
  // [middle,end) contains the remaining elements without any specific order.
  partial_sort (myvector.begin(), myvector.begin()+3, myvector.end());

  qsort (myints, 8, sizeof(int), compare);

  return 0;
}
