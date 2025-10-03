#include <stdint.h> /* Importa definiciones de enteros con tamaño exacto
                        (ej. uint16_t). Sin esto el compilador no sabe qué es uint16_t. */

#define MEMORY_MAX (1 << 16)

uint16_t memory[MEMORY_MAX]; /* 65536 posiciones */

enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* contador de programa */
    R_COND, /* registro de condiciones */
    R_COUNT, /* cantidad de registros */
};

/* Arreglo de registros */
uint16_t reg[R_COUNT];