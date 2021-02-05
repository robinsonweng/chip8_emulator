#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"


/*
    OOP stype C code
    refer: https://hackmd.io/@sysprog/c-oop?type=view
    & https://www.codeproject.com/Articles/108830/Inheritance-and-Polymorphism-in-C
*/
int new_cpu(CPU **self){ // constructor
    if (NULL == (*self = malloc(sizeof(CPU)))) return -1; // return if pointer is NULL
    // init everything
    (*self)->I = 0;
    (*self)->delay = 0;
    (*self)->sound_timer = 0;
    (*self)->PC = 0;
    (*self)->SP = 0;

    // registers
    for (int i=0;i<= MAX_GENERAL_REGISTER;i++)
        (*self)->V[i] = 0;
    
    for (int i=0;i<=MAX_STACK_LEVEL;i++)
        (*self)->stack[i] = 0;

    // ram
    for (int i=0;i<=MAX_RAM_SIZE;i++)
        (*self)->ram[i] = 0;

    // screen
    for (int i=0;i<=WINDOW_HIGHT;i++)
        for (int j=0;j<=WINDOW_WIDTH;j++)
            (*self)->vram[i][j] = 0;
}

int load_rom(CPU *self){
    FILE *romfile;
    char *buffer;
    long filelength;
    romfile = fopen("../Animal Race [Brian Astle].ch8", "rb");
    if (!romfile){
        fprintf(stderr, "can't open file \n");
        return -1;
    }
    fseek(romfile, 0, SEEK_END);
    filelength = ftell(romfile);
    printf("the cursor is at %d\n", filelength);
    return 0;
}

void reset_cpu(CPU *self){
    (self)->I = 0;
    (self)->delay = 0;
    (self)->sound_timer = 0;
    (self)->PC = 0;
    (self)->SP = 0;

    // registers
    for (int i=0;i<= MAX_GENERAL_REGISTER;i++)
        (self)->V[i] = 0;
    
    for (int i=0;i<=MAX_STACK_LEVEL;i++)
        (self)->stack[i] = 0;

    // ram
    for (int i=0;i<=MAX_RAM_SIZE;i++)
        (self)->ram[i] = 0;

    // screen
    for (int i=0;i<=WINDOW_HIGHT;i++)
        for (int j=0;j<=WINDOW_WIDTH;j++)
            (self)->vram[i][j] = 0;
}