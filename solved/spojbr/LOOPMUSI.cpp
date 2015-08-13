#include <iostream>
using namespace std;

int main()
{
    int n;
    int valores[10000];

    while (cin >> n)
    {
        int loops = 0;
        if (n == 0) break;

        for (int i = 0; i < n; i++)
        {
            cin >> valores[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (valores[(i-1 + n)%n] < valores[i] && valores[(i+1 + n)%n] < valores[i]) loops++;
            else if (valores[(i-1 + n)%n] > valores[i] && valores[(i+1 + n)%n] > valores[i]) loops++;
        }

        cout << loops << endl;
    }
    return 0;
}