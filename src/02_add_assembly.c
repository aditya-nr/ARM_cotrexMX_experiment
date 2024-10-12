#include <stdint.h>
int main()
{
    *(uint32_t *)0x20000000 = 0x1;
    *(uint32_t *)0x20000004 = 0x2;
    *(uint32_t *)0x20000008 = 0x3;
    *(uint32_t *)0x2000000C = 0x4;
    *(uint32_t *)0x20000010 = 0x5;
    *(uint32_t *)0x20000014 = 0x6;
    *(uint32_t *)0x20000018 = 0x7;
    *(uint32_t *)0x2000001C = 0x8;
    *(uint32_t *)0x20000020 = 0x9;
    *(uint32_t *)0x20000024 = 0xA;
    *(uint32_t *)0x20000028 = 0xB;
    *(uint32_t *)0x2000002C = 0xC;

    __asm("LDR R1,=#0x20000010");
    __asm("LDR R2,=#0x20000014");
    __asm("LDR R3,[R1]");
    __asm("LDR R4,[R2]");
    __asm("ADD R5,R3,R4");
    __asm("STR R5,[R1]");
    for (;;)
        ;
    return 0;
}