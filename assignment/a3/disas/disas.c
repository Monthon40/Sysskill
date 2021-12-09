#include<stdio.h>
#include <stdint.h>

const char* getArr(int x){

    if (x == 0){
        return "%rax";
    }
    else if (x == 1){
        return "%rcx";
    }
    else if (x == 2){
        return "%rdx";
    }
    else if (x == 3){
        return "%rbx";
    }
    else if (x == 4){
        return "%rsp";
    }
    else if (x ==5){
        return "%rbp";
    }
    else if (x == 6){
        return "%rsi";
    }
    else if (x == 7){
        return "%rdi";
    }
    else{
        return 0;
    }
}

void disassemble(const unsigned char *raw_instr) {
    if (raw_instr[0] == 0xff){ //255
        if (raw_instr[1] == 0x74){ //116
            printf("pushq %#x(%s,%s,%d)\n", raw_instr[3], getArr(raw_instr[2] & 0x7), getArr((raw_instr[2] >> 3)& 0x7) , 1 << (raw_instr[2] >> 6));
        }
        else if ( raw_instr[1] == 0x70){  //112
            printf("pushq %#x(%s)\n", raw_instr[2], getArr(raw_instr[1] & 0x7));
        }
        else if (raw_instr[1] == 0x32){ //50
            printf("pushq (%s)\n", getArr(raw_instr[1] & 0x7));
        }
    }
    else if (( raw_instr[0] & 0x78) == 0x50){ //120, 80
        printf("pushq %s\n", getArr(raw_instr[0] & 0x7));
    }
    else if ( raw_instr[0] == 0x68){ //104
        printf("pushq $%#x\n",*(uint32_t *)(raw_instr + 1));
    }
    else{
        printf("Testtest");
    }
}

int main()
{
    // pushq $0x3f10
    unsigned char inst1[5] = {0x68,0x10,0x3f,0x00,0x00};
    // pushq %rbx
    unsigned char inst2[1] = {0x53};
    // pushq (%rdx)
    unsigned char inst3[2] = {0xff, 0x32};
    // pushq 0x8(%rax)
    unsigned char inst4[3] = {0xff, 0x70, 0x08};
    // pushq 0xff(%rbp,%rcx,4)
    unsigned char inst5[4] = {0xff, 0x74, 0x8d, 0xff};
    disassemble(inst1);
    disassemble(inst2);
    disassemble(inst3);
    disassemble(inst4);
    disassemble(inst5);
    return 0;
}
