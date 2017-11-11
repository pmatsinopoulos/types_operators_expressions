/******************
 * Function "any(s1,s2)" returns the first location in the string s1 in which
 * any character from s2 occurs. Otherwise, it returns -1.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int any(const char s1[], const char s2[]);
int findCharPositionInString(const char s1[], char c);

int main(void) {
    char s1[MAX_LENGTH + 1];
    char s2[MAX_LENGTH + 1];

    printf("Give me first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strlen(s1) - 1] = 0;

    printf("Give me second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strlen(s2) - 1] = 0;

    int position = any(s1, s2);
    if(position >= 0) {
        printf("Found at position: %d\n", position);
    }
    else {
        puts("Not Found!");
    }
    return 0;
}

int any(const char s1[], const char s2[]) {
    for(int i = 0; s2[i] != 0; i++) {
        int position = findCharPositionInString(s1, s2[i]);
        if(position >= 0) {
            return position;
        }
    }
    return -1;
}

int findCharPositionInString(const char s[], char c) {
    for(int i = 0; s[i] != 0; i++) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}
