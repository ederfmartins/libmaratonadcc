#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX_EVENTS 64800

struct Event
{
    int seconds;
    int value;
};

int cmp_event(const void* e1, const void* e2)
{
    Event* ee1 = (Event*) e1;
    Event* ee2 = (Event*) e2;
    if (ee1->seconds == ee2->seconds) return 0;
    else if (ee1->seconds < ee2->seconds) return -1;
    else return 1;
}

int main()
{
    int t;
    int h, m, s;
    char flag;
    Event events[MAX_EVENTS];

    while (1)
    {
        int num_e = 0;
        int num_s = 0;
        int max_entradas = 0;
        scanf("%d\n", &t);

        if (t == 0) break;

        for (int i = 0; i < t; i++) {
            scanf("%d:%d:%d %c\n", &h, &m, &s, &flag);
            events[i].seconds = s + 60*m + 3600*h;
            if (flag == '?') {
                events[i].value = 0;
            }
            else if (flag == 'E') {
                events[i].value = 1;
                num_e++;
            }
            else {
                events[i].value = -1;
                num_s++;
            }
        }

        // Sort the events in ascending ocurring order
        qsort(events, t, sizeof(Event), cmp_event);

        // Find the maximal number of ? that can be used as entrada.
        int num_x = t - (num_s + num_e);
        if (num_e > num_s)
            max_entradas = (num_x - (num_e - num_s)) / 2;
        else
            max_entradas = num_s - num_e + (num_x - (num_s - num_e)) / 2;

        // Transform ? into entrada or saida
        for (int i = 0; i < t; i++) {
            if (events[i].value == 0) {
                if (max_entradas > 0) events[i].value = 1;
                else events[i].value = -1;
                max_entradas--;
            }
        }

        // max sum
        int max_sum = 0;
        int curr_sum = 0;

        for (int i = 0; i < t; i++) {
            curr_sum += events[i].value;
            if (curr_sum < 0) curr_sum = 0;
            if (curr_sum > max_sum) max_sum = curr_sum;
        }

        printf("%d\n", max_sum);

    }
    return 0;
}