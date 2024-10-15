#include <stdint.h>
#define NVIC 0xE000E100U
#define NVIC_ISER0 (*(uint32_t *)(NVIC + 0x000U)) // set enable reg 0 //
#define NVIC_ISER1 (*(uint32_t *)(NVIC + 0x004U)) // set enable reg 1 //
#define NVIC_ISER2 (*(uint32_t *)(NVIC + 0x008U)) // set enable reg 2 //
#define NVIC_ISPR0 (*(uint32_t *)(NVIC + 0x100U)) // set pending reg 0 //
#define NVIC_IABR0 (*(uint32_t *)(NVIC + 0x200U)) // check if inter. is active or not
#define NVIC_STIR (*(uint32_t *)(0xE000EF00U))    // s/w trigger interrupt
#define NVIC_IPR0 (*(uint32_t *)(NVIC + 0x300U))  // ip3 ,ip2, ip1, ip0
void __nvic_enable_irq(uint8_t IRQ)
{
    if ((IRQ < 0) || (IRQ > 59))
    {
        return;
    }
    if (IRQ < 32)
    {
        NVIC_ISER0 |= (1 << IRQ);
    }
    else if (IRQ < 64)
    {
        IRQ -= 32;
        NVIC_ISER1 |= (1 << IRQ);
    }
    else
    {
        IRQ -= 64;
        NVIC_ISER2 |= (1 << IRQ);
    }
}
void __nvic_disbale_irq(uint8_t IRQ)
{
    NVIC_ISER0 &= ~(1 << IRQ);
}
void __nvic_trigger_irq(uint8_t IRQ)
{
    if ((IRQ < 0) || (IRQ > 59))
    {
        return;
    }
    NVIC_STIR = (0x000001FFU & IRQ);

    // method 2 : set ISPRx of corresponding reg
}
void __nvic_set_priority(uint8_t IRQ, uint8_t IP)
{
    if ((IP < 0) || (IP > 15))
    {
        return;
    }

    if (IRQ < 4)
    {
        NVIC_IPR0 |= (IP << ((8 * IRQ) + 4));
    }
}
void WWDG_IRQHandler()
{
    //
}

void PVD_IRQHandler()
{
    // do something
}
void TAMPER_IRQHandler()
{
    // do something
}
void RTC_IRQHandler()
{
    // do something
}
void FLASH_IRQHandler()
{
    // do something
}
void RCC_IRQHandler()
{
    // do something
}
void EXTI0_IRQHandler()
{
    // do something
}
void EXTI1_IRQHandler()
{
    // do something
}
void EXTI2_IRQHandler()
{
    // do something
}
void EXTI3_IRQHandler()
{
    // do something
}
void EXTI4_IRQHandler()
{
    // do something
}
void DMA1_Channel1_IRQHandler()
{
    // do something
}
void DMA1_Channel2_IRQHandler()
{
    // do something
}
void DMA1_Channel3_IRQHandler()
{
    // do something
}
void DMA1_Channel4_IRQHandler()
{
    // do something
}
void DMA1_Channel5_IRQHandler()
{
    // do something
}
void DMA1_Channel6_IRQHandler()
{
    // do something
}
void DMA1_Channel7_IRQHandler()
{
    // do something
}
void ADC1_2_IRQHandler()
{
    // do something
}
void USB_HP_CAN1_TX_IRQHandler()
{
    // do something
}
void USB_LP_CAN1_RX0_IRQHandler()
{
    // do something
}
void CAN1_RX1_IRQHandler()
{
    // do something
}
void CAN1_SCE_IRQHandler()
{
    // do something
}
void EXTI9_5_IRQHandler()
{
    // do something
}
void TIM1_BRK_IRQHandler()
{
    // do something
}
void TIM1_UP_IRQHandler()
{
    // do something
}
void TIM1_TRG_COM_IRQHandler()
{
    // do something
}
void TIM1_CC_IRQHandler()
{
    // do something
}
void TIM2_IRQHandler()
{
    // do something
}
void TIM3_IRQHandler()
{
    // do something
}
void I2C1_EV_IRQHandler()
{
    // do something
}
void I2C1_ER_IRQHandler()
{
    // do something
}
void SPI1_IRQHandler()
{
    // do something
}
void USART1_IRQHandler()
{
    // do something
}
void USART2_IRQHandler()
{
    // do something
}
void EXTI15_10_IRQHandler()
{
    // do something
}
void RTC_Alarm_IRQHandler()
{
    // do something
}
void USBWakeUp_IRQHandler()
{
    // do something
}
