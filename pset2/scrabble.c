#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int total_points(string x);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = total_points(word1);
    int score2 = total_points(word2);
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int total_points(string x)
{
    int score = 0;
    for(int i = 0, l = strlen(x); i < l; i++)
    {
        if(isupper(x[i]))
        {
            score += points[x[i] - 'A'];
        }
        else if(islower(x[i]))
        {
            score += points[x[i] - 'a'];
        }
        else
        {
            score += 0;
        }

    }
    return score;
}
