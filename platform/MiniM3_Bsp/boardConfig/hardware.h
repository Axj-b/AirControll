#ifndef __HARDWARE_H
#define __HARDWARE_H

#include "common.h"

// Bit-band addressing
#define BITBAND(addr, bitnum) ((addr & 0xF0000000) + 0x2000000 + ((addr & 0xFFFFF) << 5) + (bitnum << 2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

// IO port address definitions
#define GPIOA_ODR_Addr    (GPIOA_BASE + 12) // 0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE + 12) // 0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE + 12) // 0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE + 12) // 0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE + 12) // 0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE + 12) // 0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE + 12) // 0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE + 8)  // 0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE + 8)  // 0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE + 8)  // 0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE + 8)  // 0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE + 8)  // 0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE + 8)  // 0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE + 8)  // 0x40011E08 

// IO control macros, only for one IO pin!
// Ensure n is less than 16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr, n)  // Output to PA pin
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr, n)  // Input from PA pin 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr, n)  // Output to PB pin
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr, n)  // Input from PB pin 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr, n)  // Output to PC pin
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr, n)  // Input from PC pin 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr, n)  // Output to PD pin
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr, n)  // Input from PD pin 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr, n)  // Output to PE pin
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr, n)  // Input from PE pin

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr, n)  // Output to PF pin
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr, n)  // Input from PF pin

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr, n)  // Output to PG pin
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr, n)  // Input from PG pin

#endif
