#include <iostream>
#include <queue>
using namespace std;

int main ()
{
  queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  myqueue.back() -= myqueue.front();

  cout << "size: " << (int) myqueue.size() << endl;

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  cout << "total: " << sum << endl;
  
  return 0;
}
