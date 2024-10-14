#include <stdint.h>
#include "../lib/interrupt_handler.c"

int main()
{
    for (int i = 0; i < 32; i++)
    {
        __nvic_enable_irq(i);
        __nvic_trigger_irq(i);
    }

    for (;;)
        ;
}