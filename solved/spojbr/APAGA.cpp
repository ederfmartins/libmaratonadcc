#include <stdio.h>
#include <list>

using namespace std;

void apaga(list<char>& digits, list<char>::iterator& it)
{
    if (it != digits.begin())
    {
        it--;
        list<char>::iterator ant = it;
        it++;
        digits.erase(it);
        it = ant;
    }
    else
    {
        digits.erase(it);
        it = digits.begin();
    }
}

int main()
{
    int n, d;
    char numero;

    while (scanf("%i %i\n", &n, &d) == 2)
    {
        if (n == 0 && d == 0) break;

        list<char> digits;

        for(int i = 0; i < n; i++)
        {
            scanf("%c", &numero);
            digits.push_back(numero);
        }

        list<char>::iterator it = digits.begin();
        //digits[len(digits)-1] não possui sucessor válido
        list<char>::iterator fim = --digits.end();
        while (it != fim)
        {
            if (d == 0) break;
            char atual = (*it);

            it++;
            char prox = (*it);
            it--;

            if(atual < prox)
            {
                apaga(digits, it);
                d--;
            }
            else it++;
            
        }
        
        it = digits.end();
        it--;
        while (it != digits.begin())
        {
            if (d > 0) break;
            char atual = (*it);
            
            it--;
            char antecessor = (*it);
            it++;

            if(antecessor >= atual)
            {
                apaga(digits, it);
                d--;
            }
            else it++;
        }

        for(it = digits.begin(); it != digits.end(); it++) printf("%c", *it);
        printf("\n");
    }
    return 0;
}

