#include "probar.h"

void ProBar()
{
    char bar[BNUM] = {0};
    char s[] = "|/-\\"; 
    int i = 0;
    while(i < 100)
    {
        bar[i++] = '#';
        printf("[%-100s][%3d%%][%c]\r", bar, i,s[i%3]);
        fflush(stdout);
        usleep(50000);
    }
    printf("\n");
    
}
