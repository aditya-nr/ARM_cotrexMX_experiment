// hello world into registers and read thorugh memview
#include <stdint.h>
#define SRAM_BASE 0x20000000
#define AT_ADDR(base, off) (*(uint32_t *)((base) + (off)))

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
    print("Hello World");
    print("My name is aditya");
    for (;;)
        ;
}