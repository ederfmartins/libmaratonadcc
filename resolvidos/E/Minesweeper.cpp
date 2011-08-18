#include <iostream>
//#include <stdio.h>
using namespace std;

/** 10189 - Minesweeper */

int main()
{
    int map[102][102];
    int m, n, t = 1;
    char c;
    
    while (cin >> m >> n)
    {
          if (m == 0 && n == 0) break;
          else if ( t > 1) cout << endl;

          for ( int i = 1; i <= m; i++)
              for ( int j = 1; j <= n; j++)
                  map[i][j] = 0;

          for ( int i = 1; i <= m; i++)
          {
              for ( int j = 1; j <= n; j++)
              {
                  cin >> c;
                  if ( c == '*')
                  {
                    map[i+1][j-1]++; map[i+1][j]++; map[i+1][j+1]++;
                    map[i][j+1]++; map[i][j-1]++;
                    map[i-1][j-1]++; map[i-1][j]++; map[i-1][j+1]++;
                    map[i][j] = -1000;
                  }
              }
          }
          cout << "Field #" << t++ << ":" << endl;
          for ( int i = 1; i <= m; i++)
          {
              for ( int j = 1; j <= n; j++)
              {
                  if ( map[i][j] >= 0) cout << map[i][j];
                  else cout << "*";
              }
              cout << endl;
          }
     }
     //system("pause");
     return 0;   
}
