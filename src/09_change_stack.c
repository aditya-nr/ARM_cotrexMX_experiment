
void exp1()
{
    // sp=psp -> set bit 2 =1 of CONTROL register
    __asm("MRS R0,CONTROL");
    __asm("ORR R0,R0,0x2");
    __asm("MSR CONTROL,R0");
    // sp=msp ->clear bit 2=0 of CONTROL register
    __asm("MRS R0,CONTROL");
    int r0 = 0;
    __asm("MOV %0,R0" : "=r"(r0));
    r0 &= ~(0x2);
    __asm("MOV R0,%0" : : "r"(r0));
    __asm("MSR CONTROL,R0");
}
void exp2()
{
    // sp=psp -> set bit 2 = 1 of CONTROL register
    __asm("MRS R0,CONTROL");
    __asm("ORR R0,R0,0x2");
    __asm("MSR CONTROL,R0");
    // cause exception -> cause SVC
    __asm("svc #0x01");
}
int main()
{
    // change the sp=psp and back to sp=msp
    // exp1();

    // change the sp=psp, then cause interrupt and check if sp=msp
    exp2();
}
void HardFault_Handler()
{
}
void SVC_Handler(void)
{
    // printf("Software Interrupt (SVC) triggered!\n");
}