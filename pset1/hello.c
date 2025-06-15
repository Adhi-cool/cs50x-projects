#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // promp the user for their name
    string name = get_string("What's your name? ");
    // use the format code %s to substitute name and print
    printf("Hello, %s\n", name);
}
