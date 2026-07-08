#define TAMANNO_LINEA_MAX 10000

typedef unsigned int dato_t;
typedef unsigned int *datos_t; /* typedef dato_t *datos_t; */
typedef struct imagen_s {
  char identificador[3];
  dato_t anchura, altura;
  dato_t valor_maximo;
  datos_t datos;
} imagen_t;

int comprobar_pgm_P2(char *nfichero);
void crear_pgm_P2(void);
void mostrar_datos(imagen_t *im);
imagen_t *crear_imagen_rango(char *identificador, dato_t anchura, dato_t altura, dato_t valor_maximo);
void liberar_datos(imagen_t *im);
