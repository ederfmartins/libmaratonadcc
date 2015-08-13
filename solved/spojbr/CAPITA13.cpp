/*_______
|   | |
|   | |
_______
|   | |
_______

a x b 

a = x1 + x2
b = y1 + y2
x1*y1 = A1
x2*y1 = A2
x1*y2 = A3
x2*y2 = A4

y1 = A1/x1
y1 = A2/x2

y2 = A3/x1
y2 = A4/x2

A1/x1 = A2/x2 => A1*x2 = A2*x1 => A1*x2 - A2*x1 = 0
A3/x1 = A4/x2 => A3*x2 = A4*x1 => A3*x2 - A4*x1 = 0

if (A1*A4 == A2*A3) resp = N
*/

#include <stdio.h> 
#include <algorithm> 
#include <cmath> 

using namespace std; 

int main()
{
    int areas[4];

    for (int i = 0; i < 4; i++)
        scanf("%d", &areas[i]);

    sort(areas, areas+4);

    char resp = 'N';
    do
    {
        if (areas[0]*areas[3] == areas[1]*areas[2])
        {
            resp = 'S';
            break;
        }
    } while (next_permutation(areas, areas+4));

    printf("%c\n", resp);
    return 0;
}
