#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int seed[10];

int main(int argc, char **argv) 
{
int i,s;
for (i=0;i<10;i++)
    seed[i] = rand();

#pragma omp parallel private(s)
{
    s = seed[omp_get_thread_num()];
    #pragma omp for
    for (i=0;i<1000;i++)
    {
        printf("%d %d %d\n",i,omp_get_thread_num(),s);
        s=(s*17931+7391); // those numbers should be choosen more carefully
    }
    seed[omp_get_thread_num()] = s;
}
return 0; 
} 
