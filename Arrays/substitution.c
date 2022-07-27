#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc,string argv[])
{
    string key=argv[1]; //ex: JTREKYAVOGDXPSNCUIZLFBMWHQ
    int j;
    if (argc!=2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(key)<26){
        printf("The key must contain 26 characters\n");
        return 1;
    }
    for (int i=0;i<strlen(key);i++){
        if (isdigit(key[i])){
            printf("The key must only contain alphabetic characters\n");
            return 1;}
        for (int n=i+1;n<26;n++){
            if (toupper(key[n])==toupper(argv[1][i])){
                printf("The key must not contain repeated characters\n");
                return 1;}
        }
    }

    string text=get_string("Simple text: "); //ex: HELLO
    for (int i=0;i<strlen(text);i++){
        j=0;
        if (isalpha(text[i]) && isupper(text[i])){
            j=j+(text[i]-'A');
            text[i]= toupper(key[j]);}
        else if (isalpha(text[i]) && islower(text[i])){
            j=j+(text[i]-'a');
            text[i]= tolower(key[j]);}
    }
    printf("Cipher text: %s\n",text); //ex: VKXXN
    return 0;
}
