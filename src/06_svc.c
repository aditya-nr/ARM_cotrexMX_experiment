#include <stdint.h>
#include <stdio.h>
#define NVIC_ISER0 ((uint32_t *)0xE000E100) // NVIC Interrupt Set-Enable Register 0 (for IRQs 0-31)
#define NVIC_STIR ((uint32_t *)0xE000EF00)  // NVIC Software Trigger Interrupt Register (STIR)

// Function to enable an interrupt in the NVIC
void enable_interrupt(uint32_t irq_number)
{
    *NVIC_ISER0 |= (1 << irq_number); // Set the bit corresponding to the IRQ number
}
void generate_interrupt(uint32_t irq_number)
{

    *NVIC_STIR = irq_number; // Write the interrupt number to trigger the interrupt
}
// Forward declaration of the SVC handler
void SVC_Handler(void);

// A simple function that triggers the SVC interrupt
void trigger_svc_interrupt()
{
    // Trigger SVC interrupt with SVC number 0x01
    __asm volatile("svc #0x01");
}

// Main function
int main(void)
{
    enable_interrupt(6);
    // Generate software interrupt for IRQ6 (EXTI0_IRQHandler)
    generate_interrupt(6); // Trigger EXTI0 (IRQ number 6)

    // Trigger a software interrupt (SVC) using SVC instruction
    trigger_svc_interrupt();

    // Endless loop
    while (1)
        ;
}

// SVC Handler: This is the interrupt handler that gets called when SVC is triggered
void SVC_Handler(void)
{
    // Here you can handle the software interrupt
    // This is just a simple example that prints a message
    printf("Software Interrupt (SVC) triggered!\n");
}

// Interrupt Handler for EXTI0 (External Interrupt Line 0)
void EXTI0_IRQHandler(void)
{
    // Interrupt handling logic here
    // For demonstration, we'll toggle a variable or set a flag
    volatile static uint32_t interrupt_counter = 0;
    interrupt_counter++;

    // Normally, you would clear the pending interrupt flag here in a real hardware scenario
    // For example, EXTI->PR |= (1 << 0);  // Clear the EXTI line 0 pending bit
}
