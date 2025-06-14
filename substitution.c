#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

bool duplicate(string key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    if(length != 26)
    {
        printf("Substitution key should contain 26 characters\n");
        return 1;
    }
    if(duplicate(argv[1]))
    {
        printf("Letters should not be repeated\n");
        return 1;
    }
    for(int i = 0; i < 26; i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("All the characters should be alphabets\n");
            return 1;
        }
    }
    char array[26];
    for(int i = 0; i < 26; i++)
    {
        array[i] = argv[1][i];
    }
    string plain = get_string("plaintext: ");
    int size = strlen(plain);
    printf("ciphertext: ");
    for(int i = 0; i < size; i++)
    {
        if(isupper(plain[i]))
        {
            int x = plain[i] - 'A';
            printf("%c", toupper(argv[1][x]));
        }
        else if(islower(plain[i]))
        {
            int x = plain[i] - 'a';
            printf("%c", tolower(argv[1][x]));
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
bool duplicate(string key)
{
    {
    int count[26] = {0}; // Initialize count array to zero

    for (int i = 0; i < 26; i++)
    {
        char c = tolower(key[i]);
        int index = c - 'a'; // Get index based on lowercase character
        count[index]++; // Increment count for that letter

        // If the count exceeds 1, we found a duplicate
        if (count[index] > 1)
        {
            return true; // Found a duplicate
        }
    }

    return false; // No duplicates found
}
}
