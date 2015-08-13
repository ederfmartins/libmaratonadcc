#include <stdio.h>
#include <ctype.h>
#include <queue>

/** 2841. Bolsa de Valores - ad hoc com filas de prioridade pass facil*/

using namespace std;

int main() {
    int n;

    while(scanf("%d", &n) == 1) {
        if(n==0) return 0;
        double lucroEspertinhos = 0.0;
        priority_queue<float> compras;
        priority_queue<float> vendas;

        while(n>0) {
            char ttmp;
            float vtmp;
            scanf("\n%c %f", &ttmp, &vtmp);

            if(tolower(ttmp)=='c') { // compra
                if(!vendas.empty()) {
                    float diferenca = vtmp + vendas.top();
                    //printf("Compra %f, dif: %f\n", vtmp, diferenca);
                    if(diferenca >= 0.0) {
                        lucroEspertinhos += diferenca;
                        vendas.pop();
                    } else {
                        compras.push(vtmp);
                    }
                } else {
                    compras.push(vtmp);
                }
            } else { // venda
                if(!compras.empty()) {
                    float diferenca = compras.top() - vtmp;
                    //printf("Venda %f, dif: %f\n", vtmp, diferenca);
                    if(diferenca >= 0.0) {
                        lucroEspertinhos += diferenca;
                        compras.pop();
                    } else {
                        vendas.push(-vtmp);
                    }
                } else {
                    vendas.push(-vtmp);
                }
            }
            n--;
        }
        printf("%.2f\n", lucroEspertinhos);
    }
    return 0;
}
