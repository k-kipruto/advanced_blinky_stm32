#include<stdint.h>
/*
 * defining Port configuration register CNF and Mode
 */

/*
 * In input mode CNFy[1:0]
 */
#define GPIO_CNF_INPUT_ANALOG	0b00
#define GPIO_CNF_INPUT_FLOATING	0b01
#define GPIO_CNF_INPUT_PULLUP_PULLDOWN	0b10

/*
 * In output mode CNFy[1:0]
 */
#define GPIO_CNF_OUTPUT_PUSHPULL	0b00
#define GPIO_CNF_OUTPUT_OPENDRAIN	0b01
#define GPIO_CNF_ALTFN_OUTPUT_PUSHPULL	0b10
#define GPIO_CNF_ALTFN_OUTPUT_OPENDRAIN	0b11

/*
 * MODEy[1:0]
 */

#define GPIO_MODE_INPUT				0b00
#define GPIO_MODE_OUTPUT_10_MHZ		0b01
#define GPIO_MODE_OUTPUT_2_MHZ		0b10
#define GPIO_MODE_OUTPUT_50_MHZ		0b11


/*
 * defining base addresses for peripherals
 */
#define GPIOA_BASE         ((uint32_t) 0x40010800)
#define GPIOB_BASE         ((uint32_t) 0x40010C00)
#define GPIOC_BASE         ((uint32_t) 0x40011000)
#define GPIOD_BASE         ((uint32_t) 0x40011400)
#define RCC_BASE           ((uint32_t) 0x40021000)


/*
 * struct for GPIO Registers
 */
typedef struct {
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_Type;
/*
 * Struct for RCC Registers
 */
typedef struct {
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
} RCC_Type;

/*
 * Reusing GPIO_Type for all ports
 */
#define GPIOA         ( (GPIO_Type*)     GPIOA_BASE  )
#define GPIOB         ( (GPIO_Type*)     GPIOB_BASE  )
#define GPIOC         ( (GPIO_Type*)     GPIOC_BASE  )
#define GPIOD         ( (GPIO_Type*)     GPIOD_BASE  )
#define RCC           ( (RCC_Type*)       RCC_BASE    )


/*
 * function for setting GPIO port
 */
void gpio_set_mode(GPIO_Type* GPIOx, uint8_t mode, uint8_t cnf, uint16_t pin);
















