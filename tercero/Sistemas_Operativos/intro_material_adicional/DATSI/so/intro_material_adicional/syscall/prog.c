// Programa que realiza la llamada al sistema getpid de dos formas:
// - usando la función de biblioteca que encapsula la llamada
// - utilizando una función en ensamblador creada para ello

#include <stdio.h>
#include <unistd.h>

extern int call_getpid(void); // función ensamblador creada

int main(int argc, char *argv[]) {
    printf("Mi PID es: %d\n", getpid());
    printf("Mi PID es: %d\n", call_getpid());
    return 0;
}
