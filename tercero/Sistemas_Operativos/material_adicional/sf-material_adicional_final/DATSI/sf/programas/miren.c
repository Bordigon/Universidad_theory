#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc!=3) {
        fprintf(stderr, "Uso: %s nombre_previo nombre_nuevo\n", argv[0]);
        return 1;
    }
    if (rename(argv[1], argv[2]) < 0) {
        perror("rename"); return 1;
    }
    return 0;
}
