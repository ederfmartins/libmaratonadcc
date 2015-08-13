#include <stdio.h>

/** 1387. Transmissão de Energia - dsf para achar componentes conectados*/

char estacoes[100];
char conexoes[100][100];
int E,L;

void marca(int est) {
    estacoes[est] = 1;
    int i;
    for(i=0; i<E; i++) {
        if((conexoes[est][i]==1 || conexoes[i][est]==1) && estacoes[i]==0) {
            marca(i);
        }
    }
}

int main() {
    int testcase = 1;
    while(scanf("%d %d", &E, &L) == 2) {
        if(L==0 && E==0) return 0;

        int i,j;
        for(i=0; i < E; i++) {
            estacoes[i] = 0;
            for(j=0; j < E; j++) conexoes[i][j] = 0;
        }

        for(i=0; i < L; i++) {
            int X,Y;
            scanf("%d %d", &X, &Y);
            conexoes[X-1][Y-1] = conexoes[Y-1][X-1] = 1;
        }
        marca(0);
        char ehConex = 1;
        for(i=0; i < E; i++) {
            if(estacoes[i]==0) {
                ehConex = 0;
                break;
            }
        }
        printf("Teste %d\n", testcase);
        if(ehConex) printf("normal\n");
        else printf("falha\n");
        printf("\n");
        testcase++;
    }

    return 0;
}
