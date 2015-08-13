#include <iostream>
#include <set>
using namespace std;

int main ()
{
  multiset<int> mymultiset;
  multiset<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) mymultiset.insert(i*10);   // 10 20 30 40 50

  cout << "size: " << (int) mymultiset.size() << endl;
  cout << "count: " << (int) mymultiset.count(10) << endl;

  it=mymultiset.find(20);
  mymultiset.erase (it);

  if (! mymultiset.empty)
	mymultiset.erase (mymultiset.find(40));

  for (it=mymultiset.begin(); it!=mymultiset.end(); it++)
    cout << " " << *it;

  int myints[]={19,72,4,36,20,20};
  multiset<int> first (myints,myints+3);     // 4,19,72
  multiset<int> second (myints+3,myints+6);  // 20,20,36

  first.swap(second); // troca conteudo. o primeiro fica [20,20,36] e o segundo [4,19,72]

  return 0;
}
