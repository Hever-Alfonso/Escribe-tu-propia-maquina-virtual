#include <stdio.h>    /* printf, exit */
#include <stdlib.h>   /* funciones de sistema (exit, etc.) */
#include <stdint.h>   /* enteros de tamaño fijo, ej. uint16_t */

/* Memoria */
#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX]; /* 65536 posiciones */

/* Registros */
enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,   /* contador de programa */
    R_COND, /* registro de condiciones */
    R_COUNT /* cantidad de registros */
};

/* Arreglo de registros */
uint16_t reg[R_COUNT];

/* Códigos de operación (opcodes) */
enum
{
    OP_BR = 0,  /* salto condicional (branch) */
    OP_ADD,     /* suma */
    OP_LD,      /* cargar (load) */
    OP_ST,      /* almacenar (store) */
    OP_JSR,     /* salto a subrutina */
    OP_AND,     /* AND */
    OP_LDR,     /* cargar desde registro */
    OP_STR,     /* almacenar en registro */
    OP_RTI,     /* retorno interrupción (no usado) */
    OP_NOT,     /* NOT */
    OP_LDI,     /* carga indirecta */
    OP_STI,     /* almacenamiento indirecto */
    OP_JMP,     /* salto */
    OP_RES,     /* reservado */
    OP_LEA,     /* cargar dirección efectiva */
    OP_TRAP     /* llamada a sistema */
};

/* Flags de condición */
enum
{
    FL_POS = 1 << 0, /* P: positivo */
    FL_ZRO = 1 << 1, /* Z: cero */
    FL_NEG = 1 << 2  /* N: negativo */
};

/* Prototipos */
int read_image(const char *path);     /* cargar imagen en memoria */
uint16_t mem_read(uint16_t address);  /* leer palabra de 16 bits */

int main (int argc, const char* argv[])
{
    /* Cargar argumentos desde la terminal */
    if (argc < 2) {
        printf("Uso: lc3 [imagen1] [imagen2] ...\n");
        exit(2);
    }
    for (int j = 1; j < argc; ++j) {
        if (!read_image(argv[j])) {
            printf("No se pudo cargar: %s\n", argv[j]);
            exit(1);
        }
    }

    /* Configuración inicial */

    /* Como solo un flag debe estar activo a la vez,
       iniciamos con Z (cero) */
    reg[R_COND] = FL_ZRO;

    /* Establecer el PC en la posición inicial */
    /* 0x3000 es la posición por defecto en LC-3 */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        /* FETCH: obtener instrucción */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12; /* obtenemos el opcode */

        switch (op)
        {
            case OP_ADD: /* ejecutar ADD */ break;
            case OP_AND: /* ejecutar AND */ break;
            case OP_NOT: /* ejecutar NOT */ break;
            case OP_BR:  /* ejecutar BR */ break;
            case OP_JMP: /* ejecutar JMP */ break;
            case OP_JSR: /* ejecutar JSR */ break;
            case OP_LD:  /* ejecutar LD */ break;
            case OP_LDI: /* ejecutar LDI */ break;
            case OP_LDR: /* ejecutar LDR */ break;
            case OP_LEA: /* ejecutar LEA */ break;
            case OP_ST:  /* ejecutar ST */ break;
            case OP_STI: /* ejecutar STI */ break;
            case OP_STR: /* ejecutar STR */ break;
            case OP_TRAP:/* ejecutar TRAP */ break;
            case OP_RES: /* reservado */ break;
            case OP_RTI: /* no usado */ break;
            default:     /* opcode inválido */ break;
        }
    }

    /* Terminar */
    return 0;
}