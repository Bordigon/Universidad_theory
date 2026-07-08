#include "pgm.h"

int main(int argc, char **argv) {
  
  if (argc == 2) {
    return (comprobar_pgm_P2(argv[1]));
  }
  else return 1;
}
