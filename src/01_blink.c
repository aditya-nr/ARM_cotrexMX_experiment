#include <stdint.h>
#define RCC_BASE 0x40021000
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOC_BASE 0x40011000
#define GPIOC_CRH (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_BSRR (*(volatile uint32_t *)(GPIOC_BASE + 0x10))

void delay(int d)
{
    while (d--)
        for (int i = 0; i < 10000; i++)
            ;
}

int main()
{
    // enbale clock for GPIOC
    RCC_APB2ENR |= (1 << 4);

    // set PC13 in output mode (low speed, push-pull)
    // CNF13[23], CNF13[22], MODE13[21], MODE13[20]
    GPIOC_CRH &= ~(0b1111 << 20); // reset
    GPIOC_CRH |= (0b0010 << 20);  // set CNF = 00 (general output push-pull) MODE=10 (low speed OUTPUT)

    while (1)
    {
        GPIOC_BSRR = (0b1 << 13); // set 13th bit to set PC13
        delay(1000);
        GPIOC_BSRR = (0b1 << (13 + 16)); // set 29th bit to reset PC13
        delay(1000);
    }

    return 0;
}
