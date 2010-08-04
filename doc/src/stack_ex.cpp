#include <iostream>
#include <stack>
using namespace std;

int main ()
{
  stack<int> mystack;
  int sum = 0;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  cout << "size: " << (int) mystack.size() << endl;

  return 0;
}
