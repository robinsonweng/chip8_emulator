#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"


int main(){
    CPU *cpuobj;
    if (-1 == new_cpu(&cpuobj))
        printf("cpu init failed");
    printf("%d", cpuobj->PC);
    return 0;
}