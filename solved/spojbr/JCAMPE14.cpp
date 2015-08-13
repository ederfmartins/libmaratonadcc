#include <stdio.h>

using namespace std;

int main()
{
    int Cv, Ce, Cs, Fv, Fe, Fs;
    scanf("%d %d %d %d %d %d\n", &Cv, &Ce, &Cs, &Fv, &Fe, &Fs);

    if ((3*Cv + Ce) > (3*Fv+Fe)) printf("C\n");
    else if ((3*Cv + Ce) < (3*Fv+Fe)) printf("F\n");
    else {
        if (Cs > Fs) printf("C\n");
        else if (Cs < Fs) printf("F\n");
        else printf("=\n");
    }

    return 0;
}