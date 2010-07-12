#include <iostream>
#include <string>
#include <map>
using namespace std;

/** 10082 - WERTYU */

int main()
{
    map<char, char> keyMap;
    keyMap['A'] = '#';
    keyMap['B'] = 'V';
    keyMap['C'] = 'X';
    keyMap['D'] = 'S';
    keyMap['E'] = 'W';
    keyMap['F'] = 'D';
    keyMap['G'] = 'F';
    keyMap['H'] = 'G';
    keyMap['I'] = 'U';
    keyMap['J'] = 'H';
    keyMap['K'] = 'J';
    keyMap['L'] = 'K';
    keyMap['M'] = 'N';
    keyMap['N'] = 'B';
    keyMap['O'] = 'I';
    keyMap['P'] = 'O';
    keyMap['Q'] = '#';
    keyMap['R'] = 'E';
    keyMap['S'] = 'A';
    keyMap['T'] = 'R';
    keyMap['U'] = 'Y';
    keyMap['V'] = 'C';
    keyMap['X'] = 'Z';
    keyMap['Y'] = 'T';
    keyMap['W'] = 'Q';
    keyMap['Z'] = '#';
    
    keyMap['0'] = '9';
    keyMap['1'] = '`';    
    keyMap['2'] = '1';    
    keyMap['3'] = '2'; 
    keyMap['4'] = '3'; 
    keyMap['5'] = '4'; 
    keyMap['6'] = '5'; 
    keyMap['7'] = '6'; 
    keyMap['8'] = '7'; 
    keyMap['9'] = '8';
    
    keyMap['='] = '-';
    keyMap['-'] = '0';
    
    keyMap['['] = 'P';
    keyMap[']'] = '[';
    keyMap['\\'] = ']';
    
    keyMap[';'] = 'L';
    keyMap['\''] = ';';
    
    keyMap[','] = 'M';
    keyMap['.'] = ',';
    keyMap['/'] = '.';
    keyMap[' '] = ' ';
    
    string linha;
    while (getline(cin, linha))
    {
     for(int i = 0; i < linha.length(); i++)
     {
      cout << keyMap[linha[i]];
     }
     cout << endl;
    }
    return 0;   
}
