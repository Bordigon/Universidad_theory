
#ifndef _EX202407_H
#define _EX202407_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tabla_s {
  int tamanno;
  char **array_tabla;
};
typedef struct tabla_s t_tabla;

FILE *argumentos_y_entrada(int argc, char **argv);

int calcular_indice_tabla(char *ele, int N);

struct tabla_s *crear_tabla_vacia(int tam);

struct tabla_s *mostrar_e_insertar_lineas(FILE *fp, struct tabla_s *ptabla);

void mostrar_tabla(struct tabla_s *ptabla);

void reiniciar_y_liberar_array_de_tabla(struct tabla_s *ptabla);

#endif


