#include "stm32f4xx.h"
#include "stm32f407xx.h"
void delay_ms(uint32_t ms);
extern void SystemInit(void);
int main(void) {
    // SystemInit();

    // Khoi tao clock cho GPIO
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // Cấu hình các chân PD12, PD13, PD14, PD15 là output
    GPIOD->MODER &= ~(0xFF << (2 * 12));         // Xoá cấu hình cũ
    GPIOD->MODER |=  (0x55 << (2 * 12));         // Output mode cho PD12..PD15

    GPIOD->OTYPER &= ~(0xF << 12);               // Push-pull
    GPIOD->OSPEEDR |= (0xFF << (2 * 12));        // High speed
    GPIOD->PUPDR &= ~(0xFF << (2 * 12));         // No pull-up, pull-down

    while (1) {
        // Bật LED
        GPIOD->ODR ^= (1 << 12); // LED xanh lá
        GPIOD->ODR ^= (1 << 13); // LED cam
        GPIOD->ODR ^= (1 << 14); // LED đỏ
        GPIOD->ODR ^= (1 << 15); // LED xanh dương

        delay_ms(3);
    }
}

// openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program blink.elf verify reset exit"
void delay_ms(uint32_t ms) {
    // Giả sử clock chạy ở 16 MHz từ HSI (hoặc bạn có thể thay đổi tùy theo clock thực tế)
    for (uint32_t i = 0; i < ms * 16000; i++) {
        __NOP();
    }
}
