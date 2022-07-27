#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//            A B C D E F G H I J K L M N O P  Q R S T U V W X Y  Z
int POINTS[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int computeScore(string word);

int main(void)
{
    int score1=0,score2=0;

    string word1=get_string("Player 1: "); //ex: COMPUTER
    string word2=get_string("Player 2: "); //ex: science

    score1 = computeScore(word1);
    score2 = computeScore(word2);

    if (score1==score2)
        printf("Tie!\n");
    else if (score1>score2)
        printf("Player 1 wins!\n"); //saída dos ex
    else
        printf("Player 2 wins!\n");
}

int computeScore(string word){
    int i,n,j,sum=0;
    for (i=0,n=strlen(word);i<n;i++){
        j=0;
        if (isalpha(word[i])){
            j=j+(toupper(word[i])-'A');
            sum += POINTS[j];
        }
    }
    return sum;
}
