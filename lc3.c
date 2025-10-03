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

enum
{
    OP_BR = 0, /* salto condicional (branch) */
    OP_ADD, /* suma */
    OP_LD, /* cargar (load) */
    OP_ST, /* almacenar (store) */
    OP_JSR, /* salto a registro (jump register) */
    OP_AND, /* AND a nivel de bits */
    OP_LDR, /* cargar desde registro (load register) */
    OP_STR, /* almacenar en registro (store register) */
    OP_RTI, /* instrucción de retorno de interrupción (unused) */
    OP_NOT, /* NOT a nivel de bits */
    OP_LDI, /* carga indirecta (load indirect)*/
    OP_STI, /* almacenamiento indirecto (store indirect) */
    OP_JMP, /* salto (jump)*/
    OP_RES, /* reservado (unused) */
    OP_LEA, /* cargar dirección efectiva (load effective address) */
    OP_TRAP, /* llamada a sistema (trap) */
};

enum
{
    FL_POS = 1 << 0, /* P: positivo */
    FL_ZRO = 1 << 1, /* Z: cero */
    FL_NEG = 1 << 2, /* N: negativo */
};

int main (int argc, const char* argv[])
{
    /* Cargar argumentos */
    /* Configuración inicial */

    /* Como exactamente un flag de condición debe estar activo en cada momento,
        inicializamos el flag Z (cero) */
    reg[R_COND] = FL_ZRO;

    /* Establecer el PC en la posición incial */
    /* 0x3000 es la posición de inicio por defecto en LC-3 */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        /* FETCH: obtener instrucción */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12; // obtenemos el opcode

        switch (op)
        {
            case OP_ADD:
                /* ejecutar ADD */
                break;
            case OP_AND:
                /* ejecutar AND */
                break;
            case OP_NOT:
                /* ejecutar NOT */
                break;
            case OP_BR:
                /* ejecutar salto condicional (BR) */
                break;
            case OP_JMP:
                /* ejecutar salto (JMP) */
                break;
            case OP_JSR:
                /* ejecutar salto a subrutina (JSR) */
                break;
            case OP_LD:
                /* ejecutar load (LD) */
                break;
            case OP_LDI:
                /* ejecutar load indirect (LDI) */
                break;
            case OP_LDR:
                /* ejecutar load register (LDR) */
                break;
            case OP_LEA:
                /* ejecutar load effective address (LEA) */
                break;
            case OP_ST:
                /* ejecutar store (ST) */
                break;
            case OP_STI:
                /* ejecutar store indirect (STI) */
                break;
            case OP_STR:
                /* ejecutar store register (STR) */
                break;
            case OP_TRAP:
                /* ejecutar llamada al sistema (TRAP) */
                break;
            case OP_RES:   // reservado
            case OP_RTI:   // retorno de interrupción
            default:
                /* BAD OPCODE → código inválido */
                break;
        }
    }
    /* Apagar o terminar */
}