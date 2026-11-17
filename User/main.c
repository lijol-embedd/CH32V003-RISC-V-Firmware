#include <stdint.h>

/* ---------------- RCC ---------------- */

#define RCC_APB2PCENR (*(volatile uint32_t *)0x40021018)

/* ---------------- GPIO ---------------- */

#define GPIOD_CFGLR   (*(volatile uint32_t *)0x40011400)
#define GPIOD_OUTDR   (*(volatile uint32_t *)0x4001140C)

/* ---------------- TIM1 ---------------- */

#define TIM1_CTLR1       (*(volatile uint16_t *)0x40012C00)
#define TIM1_INTFR       (*(volatile uint16_t *)0x40012C10)
#define TIM1_PSC         (*(volatile uint16_t *)0x40012C28)
#define TIM1_ATRLR       (*(volatile uint16_t *)0x40012C2C)

int main(void)
{
    /* Enable clocks */
    RCC_APB2PCENR |= (1 << 5);      // GPIOD
    RCC_APB2PCENR |= (1 << 11);     // TIM1

    /* PD6 = Push-Pull Output, 2 MHz */
    GPIOD_CFGLR &= ~(0xF << 24);
    GPIOD_CFGLR |=  (0x2 << 24);

    /* Timer configuration */
    TIM1_PSC   = 23999;
    TIM1_ATRLR = 999;

    /* Start timer */
    TIM1_CTLR1 |= (1 << 0);

    while (1)
    {
        if (TIM1_INTFR & (1 << 0))
        {
            /* Clear Update Flag */
            TIM1_INTFR &= ~(1 << 0);

            /* Toggle PD6 */
            GPIOD_OUTDR ^= (1 << 6);
        }
    }
}