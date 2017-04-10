//Autogenerated file
//MCU name: STM32F031F6
//MCU  xml: STM32F031F(4-6)Px.xml
//GPIO remap/alternate function xml: GPIO-STM32F031_gpio_v1_0_Modes.xml

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
  { GPIOA, GPIO_PIN_9 },
  { GPIOA, GPIO_PIN_10},
  { GPIOA, GPIO_PIN_13},
  { GPIOA, GPIO_PIN_14},
  { GPIOB, GPIO_PIN_1 },
  { GPIOF, GPIO_PIN_0 },
  { GPIOF, GPIO_PIN_1 },
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
   PA9 ,
   PA10,
   PA13,
   PA14,
   PB1 ,
   PF0 ,
   PF1 ,
NUM_PINS,
};
*/

const alternate_pin_type alternate_i2c_scl [] = {
//I2C1
    { I2C1  , GPIOA, GPIO_PIN_9  , GPIO_AF4_I2C1  }, 
}; 

const alternate_pin_type alternate_i2c_sda [] = {
//I2C1
    { I2C1  , GPIOA, GPIO_PIN_10 , GPIO_AF4_I2C1  }, 
}; 

const alternate_pin_type alternate_spi_miso [] = {
//SPI1
    { SPI1  , GPIOA, GPIO_PIN_6  , GPIO_AF0_SPI1  }, 
}; 

const alternate_pin_type alternate_spi_mosi [] = {
//SPI1
    { SPI1  , GPIOA, GPIO_PIN_7  , GPIO_AF0_SPI1  }, 
}; 

const alternate_pin_type alternate_spi_sck [] = {
//SPI1
    { SPI1  , GPIOA, GPIO_PIN_5  , GPIO_AF0_SPI1  }, 
}; 

const alternate_pin_type alternate_usart_rx [] = {
//USART1
    { USART1, GPIOA, GPIO_PIN_10 , GPIO_AF1_USART1}, 
    { USART1, GPIOA, GPIO_PIN_3  , GPIO_AF1_USART1}, 
}; 

const alternate_pin_type alternate_usart_tx [] = {
//USART1
    { USART1, GPIOA, GPIO_PIN_14 , GPIO_AF1_USART1}, 
    { USART1, GPIOA, GPIO_PIN_2  , GPIO_AF1_USART1}, 
    { USART1, GPIOA, GPIO_PIN_9  , GPIO_AF1_USART1}, 
}; 
