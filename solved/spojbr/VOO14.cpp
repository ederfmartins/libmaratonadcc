#include <stdio.h>

#define NUM_SEG_PER_HORA 60

#define UM_DIA 24 * NUM_SEG_PER_HORA
#define MEIO_DIA 12 * NUM_SEG_PER_HORA

int pos_mod(int a, int b)
{
    int m = a % b;
    if (m < 0)
    {
        m += b;
    }
    return m;
}

int main()
{
    int pa_hora, pa_min, pb_hora, pb_min;
    int cb_hora, cb_min, ca_hora, ca_min;

    scanf("%d:%d %d:%d ", &pa_hora, &pa_min, &cb_hora, &cb_min);
    scanf("%d:%d %d:%d", &pb_hora, &pb_min, &ca_hora, &ca_min);

    int pa = pa_min + NUM_SEG_PER_HORA * pa_hora;
    int pb = pb_min + NUM_SEG_PER_HORA * pb_hora;
    int ca = ca_min + NUM_SEG_PER_HORA * ca_hora;
    int cb = cb_min + NUM_SEG_PER_HORA * cb_hora;
    
    int tempo_ida = cb - pa;
    int tempo_volta = ca - pb;
    
    int tempo_real = (tempo_ida + tempo_volta)/2;
    tempo_real = pos_mod(tempo_real, MEIO_DIA);

    int fuso = pos_mod(tempo_ida - tempo_real, UM_DIA);
    if (fuso > MEIO_DIA)
    {
        fuso -= UM_DIA;
    }
    fuso /= NUM_SEG_PER_HORA;

    printf("%d %d\n", tempo_real, fuso) ;
    return 0;
}