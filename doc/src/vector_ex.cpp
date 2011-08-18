#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  vector<int> myvector (3,100); // (100 100 100)
  vector<int>::iterator it;

  myvector.reserve(100);

  for (int i=0; i<myvector.size(); i++)
    myvector.at(i)=i; // = myvector[i] = i

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  myvector.insert (it,2,300);

  vector<int> anothervector (2,400);
  int myarray [] = { 501,502,503 };
  vector<int> initializer(myarray/*PointerInicio*/, myarray+sizeof(myarray)/sizeof(int)/*PointerFim*/);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());
  myvector.insert (myvector.begin(), myarray, myarray+3);

  cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    cout << " " << *it;
  cout << endl;

  // erase the 6th element
  myvector.erase (myvector.begin()+5);
  int sum;
  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  return 0;
}
