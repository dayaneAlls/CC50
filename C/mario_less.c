#include <cs50.h>
#include <stdio.h>

int main(void)
{   //check user input
    do
    {
       int h = get_int ("Height: ");
    }
    while (h<1 || h>8);
    //prints the # according to the size specified by the user 'h'
    for (int n=0; n<h; n++)
    {
        for (int j=0; j<h; j++)
        {
            if (n + j < h - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

        }
        printf("\n");
    }

}
