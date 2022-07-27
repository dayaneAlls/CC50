#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string ch={"! ,"".';?"};
    int countchar=0,countspace=1,countsentence=0, grade;
    float L,S,qtdletters,words;
    //check input
    string text= get_string("Text: ");
    int sizechar=strlen(text);
    //counts all the letters in the text
    for (int i=0;i<sizechar;i++){
        for (int j=0;j<strlen(ch);j++){
            if (text[i]==ch[j])
                countchar++;
       }
    }
    //counts all the words in the text
    for (int i=0;i<sizechar;i++){
       if (text[i]==' ')
          countspace++;
    }
    //counts all the sentences in the text
    for (int i=0;i<sizechar;i++){
       if (text[i]=='.' || text[i]=='!' || text[i]=='?')
          countsentence++;
    }

    words=countspace;
    qtdletters = sizechar-countchar;
    //calculates the school level according to the Coleman-Liau formula
    L=(qtdletters/words)*100;
    S=(countsentence/words)*100;
    grade = (0.0588 * L) - (0.296 * S) - 15.8;
    //print grade
    if (grade >=16)
       printf("Grade 16+.\n");
    else if (grade < 1)
        printf("Before grade 1.\n");
    else
        printf("Grade: %d \n",grade);
}
