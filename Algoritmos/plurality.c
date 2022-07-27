#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAX 9

typedef struct{
    string names;
    int votes;
}candidate;

bool vote(string name);
void printWinner(void);
candidate candidates[MAX];
int candidateCount=0;

int main(int argc,string argv[])
{
    candidateCount=argc-1;
    if (argc<2){
        printf("Minimum 2 candidates\n");
        return 1;}
    if(candidateCount>MAX){
        printf("Maximum number of candidates must be 9!\n");
        return 1;}
    for (int i=0;i<candidateCount;i++){
        candidates[i].names=argv[i+1];
        candidates[i].votes = 0;
    }

    int voters=get_int("Number of voters: ");
    for (int j=0;j<voters;j++){
        string name=get_string("Vote: ");
        vote(name)==true?:printf("Invalid vote.\n");
    }
    printWinner();
}

bool vote(string name){
    for (int i=0;i<candidateCount;i++){
        if (strcmp(candidates[i].names,name)==0){
            candidates[i].votes++;
            return true;}
    }
    return false;
}
void printWinner(void){
    int greater=0;
    for (int i=0;i<candidateCount;i++){
        if (candidates[i].votes >= greater)
            greater = candidates[i].votes;
    }
    for (int i=0;i<candidateCount;i++){
        if (candidates[i].votes == greater)
            printf("%s\n",candidates[i].names);
    }
}
