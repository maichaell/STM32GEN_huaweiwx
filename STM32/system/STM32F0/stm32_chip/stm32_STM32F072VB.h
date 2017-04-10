//Autogenerated file
//MCU name: STM32F072VB
//MCU  xml: STM32F072V(8-B)Tx.xml
//GPIO remap/alternate function xml: GPIO-STM32F052_gpio_v1_0_Modes.xml

/*
const stm32_port_pin_type port_pin_list[] = {
  { GPIOA, GPIO_PIN_0 },
  { GPIOA, GPIO_PIN_1 },
  { GPIOA, GPIO_PIN_2 },
  { GPIOA, GPIO_PIN_3 },
  { GPIOA, GPIO_PIN_4 },
  { GPIOA, GPIO_PIN_5 },
  { GPIOA, GPIO_PIN_6 },
  { GPIOA, GPIO_PIN_7 },
  { GPIOA, GPIO_PIN_8 },
  { GPIOA, GPIO_PIN_9 },
  { GPIOA, GPIO_PIN_10},
  { GPIOA, GPIO_PIN_11},
  { GPIOA, GPIO_PIN_12},
  { GPIOA, GPIO_PIN_13},
  { GPIOA, GPIO_PIN_14},
  { GPIOA, GPIO_PIN_15},
  { GPIOB, GPIO_PIN_0 },
  { GPIOB, GPIO_PIN_1 },
  { GPIOB, GPIO_PIN_2 },
  { GPIOB, GPIO_PIN_3 },
  { GPIOB, GPIO_PIN_4 },
  { GPIOB, GPIO_PIN_5 },
  { GPIOB, GPIO_PIN_6 },
  { GPIOB, GPIO_PIN_7 },
  { GPIOB, GPIO_PIN_8 },
  { GPIOB, GPIO_PIN_9 },
  { GPIOB, GPIO_PIN_10},
  { GPIOB, GPIO_PIN_11},
  { GPIOB, GPIO_PIN_12},
  { GPIOB, GPIO_PIN_13},
  { GPIOB, GPIO_PIN_14},
  { GPIOB, GPIO_PIN_15},
  { GPIOC, GPIO_PIN_0 },
  { GPIOC, GPIO_PIN_1 },
  { GPIOC, GPIO_PIN_2 },
  { GPIOC, GPIO_PIN_3 },
  { GPIOC, GPIO_PIN_4 },
  { GPIOC, GPIO_PIN_5 },
  { GPIOC, GPIO_PIN_6 },
  { GPIOC, GPIO_PIN_7 },
  { GPIOC, GPIO_PIN_8 },
  { GPIOC, GPIO_PIN_9 },
  { GPIOC, GPIO_PIN_10},
  { GPIOC, GPIO_PIN_11},
  { GPIOC, GPIO_PIN_12},
  { GPIOC, GPIO_PIN_13},
  { GPIOC, GPIO_PIN_14},
  { GPIOC, GPIO_PIN_15},
  { GPIOD, GPIO_PIN_0 },
  { GPIOD, GPIO_PIN_1 },
  { GPIOD, GPIO_PIN_2 },
  { GPIOD, GPIO_PIN_3 },
  { GPIOD, GPIO_PIN_4 },
  { GPIOD, GPIO_PIN_5 },
  { GPIOD, GPIO_PIN_6 },
  { GPIOD, GPIO_PIN_7 },
  { GPIOD, GPIO_PIN_8 },
  { GPIOD, GPIO_PIN_9 },
  { GPIOD, GPIO_PIN_10},
  { GPIOD, GPIO_PIN_11},
  { GPIOD, GPIO_PIN_12},
  { GPIOD, GPIO_PIN_13},
  { GPIOD, GPIO_PIN_14},
  { GPIOD, GPIO_PIN_15},
  { GPIOE, GPIO_PIN_0 },
  { GPIOE, GPIO_PIN_1 },
  { GPIOE, GPIO_PIN_2 },
  { GPIOE, GPIO_PIN_3 },
  { GPIOE, GPIO_PIN_4 },
  { GPIOE, GPIO_PIN_5 },
  { GPIOE, GPIO_PIN_6 },
  { GPIOE, GPIO_PIN_7 },
  { GPIOE, GPIO_PIN_8 },
  { GPIOE, GPIO_PIN_9 },
  { GPIOE, GPIO_PIN_10},
  { GPIOE, GPIO_PIN_11},
  { GPIOE, GPIO_PIN_12},
  { GPIOE, GPIO_PIN_13},
  { GPIOE, GPIO_PIN_14},
  { GPIOE, GPIO_PIN_15},
  { GPIOF, GPIO_PIN_0 },
  { GPIOF, GPIO_PIN_1 },
  { GPIOF, GPIO_PIN_2 },
  { GPIOF, GPIO_PIN_3 },
  { GPIOF, GPIO_PIN_6 },
  { GPIOF, GPIO_PIN_9 },
  { GPIOF, GPIO_PIN_10},
};
*/

/*
enum {
   PA0 ,
   PA1 ,
   PA2 ,
   PA3 ,
   PA4 ,
   PA5 ,
   PA6 ,
   PA7 ,
   PA8 ,
   PA9 ,
   PA10,
   PA11,
   PA12,
   PA13,
   PA14,
   PA15,
   PB0 ,
   PB1 ,
   PB2 ,
   PB3 ,
   PB4 ,
   PB5 ,
   PB6 ,
   PB7 ,
   PB8 ,
   PB9 ,
   PB10,
   PB11,
   PB12,
   PB13,
   PB14,
   PB15,
   PC0 ,
   PC1 ,
   PC2 ,
   PC3 ,
   PC4 ,
   PC5 ,
   PC6 ,
   PC7 ,
   PC8 ,
   PC9 ,
   PC10,
   PC11,
   PC12,
   PC13,
   PC14,
   PC15,
   PD0 ,
   PD1 ,
   PD2 ,
   PD3 ,
   PD4 ,
   PD5 ,
   PD6 ,
   PD7 ,
   PD8 ,
   PD9 ,
   PD10,
   PD11,
   PD12,
   PD13,
   PD14,
   PD15,
   PE0 ,
   PE1 ,
   PE2 ,
   PE3 ,
   PE4 ,
   PE5 ,
   PE6 ,
   PE7 ,
   PE8 ,
   PE9 ,
   PE10,
   PE11,
   PE12,
   PE13,
   PE14,
   PE15,
   PF0 ,
   PF1 ,
   PF2 ,
   PF3 ,
   PF6 ,
   PF9 ,
   PF10,
NUM_PINS,
};
*/

const alternate_pin_type alternate_i2c_scl [] = {
//I2C1
    { I2C1  , GPIOB, GPIO_PIN_6  , GPIO_AF1_I2C1  }, 
    { I2C1  , GPIOB, GPIO_PIN_8  , GPIO_AF1_I2C1  }, 
//I2C2
    { I2C2  , GPIOB, GPIO_PIN_10 , GPIO_AF1_I2C2  }, 
    { I2C2  , GPIOB, GPIO_PIN_13 , GPIO_AF5_I2C2  }, 
}; 

const alternate_pin_type alternate_i2c_sda [] = {
//I2C1
    { I2C1  , GPIOB, GPIO_PIN_7  , GPIO_AF1_I2C1  }, 
    { I2C1  , GPIOB, GPIO_PIN_9  , GPIO_AF1_I2C1  }, 
//I2C2
    { I2C2  , GPIOB, GPIO_PIN_11 , GPIO_AF1_I2C2  }, 
    { I2C2  , GPIOB, GPIO_PIN_14 , GPIO_AF5_I2C2  }, 
}; 

const alternate_pin_type alternate_spi_miso [] = {
//SPI1
    { SPI1  , GPIOA, GPIO_PIN_6  , GPIO_AF0_SPI1  }, 
    { SPI1  , GPIOB, GPIO_PIN_4  , GPIO_AF0_SPI1  }, 
    { SPI1  , GPIOE, GPIO_PIN_14 , GPIO_AF1_SPI1  }, 
//SPI2
    { SPI2  , GPIOB, GPIO_PIN_14 , GPIO_AF0_SPI2  }, 
    { SPI2  , GPIOC, GPIO_PIN_2  , GPIO_AF1_SPI2  }, 
    { SPI2  , GPIOD, GPIO_PIN_3  , GPIO_AF1_SPI2  }, 
}; 

const alternate_pin_type alternate_spi_mosi [] = {
//SPI1
    { SPI1  , GPIOA, GPIO_PIN_7  , GPIO_AF0_SPI1  }, 
    { SPI1  , GPIOB, GPIO_PIN_5  , GPIO_AF0_SPI1  }, 
    { SPI1  , GPIOE, GPIO_PIN_15 , GPIO_AF1_SPI1  }, 
//SPI2
    { SPI2  , GPIOB, GPIO_PIN_15 , GPIO_AF0_SPI2  }, 
    { SPI2  , GPIOC, GPIO_PIN_3  , GPIO_AF1_SPI2  }, 
    { SPI2  , GPIOD, GPIO_PIN_4  , GPIO_AF1_SPI2  }, 
}; 

const alternate_pin_type alternate_spi_sck [] = {
//SPI1
    { SPI1  , GPIOA, GPIO_PIN_5  , GPIO_AF0_SPI1  }, 
    { SPI1  , GPIOB, GPIO_PIN_3  , GPIO_AF0_SPI1  }, 
    { SPI1  , GPIOE, GPIO_PIN_13 , GPIO_AF1_SPI1  }, 
//SPI2
    { SPI2  , GPIOB, GPIO_PIN_10 , GPIO_AF5_SPI2  }, 
    { SPI2  , GPIOB, GPIO_PIN_13 , GPIO_AF0_SPI2  }, 
    { SPI2  , GPIOD, GPIO_PIN_1  , GPIO_AF1_SPI2  }, 
}; 

const alternate_pin_type alternate_usart_rx [] = {
//USART1
    { USART1, GPIOA, GPIO_PIN_10 , GPIO_AF1_USART1}, 
    { USART1, GPIOB, GPIO_PIN_7  , GPIO_AF0_USART1}, 
//USART2
    { USART2, GPIOA, GPIO_PIN_15 , GPIO_AF1_USART2}, 
    { USART2, GPIOA, GPIO_PIN_3  , GPIO_AF1_USART2}, 
    { USART2, GPIOD, GPIO_PIN_6  , GPIO_AF0_USART2}, 
//USART3
    { USART3, GPIOB, GPIO_PIN_11 , GPIO_AF4_USART3}, 
    { USART3, GPIOC, GPIO_PIN_11 , GPIO_AF1_USART3}, 
    { USART3, GPIOC, GPIO_PIN_5  , GPIO_AF1_USART3}, 
    { USART3, GPIOD, GPIO_PIN_9  , GPIO_AF0_USART3}, 
//USART4
    { USART4, GPIOA, GPIO_PIN_1  , GPIO_AF4_USART4}, 
    { USART4, GPIOC, GPIO_PIN_11 , GPIO_AF0_USART4}, 
}; 

const alternate_pin_type alternate_usart_tx [] = {
//USART1
    { USART1, GPIOA, GPIO_PIN_9  , GPIO_AF1_USART1}, 
    { USART1, GPIOB, GPIO_PIN_6  , GPIO_AF0_USART1}, 
//USART2
    { USART2, GPIOA, GPIO_PIN_14 , GPIO_AF1_USART2}, 
    { USART2, GPIOA, GPIO_PIN_2  , GPIO_AF1_USART2}, 
    { USART2, GPIOD, GPIO_PIN_5  , GPIO_AF0_USART2}, 
//USART3
    { USART3, GPIOB, GPIO_PIN_10 , GPIO_AF4_USART3}, 
    { USART3, GPIOC, GPIO_PIN_10 , GPIO_AF1_USART3}, 
    { USART3, GPIOC, GPIO_PIN_4  , GPIO_AF1_USART3}, 
    { USART3, GPIOD, GPIO_PIN_8  , GPIO_AF0_USART3}, 
//USART4
    { USART4, GPIOA, GPIO_PIN_0  , GPIO_AF4_USART4}, 
    { USART4, GPIOC, GPIO_PIN_10 , GPIO_AF0_USART4}, 
}; 
