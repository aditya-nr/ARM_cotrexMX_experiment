#include <stdint.h>
int main()
{
    // move content of varibable var into R0
    uint32_t var = 0xa5;
    __asm volatile("MOV R0,%0" ::"r"(var) :);

    // move content of non-memory-mapped register(genral/special) into var
    uint32_t control_var = 0, pc_var = 0;
    __asm volatile("MRS %0,CONTROL" : "=r"(control_var)::);
    __asm volatile("MOV %0,PC" : "=r"(pc_var)::);

    // move conternt from var1 to var2
    uint32_t var1 = 0, var2 = 0;
    var1 = 0xabc;
    __asm volatile("MOV %0,%1" : "=r"(var2) : "r"(var1) :);

    // move content form pointer to var3
    uint32_t var3, *var_ptr;
    var3 = 0;
    var_ptr = (uint32_t *)0x20000000;
    *var_ptr = 0xab;

    __asm volatile("LDR %0,[%1]" : "=r"(var3) : "r"(var_ptr) :);
    for (;;)
        ;
    return 0;
}