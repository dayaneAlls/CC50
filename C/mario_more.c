#include <stdio.h>
#include <cs50.h>

int main(void)
{   //check user input
    do
    {
       int h = get_int ("Height: ");
    }
    while (h<1 || h>8);
    //#prints the # according to the size specified by the user 'h'
    for (int n=0; n<h; n++)
    {
        for (int j=0; j<h; j++)
        {
            if (n + j < h - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("  ");
        for (j=h; j>0; j--)
        {
            if (j+n > h - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}
