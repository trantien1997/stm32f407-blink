# stm32f407-blink
## STM32F407 GPIO Tutorial - Bare Metal
### 1. Control Registers
Before looking into the control register, we will see the Clock Register (RCC_AHB1ENR) which will enable the AHB clock to the GPIO ports

RCC_AHB1ENG
This is called as RCC AHB1 peripheral clock enable register. The register is given below.

![image](https://github.com/user-attachments/assets/eab604ae-a342-4ae1-98ef-c838dd6c3437)

Bit [0] – GPIOAEN: IO port A clock enable

0 – IO port A clock disabled

1 – IO port A clock enabled

Bit [1] – GPIOBEN: IO port B clock enable

0 – IO port B clock disabled

1 – IO port B clock enabled

Bit [2] – GPIOBEN: IO port C clock enable

0 – IO port C clock disabled

1 – IO port C clock enabled

Bit [3] – GPIOBEN: IO port D clock enable

0 – IO port D clock disabled

1 – IO port D clock enabled

Bit [4] – GPIOBEN: IO port E clock enable

0 – IO port E clock disabled

1 – IO port E clock enabled
We don’t need the rest of the bits as we are only working on GPIO.

Example:

```c
//These are a couple of ways of enabling AHB clock for Port A
SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
RCC->AHB1ENR |= (1UL << 0U);'''
```
The below control registers are used to configure the GPIOs.
### 2. GPIOx_MODER
This GPIO port mode register is used to select the I/O direction. Please find the below image of the GPIOx_MODER register.
![image](https://github.com/user-attachments/assets/ac810db0-ef21-428a-968d-18483d750e03)

Here 2-bits are combined for one particular GPIO pin.

Bits [31:0] – MODERy: Direction selection for port X and bit Y, (y = 0 … 15)

MODERy Direction Selection:

00: Input (reset state)

01: General purpose output mode

10: Alternate Function mode

11: Analog mode


