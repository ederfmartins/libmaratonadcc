#include <iostream>
#include <inttypes.h>

using namespace std;

#define TAM 101

int main()
{
    int l;
    uint64_t cnt = 1;
    cin >> l;

    while (l >= 2)
    {
        cnt *= 4;
        l /= 2;
    }

    cout << cnt << endl;

    return 0;
}