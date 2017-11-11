#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ask user to give the year
    int year;
    char yearS[5];

    fgets(yearS, sizeof yearS, stdin);

    year = atoi(yearS);

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        puts("This is a leap year");
    }
    else {
        puts("This is not a leap year");
    }

    return 0;
}
