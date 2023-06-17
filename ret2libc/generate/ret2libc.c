#include <stdio.h>
#include <stdlib.h>

void vuln() {
    char buffer[64];
    gets(buffer);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    puts("Guess my name");
    vuln();
    puts("Wrong!");

    return 0;
}
