#include <iostream>
#include <map>
using namespace std;

int main ()
{
  map<char,int> mymap;
  map<char,int>::iterator it;
  pair<map<char,int>::iterator,bool> ret;

  // first insert function version (single parameter):
  mymap.insert ( pair<char,int>('a',100) );
  mymap.insert ( pair<char,int>('z',200) );

  ret=mymap.insert (pair<char,int>('z',500) );
  if (ret.second==false)
  {
    cout << "element 'z' already existed";
    cout << " with a value of " << ret.first->second << endl;
  }

  // third insert function version (range insertion):
  map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  cout << "mymap contains:\n";
  for ( it=mymap.begin() ; it != mymap.end(); it++ )
    cout << (*it).first << " => " << (*it).second << endl;

  map<char,string> mymap;
  mymap['a']="an element";
  if (mymap.count('a') > 0)
      cout << mymap['a'] << " is an element of mymap.\n";

  while (!mymap.empty())
  {
     cout << mymap.begin()->first << " => ";
     cout << mymap.begin()->second << endl;
     map<char, int>::iterator erasedelement = mymap.erase(mymap.begin());
  }

  return 0;
}
