#include <stdint.h>
#define SCB 0xE000ED00U
#define SCB_SHCSR (*(uint32_t *)(SCB + 0x24U))
void exp_1()
{
    __asm("SVC #0x1");
}

void exp_2()
{
    SCB_SHCSR |= (1 << 7);
}
int main()
{
    // trigger svc by assembly code
    exp_1();

    for (;;)
        ;
    return 0;
}

void SVC_Handler()
{
    // read the value of System handler control and state register (SCB_SHCSR)
    __asm("MOV R0,%0" ::"r"(SCB_SHCSR)); // bit 7 is the svc active bit
    // check the content of IPSR for ISR_no
    uint32_t ipsr = 0;
    __asm("MRS R0,xPSR");
    __asm("MOV %0,R0" : "=r"(ipsr));
    ipsr &= 0x1FF; // need bit [8:0]
}