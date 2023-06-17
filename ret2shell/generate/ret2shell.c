#include <stdio.h>
#include <stdlib.h>

void vuln() {
    char buffer[256];
    gets(buffer);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    puts("Guess my name");
    vuln("\xff\xe4");
    puts("Wrong!");

    return 0;
}
