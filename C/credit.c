#include <stdio.h>
#include <cs50.h>

int main()
{   //define variables
    int digit1=0, digit2=0, sum=0, total, cod, i;
    //check input
    long int num = get_long ("Number: ");

    cod = num/100000000000000;
    //calculates card digits according to Luhn's algorithm
    while (num > 0){
       digit1 += num %10;
       digit2 = ((num /10)%10)*2;
       sum += (digit2/10 + digit2%10);
       num = (num /10)/10;
    }
    total = (digit1+sum)%10;
    //check if it is valid and print result
    if (total == 0 && (cod == 34 || cod == 37))
        printf("AMEX\n");
    else if (total == 0 && cod >= 51 && cod <= 55)
        printf("MASTERCARD\n");
    else if (total == 0 && cod/10 == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");
}
