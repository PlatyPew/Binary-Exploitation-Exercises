#include <stdio.h>
#include <string.h>
#include <unistd.h>

void readFile(char *file) {
    FILE *fp;
    char ch;

    char cwd[128];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        return;
    }

    if (!strcmp(file, "/")) {
        file = "/index.html";
    }

    strcat(cwd, file);

    if ((fp = fopen(cwd, "rb")) == NULL) {
        puts("HTTP/1.1 404 Not found\n");
        printf("%s not found\n", file);
        return;
    }

    puts("HTTP/1.1 200 OK");
    puts("Content-Type: text/html; charset=UTF-8");
    puts("Server: Http Server written in C\n");

    fseek(fp, 0L, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    for (int i = 0; i < sz; i++) {
        putchar(fgetc(fp));
    }
}

int main(int argc, char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    char buffer[256];
    gets(buffer);

    char file[64] = {0};
    sscanf(buffer, "GET %s", file);

    if (file[0] == '\0') {
        puts("HTTP/1.1 500 Internal Server Error\n");
        puts("Something went wrong");
        return 0;
    }

    readFile(file);

    return 0;
}
