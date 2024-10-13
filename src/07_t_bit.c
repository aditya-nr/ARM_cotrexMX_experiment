#include <stdint.h>
#define SRAM_BASE 0x20000000
#define AT_ADDR(base, off) (*(uint32_t *)((base) + (off)))
void HardFault_Handler()
{
    // __asm volatile("MRS R0,CONTROL"); // read CONTROL into R0
    // _change_access_lvl_PAL();
    // print("Hard Fault");
}
void print(char *str)
{
    int count = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        count++;
        AT_ADDR(SRAM_BASE, i) = str[i];
    }

    count = 16 - (count % 16);
    for (int j = 0; j < count; j++)
    {
        AT_ADDR(SRAM_BASE, (i + j)) = ' ';
    }
}
int main()
{
    int r0;
    // __asm("MRS R0, xPSR");          // Read EPSR into R0 (R0 = EPSR)
    // __asm("MOV %0, R0" : "=r"(r0)); // Move R0 to C variable r0 (r0 = R0)

    // r0 &= ~(1 << 24); // Clear the 24th bit (T-bit), which is illegal

    // __asm("MOV R0, %0" ::"r"(r0));         // Move r0 back to R0
    // __asm("MSR xPSR, R0");                 // Attempt to write back to EPSR, causing a fault

    // volatile int *ptr = (int *)0xFFFFFFF0; // Invalid memory address
    // int val = *ptr;                   // Accessing invalid memory

    // __asm volatile(
    //     "B 0x20000001" // Branch to an odd address //
    // );
    // uint32_t (*f_ptr1)(char *str) = (void *)0x8000118;
    uint32_t (*f_ptr1)(char *str) = print;

    uint32_t (*f_ptr2)(char *str) = HardFault_Handler;
    uint32_t (*f_ptr3)(char *str) = main;
    f_ptr1("Hello");
    // uint32_t (*f_ptr4)(char *str) = Default_Handler;
    // f_ptr("HEllo");
    for (;;)
        ;
    return 0;
}
