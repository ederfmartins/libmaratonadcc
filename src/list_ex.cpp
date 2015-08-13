#include <iostream>
#include <list>
using namespace std;

int main ()
{
  list<int> mylist (2,100);         // two ints with a value of 100
  mylist.push_front (200);
  mylist.push_back (300);

  it = mylist.begin();
  mylist.insert (it,10);
  mylist.insert (it,2,20); // two ints with a value of 20

  mylist.reverse(); // Reverses the order of the elements in the list.

  cout << "mylist contains:";
  for (list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    cout << " " << *it;

  cout << "Popping out the elements in mylist:";
  while (!mylist.empty())
  {
    cout << " " << mylist.front();
    mylist.pop_front();
  }

  while (!mylist.empty())
  {
    cout << " " << mylist.back();
    mylist.pop_back();
  }

  cout << mylist.size() << endl;

  return 0;
}
