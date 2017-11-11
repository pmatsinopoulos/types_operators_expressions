/*********
 *
 * Implements the function "squeeze(s1, s2)" which
 * deletes all the characters in "s1" that match any character from the string "s2".
 *
 */
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void squeeze(char s1[], char s2[]);
int string_includes_char(char s[], char c);

int main(void)
{
    char s1[MAX_LENGTH + 1];
    char s2[MAX_LENGTH + 1];

    printf("Give the first string: \n");
    fgets(s1, sizeof(s1), stdin);
    s1[strlen(s1) - 1] = 0;

    printf("Give the second string: \n");
    fgets(s2, sizeof(s2), stdin);
    s2[strlen(s2) - 1] = 0;

    printf("First string is: %s, Second string is: %s\n", s1, s2);

    squeeze(s1, s2);

    printf("Now first string is: %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    j = 0;
    for(i = 0; s1[i] != 0; i++)
    {
        if(!string_includes_char(s2, s1[i])) {
            s1[j] = s1[i];
            j++;
        }
    }
    s1[j] = 0;
}

int string_includes_char(char s[], char c)
{
    for(int i = 0; s[i] != 0; i++) {
        if(s[i] == c) {
            return 1;
        }
    }
    return 0;
}
