#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    char c;
    string palavra;
    int np = 0, f=0;

    cin >> c;
    while (cin >> palavra) {
        np++;
        for (int i = 0; i < palavra.size(); i++) {
            if (palavra[i] == c) {
                f++;
                break;
            }
        }
    }

    std::cout << fixed << setprecision(1) << 100*((double)f)/np << endl;
    return 0;
}