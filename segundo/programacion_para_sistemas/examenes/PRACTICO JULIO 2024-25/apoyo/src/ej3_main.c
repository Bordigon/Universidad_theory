#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

int main(void) {
  imagen_t *im;
  char *id_version = "P2";

  im = crear_imagen_rango(id_version, 3, 2, 255);
  fprintf(stdout, "Llamando a mostrar_datos(im)...\n");
  mostrar_datos(im);
  liberar_datos(im);
  free(im);
  return 0;
}


