#include <stdint.h>
#define alias_base 0x22000000U
#define bit_band_base 0x20000000U
void reset_bit(uint8_t *address, int bit)
{
    *address &= ~(1 << bit);
}
void reset_bit_bitAlias(uint8_t *address, int bit)
{

    uint8_t *bitAlias = (uint8_t *)(alias_base + (32 * ((uint32_t)address - bit_band_base)) + bit * 4);

    *bitAlias = 0;
}
int main()
{

    uint8_t *p1 = (uint8_t *)0x20000200,
            *p2 = (uint8_t *)0x20000210;
    *p1 = 0x6;
    *p2 = 0x6;

    reset_bit(p1, 2);          // *p1 now 2
    reset_bit_bitAlias(p2, 2); // *p2 now 2

    for (;;)
        ;
}