#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    const char* p = "10 200000000000000000000000000000 30 -40 - 42";
    printf("Parsing '%s':\n", p);
    char* end = NULL;

    for (unsigned long i = strtoul(p, &end, 10);
        p != end;
        i = strtoul(p, &end, 10)) 
    {
        printf("'%.*s' -> ", (int)(end - p), p);
        p = end;

        if (errno == ERANGE) {
            errno = 0;
            printf("range error, got ");
        }

        printf("%lu\n", i);
    }

    printf("After the loop p points to '%s'\n", p);

    _getch();
    return 0;
}