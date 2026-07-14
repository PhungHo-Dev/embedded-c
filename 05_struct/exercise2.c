#include <stdio.h>
#include <stdint.h>

#define GPIO_PIN_RESET 0
#define GPIO_PIN_SET   1

typedef struct
{
    uint32_t ODR;
} GPIO_TypeDef;

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state)
{
    if(state == GPIO_PIN_SET)
    {
        GPIOx->ODR |= (1U << pin);
    }
    else
    {
        GPIOx->ODR &= ~(1U << pin);
    }
}

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    return (GPIOx->ODR >> pin) & 1U;
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    GPIOx->ODR ^= (1U << pin);
}

GPIO_TypeDef GPIOA = {0};

int main(void)
{
    printf("Initial ODR : 0x%08X\n", GPIOA.ODR);

    GPIO_WritePin(&GPIOA, 5, GPIO_PIN_SET);
    printf("Set Pin 5   : 0x%08X\n", GPIOA.ODR);

    GPIO_TogglePin(&GPIOA, 5);
    printf("Toggle Pin 5: 0x%08X\n", GPIOA.ODR);

    GPIO_WritePin(&GPIOA, 5, GPIO_PIN_RESET);
    printf("Reset Pin 5 : 0x%08X\n", GPIOA.ODR);

    printf("Pin 5 State : %d\n", GPIO_ReadPin(&GPIOA, 5));

    return 0;
}
