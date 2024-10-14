#include <stdint.h>
#include "../lib/interrupt_handler.c"

int main()
{
    // --> DEMO using IRQ 0,1,2,3
    // enable IRQ
    __nvic_enable_irq(0);
    __nvic_enable_irq(1);
    __nvic_enable_irq(2);
    __nvic_enable_irq(3);
    // set priority
    __nvic_set_priority(0, 7);
    __nvic_set_priority(1, 6);
    __nvic_set_priority(2, 5);
    __nvic_set_priority(3, 4);
    // pend IRQ
    uint32_t pend_IRQs = 0x00000000; // reset value
    pend_IRQs |= (1 << 0);
    pend_IRQs |= (1 << 1);
    pend_IRQs |= (1 << 2);
    pend_IRQs |= (1 << 3);
    NVIC_ISPR0 |= pend_IRQs;

    for (;;)
        ;
}