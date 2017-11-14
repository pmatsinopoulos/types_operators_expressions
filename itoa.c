/****
 * Convert "n" to characters in "s
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


void itoa(long int n, char s[]);
void reverse(char s[]);

int main(void) {
    printf("LONG_MIN: %ld\n", LONG_MIN);

    long int n = 0;
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0;

    n = atol(input);

    printf("integer: %ld\n", n);

    char output[1000];
    memset(output, sizeof(char) * 1000, 0);

    itoa(n, output);

    printf("string: %s\n", output);

    return 0;
}

void itoa(long int n, char s[]) {
  int i;
  long int sign;
  int isLongMin = LONG_MIN == n;

  if (isLongMin) {
      n = LONG_MIN + 1;
  }

  if ((sign = n) < 0) {
      n = -n;
  }

  i = 0;

  do {
      s[i++] = n % 10L + '0';
  } while (( n /= 10L) > 0);

  if(isLongMin) {
      s[0] = s[0] + 1;
  }

  if (sign < 0) {
      s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[]) {
    int length = strlen(s);
    for(int i = 0; i < length / 2; i++) {
        char t = s[length - 1 - i];
        s[length - 1 - i] = s[i];
        s[i] = t;
    }
}
