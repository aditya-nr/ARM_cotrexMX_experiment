#include <stdint.h>
void generate_interrupt_irq3()
{
    uint32_t *NVIC_ISER0 = (uint32_t *)0xE000E100; // Interrupt Set-Enable Register 0
    *NVIC_ISER0 |= (1 << 3);                       // Enable interrupt number 19 (IRQ3)

    uint32_t *NVIC_STIR = (uint32_t *)0xE000EF00; // Software Trigger Interrupt Register
    *NVIC_STIR = 19;                              // Trigger interrupt number 19 (corresponding to IRQ3)
}
void _change_access_lvl_NPAL()
{
    /** we need to modify CONTROL register, so we have to do use asm */
    __asm volatile("MRS R0,CONTROL"); // read CONTROL into R0
    __asm volatile("ORR R0,R0,#0x1"); // modify R0's bit 0
    __asm volatile("MSR CONTROL,R0"); // write CONTROL from R0
}

void _change_access_lvl_PAL()
{
    /** we need to modify CONTROL register, so we have to do use asm */
    __asm volatile("MRS R0,CONTROL"); // read CONTROL into R0
    __asm volatile("AND R0,R0,#0b0"); // modify R0's bit 0
    __asm volatile("MSR CONTROL,R0"); // write CONTROL from R0
}
int main()
{
    _change_access_lvl_NPAL();
    // _change_access_lvl_PAL();
    generate_interrupt_irq3();
    for (;;)
        ;
}

void HardFault_Handler()
{
    // __asm volatile("MRS R0,CONTROL"); // read CONTROL into R0
    _change_access_lvl_PAL();
}
void TAMPER_IRQHandler()
{
    __asm volatile("MRS R0,CONTROL");
}
void RTC_IRQHandler()
{
    __asm volatile("MRS R0,CONTROL");
}