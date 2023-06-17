#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool win1 = false;
bool win2 = false;

void func1(int arg1) {
    if (arg1 == 0xdeadbeef)
        win1 = true;
}

void func2(int arg2) {
    if (arg2 == 0xcafebabe)
        win2 = true;
}

void win(char* secret) {
    if (!(win1 && win2)) {
        return;
    }

    if (!strncmp(secret, "magicman", 8))
        system("/bin/sh");
}

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
