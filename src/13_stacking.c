#include <stdint.h>

void fun_1();

#define SRAM_START 0x20000000
#define SRAM_SIZE 10240
#define SRAM_END ((SRAM_START) + SRAM_SIZE)

#define PSP_START ((SRAM_END) - 1024U) // Start of PSP
#define MSP_START ((SRAM_END) - 512U)  // Start of MSP

int main()
{
    uint32_t *__psp = (uint32_t *)PSP_START;
    uint32_t *__msp = (uint32_t *)MSP_START;

    // Initialize MSP and PSP
    __asm volatile("MSR PSP, %0" ::"r"(__psp)); // Set PSP
    __asm volatile("MSR MSP, %0" ::"r"(__msp)); // Set MSP

    // Switch to use PSP in Thread mode
    __asm volatile(
        "MOV R0, #2      \n" // Set CONTROL to switch to PSP
        "MSR CONTROL, R0 \n"
        "ISB" // Instruction Synchronization Barrier
    );

    // put some dummy data to r0-r3,r12
    __asm volatile("LDR R0,=0xF0F0F0F0");
    __asm volatile("LDR R1,=0xF0F0F0F1");
    __asm volatile("LDR R2,=0xF0F0F0F2");
    __asm volatile("LDR R3,=0xF0F0F0F3");
    __asm volatile("LDR R12,=0xF0F0F0F4");

    int i = 0, target = 10;
    fun_1();
    for (;;)
    {
        i++;
        if (i == target)
        {
            __asm volatile("SVC #1"); // Trigger SVC interrupt
            i = 0;
        }
    }
}

// SVC handler
void SVC_Handler(void)
{
    // Handle the SVC interrupt
    *(uint32_t *)0x200023F8 = (uint32_t)fun_1;
}

void fun_1()
{
    // fun_1 handler
}
