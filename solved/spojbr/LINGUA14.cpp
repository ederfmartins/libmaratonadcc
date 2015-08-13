#include <iostream>
#include <string>

using namespace std;

int main()
{
    string palavra;
    while (cin >> palavra)
    {
        bool p = true;
        for (int i = 0; i < palavra.size(); i++) {
            if (!p) cout << palavra[i];
            p = !p;
        }

        cout << " ";
    }
    cout << endl;
    return 0;
}