#include <iostream>

using namespace std;

/** 706 - LCD Display */

void print(char c, int n)
{
     for (int i = 0; i < n; i++)
         cout << c;     
}

int main()
{
    int n;
    string digits;
    //                 0         1      2     3      4       5     6      7     8     9
    bool top[10]    = {true,  false, true,  true,  false, true,  true,  true,  true, true};
    bool down[10]   = {true,  false, true,  true,  false, true,  true,  false, true, true};
    bool middle[10] = {false, false, true,  true,  true,  true,  true,  false, true, true};
    bool left1[10]  = {true,  false, false, false, true,  true,  true,  false, true, true};
    bool left2[10]  = {true,  false, true,  false, false, false, true,  false, true, false};
    bool rigth1[10] = {true,  true,  true,  true,  true,  false, false, true,  true, true};
    bool rigth2[10] = {true,  true,  false, true,  true,  true,  true,  true,  true, true};
    
    while(1)
    {
          cin >> n >> digits;
          if (n == 0) break;

          for (int i = 0; i < digits.size(); i++)
          {
              char c = top[ digits[i] - '0']? '-': ' ';
              print(' ', 1); print(c, n);  print(' ', 1);
              if (i != digits.size() - 1) print(' ', 1);
              else cout << endl;
          }
          for (int j = 0; j < n; j++)
          {
              for (int i = 0; i < digits.size(); i++)
              {
                  char c = left1[ digits[i] - '0']? '|': ' ';
                  char c1 = rigth1[ digits[i] - '0']? '|': ' ';
                  print(c, 1); print(' ', n); print(c1, 1);
                  if (i != digits.size() - 1) print(' ', 1);
                  else cout << endl;
              }
          }
          for (int i = 0; i < digits.size(); i++)
          {
              char c = middle[ digits[i] - '0']? '-': ' ';
              print(' ', 1); print(c, n);  print(' ', 1);
              if (i != digits.size() - 1) print(' ', 1);
              else cout << endl;
          }
          for (int j = 0; j < n; j++)
          {
              for (int i = 0; i < digits.size(); i++)
              {
                  char c = left2[ digits[i] - '0']? '|': ' ';
                  char c1 = rigth2[ digits[i] - '0']? '|': ' ';
                  print(c, 1); print(' ', n); print(c1, 1);
                  if (i != digits.size() - 1) print(' ', 1);
                  else cout << endl;
              }
          }
          for (int i = 0; i < digits.size(); i++)
          {
              char c = down[ digits[i] - '0']? '-': ' ';
              print(' ', 1); print(c, n);  print(' ', 1);
              if (i != digits.size() - 1) print(' ', 1);
              else cout << endl;
          }
          cout << endl;
    }
    return 0;   
}
