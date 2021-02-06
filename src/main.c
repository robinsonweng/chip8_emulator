#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"


int main(){
    CPU *cpuobj;
    printf("init cpu object\n");
    if (-1==new_cpu(&cpuobj)){
        printf("cpu new faild\n");
        return -1;
    }
    cpuobj->LoadRom(cpuobj);

    return 0;
}