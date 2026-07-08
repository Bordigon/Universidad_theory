#include <stdio.h>
#include "pgm.h"

void mostrar_datos(imagen_t *im) {
  size_t cont;

  if (im != NULL) {
    for (cont = 0; cont < (size_t) im->anchura * im->altura; cont++) {
      fprintf(stdout, "%4d", im->datos[cont]);
      if (((cont+1) % im->anchura) == 0) fprintf(stdout, "\n");
      else fprintf(stdout, " ");
    }
  }
  return ;
}
