#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letter(string text);
int count_word(string text);
int count_sentences(string text);
string grade[] = {"before grade 1","Grade 1", "Grade 2", "Grade 3", "Grade 4", "Grade 5", "Grade 6", "Grade 7", "Grade 8",
"Grade 9", "Grade 10", "Grade 11", "Grade 12", "Grade 13", "Grade 14", "Grade 15"};

int main(void)
{
    string text = get_string("Text: ");
    int x = count_letter(text);
    int y = count_word(text);
    int z = count_sentences(text);
    float L = ((float)x/y)*100;
    float S = ((float)z/y)*100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int ind = (int)round(index);
    if(ind >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(ind < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("%s\n", grade[ind]);
    }
}
int count_letter(string text)
{
    int letter = 0;
    int length = strlen(text);
    for(int i = 0; i < length; i++ )
    {
        if(isalpha(text[i]))
        {
            letter++;
        }
        else
        {
            letter += 0;
        }

    }
    return letter;
}
int count_word(string text)
{
    int word = 0;
    int length = strlen(text);
    for(int i = 0; i < length; i++)
    {
        if(isblank(text[i]))
        {
            word++;
        }
        else
        {
            word+=0;
        }
    }
    word+=1;
    return word;
}
int count_sentences(string text)
{
    int sent = 0;
    int length = strlen(text);
    for(int i = 0; i < length; i++)
    {
        if(text[i] == '.'|| text[i] == '!'|| text[i] == '?')
        {
            sent++;
        }
    }
    return sent;
}
