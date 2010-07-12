#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

/** 10137 - The Trip */

int main()
{
    int n;
    double gastos[1000];
    double total;
    double menor, maior;
    
    while (1)
    {
          cin >> n;
          if ( n == 0 ) break;
          total = 0;
          
          for ( int i = 0; i < n; i++)
          {
              cin >> gastos[i];
              total += gastos[i];
          }
          total /= n;
          menor = maior = 0;
          
          for ( int i = 0; i < n; i++)
          {
              double diff = gastos[i] - total;
              
              if(diff < 0) menor -= ceil(diff * 100) / 100;
              else maior += floor(diff * 100) / 100;
          }
          
          cout << "$" << setiosflags(ios::fixed) << setprecision(2) << (menor > maior? menor : maior) << endl;
    }
    return 0;
}
