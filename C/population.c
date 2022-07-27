#include <stdio.h>
#include <cs50.h>

int main()
{
    int n=0,startsize,endsize;

    do{
        startsize=get_int("Start size: ");
    }while (startsize < 9);

    do{
        endsize=get_int("End size: ");
    }while (endsize < 9 || endsize < startsize);

    while (startsize < endsize){
        startsize += (startsize/3)-(startsize/4);
        n++;
    }
    printf("Years: %d\n",n);
}
