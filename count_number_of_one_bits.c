/****************
 * Counts the number of 1 bits in an integer argument.
 *
 * For 0, it returns 0,
 * For 1, it returns 1,
 * For 2, it returns 1,
 * For 3, it returns 2,
 * For 4, it returns 1,
 * For 5, it returns 2 e.t.c.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countBitsOfOne(unsigned integer);

int main(void) {
    printf("Give me an integer and I will tell you how many bits of 1 it includes: ");
    char input[1000];
    int integer;

    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0;
    integer = atoi(input);

    printf("Number of One Bits: %d\n", countBitsOfOne(integer));

    return 0;
}

int countBitsOfOne(unsigned integer) {
    int result = 0;
    while(integer != 0) {
        if((integer & 01) == 01) {
            result++;
        }
        integer >>= 1;
    }
    return result;
}
