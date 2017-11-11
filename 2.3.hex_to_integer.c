/*************
 * Converts a hex string to its decimal equivalent.
 *
 * Note that hex string might be given with optional 0x or 0X.
 * And the program can also work in a case insensitive mode.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned char convertToDecimalDigit(char hexDigit);
unsigned long convertToDecimal(char *hexString);

int main(void)
{
    char input[1000];

    fgets(input, sizeof(input), stdin);

    printf("%ld\n", convertToDecimal(input));

    return 0;
}

unsigned long convertToDecimal(char *hexString)
{
    // TODO: copy the input string to another local string

    int length = strlen(hexString);
    if (hexString[length - 1] == '\n') {
        hexString[length - 1] = '\0';
        length = length - 1;
    }

    if (length == 1) {
        return convertToDecimalDigit(hexString[0]);
    }

    if (length == 2 && strcasecmp(hexString, "0x") == 0) {
        printf("not valid hex number\n");
        return 0;
    }

    if (strncasecmp(hexString, "0x", 2) == 0) {
        memcpy(hexString, hexString + 2, length - 2);
        hexString[length - 2] = 0;
        hexString[length - 1] = 0;
        length -= 2;
    }

    long result = 0;
    long hexPower = 1;
    for(int i = 0; i < length; i++) {
        result += convertToDecimalDigit(hexString[length - 1 - i]) * hexPower;
        hexPower *= 16;
    }
    return result;
}

unsigned char convertToDecimalDigit(char hexDigit)
{
    hexDigit = tolower(hexDigit);
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    }
    else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return 10 + hexDigit - 'a';
    }
    printf("not valid hex digit\n");
    return 0;
}
