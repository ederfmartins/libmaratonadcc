#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string str ("There are two needles in this haystack with needles.");
  string str2 ("needle");
  size_t found;

  // different member versions of find in the same order as above:
  found=str.find(str2);
  if (found!=string::npos)
    cout << "first 'needle' found at: " << int(found) << endl;

  found=str.find("needles are small",found+1,6);
  if (found!=string::npos)
    cout << "second 'needle' found at: " << int(found) << endl;

  found=str.find("haystack");
  if (found!=string::npos)
    cout << "'haystack' also found at: " << int(found) << endl;

  found=str.find('.');
  if (found!=string::npos)
    cout << "Period found at: " << int(found) << endl;

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  cout << str << endl;
  
  string str="We think in generalities, but we live in details.";
                             // quoting Alfred N. Whitehead
  string str2, str3;
  size_t pos;

  str2 = str.substr (12,12); // "generalities"

  pos = str.find("live");    // position of "live" in str
  str3 = str.substr (pos);   // get from "live" to the end

  cout << str2 << ' ' << str3 << endl;


  return 0;
}
/*
first 'needle' found at: 14
second 'needle' found at: 44
'haystack' also found at: 30
Period found at: 51
There are two prepositions in this haystack with needles.
generalities live in details.
*/

