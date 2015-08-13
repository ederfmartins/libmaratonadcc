#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        switch(s[i])
        {
            case 'A': s[i] = '2'; break;
            case 'B': s[i] = '2'; break;
            case 'C': s[i] = '2'; break;
            case 'D': s[i] = '3'; break;
            case 'E': s[i] = '3'; break;
            case 'F': s[i] = '3'; break;
            case 'G': s[i] = '4'; break;
            case 'H': s[i] = '4'; break;
            case 'I': s[i] = '4'; break;
            case 'J': s[i] = '5'; break;
            case 'K': s[i] = '5'; break;
            case 'L': s[i] = '5'; break;
            case 'M': s[i] = '6'; break;
            case 'N': s[i] = '6'; break;
            case 'O': s[i] = '6'; break;
            case 'P': s[i] = '7'; break;
            case 'Q': s[i] = '7'; break;
            case 'R': s[i] = '7'; break;
            case 'S': s[i] = '7'; break;
            case 'T': s[i] = '8'; break;
            case 'U': s[i] = '8'; break;
            case 'V': s[i] = '8'; break;
            case 'W': s[i] = '9'; break;
            case 'X': s[i] = '9'; break;
            case 'Y': s[i] = '9'; break;
            case 'Z': s[i] = '9'; break;
        }
    }
    
    cout << s << endl;
    return 0;
}