// #include <stdio.h>
// #include <set>
// 
// using namespace std;
// set<int> pode_somar;
// 
// int main()
// {
//     int v_desejado, m, moeda;
// 
//     scanf("%d %d", &v_desejado, &m);
//     pode_somar.insert(0);
// 
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d", &moeda);
//         set<int> novas_somas;
// 
//         for (set<int>::iterator it = pode_somar.begin(); it != pode_somar.end(); it++)
//         {
//             if (*it + moeda <= v_desejado)
//                 novas_somas.insert(*it + moeda);
//         }
// 
//         pode_somar.insert(novas_somas.begin(), novas_somas.end());
//         if (pode_somar.count(v_desejado)) break;
//     }
// 
//     if (pode_somar.count(v_desejado)) printf("S\n");
//     else printf("N\n");
// 
//     return 0;
// }

#include <stdio.h>

#define TAM 100001
bool somas_possiveis[TAM];

int main()
{
    int v_desejado, m, moeda;

    scanf("%d %d", &v_desejado, &m);
    //escolhendo 0 moedas sempre é possível somar 0.
    somas_possiveis[0] = true;
    for (int i = 1; i <= v_desejado; i++) somas_possiveis[i] = false;

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &moeda);
        
        // somas_possiveis[v-moeda] foi somado sem a moeda atual. Se é possível
        // somar isso sem ela é possível somar somas_possiveis[v] usando a moeda
        // atual.
        for (int v = v_desejado; v >= moeda; v--)
        {
            if (somas_possiveis[v-moeda]) somas_possiveis[v] = true;
        }
    }

    if (somas_possiveis[v_desejado]) printf("S\n");
    else printf("N\n");

    return 0;
}