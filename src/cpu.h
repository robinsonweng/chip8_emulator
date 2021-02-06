#ifndef __CPU
# define __CPU

#include <stdlib.h>

// chip8
#define MAX_RAM_SIZE 4096
#define PROGRAM_START_RAM_LOACATION 0x200
#define MAX_GENERAL_REGISTER 16
#define MAX_STACK_LEVEL 16
// screen
// The original implementation of the Chip-8 language used a 64x32-pixel monochrome display
#define WINDOW_HIGHT 32
#define WINDOW_WIDTH 64

typedef unsigned char uint8_t;
typedef unsigned short ushort;
typedef struct _CPU CPU;
typedef int (*CPUfptr)(CPU *);

typedef struct _CPU {
    // normal registers
    uint8_t V[MAX_GENERAL_REGISTER];
    ushort I;
    // special registers
    uint8_t delay;
    uint8_t sound_timer;
    ushort PC; // program counter
    
    uint8_t SP; // stack pointer
    ushort stack[MAX_STACK_LEVEL]; // stack

    uint8_t ram[MAX_RAM_SIZE]; // ramdom acess memory
    uint8_t vram[WINDOW_HIGHT][WINDOW_WIDTH]; // ram for screen

    /*
    applying method to the struct by fptr
    */
   CPUfptr LoadRom, ResetCpu;

} CPU;

int new_cpu(CPU **self);


#endif // __CPU