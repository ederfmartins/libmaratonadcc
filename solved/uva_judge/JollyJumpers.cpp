#include <stdio.h>
#define SIZE 3000
#define abs(x) ((x) > 0 ? (x) : -(x))

int main()
{
    int n, diff, ant, atual;
    char bitSet[SIZE];
    
    while (scanf("%i", &n) == 1)
    {
          for ( int i = 0; i < n; i++) bitSet[i] = 0;
          scanf("%i", &ant);
          for ( int i = 1; i < n; i++)
          {
                 scanf("%i", &atual);
                 diff = abs(ant - atual); //printf("diff %i\n", diff);
                 bitSet[diff - 1] = 1;
                 ant = atual;
          }
          bool resp = true;
          for (int i = 0; i < n -1; i++)
          {
           if (bitSet[i] == 0) {resp = false; break;}   
          }
          if (resp) printf("Jolly\n");
          else printf("Not jolly\n");
    } 
    return 0;
}
