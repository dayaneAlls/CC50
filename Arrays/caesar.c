#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc,string argv[])
{
    if (argc !=2){
        printf("Usage ./caesar key \n");
        return 1;
    }
    for(int i=0;i<strlen(argv[1]);i++){
        if (!isdigit(argv[1][i])){
            printf("Usage ./caesar key \n");
            return 1;}
    }
    int k=atoi(argv[1]);
    if (k<=0){
        printf("Usage ./caesar key \n");
        return 1;
    }
    string p=get_string(" Plaintext: ");

    for (int i=0;i<strlen(p);i++){
        if (isalpha(p[i]) && isupper(p[i]))
            p[i]=(p[i]-'A'+k)%26 +'A';
        else if (isalpha(p[i]) && islower(p[i]))
            p[i]=(p[i]-'a'+k)%26 +'a';
    }
    printf("Ciphertext: %s\n\n",p);
    return 0;
}
