#include <stdio.h>
#include <cs50.h>

int main()
{
    int cent1=0,cent2=0,cent3=0,cent4=0, cash2=0, total=0;
    //ask and check the input
    do{
      float cash = get_float("Change owed: ");
    }while (cash <= 0);
    //calculations to return minimum coin possibilities
    cash2 = cash*100;
    cent1 = cash2/25;
    cent2 = (cash2 - cent1*25)/10;
    cent3 = (cash2 - cent1*25 - cent2*10)/5;
    cent4 = (cash2 - cent1*25 - cent2*10 - cent3*5);
    total = (cent1 + cent2 + cent3 + cent4);

    printf("%d",total):
}
