//  main.c for STM32F030-CMSIS-LCD-lib
//    Simple functionality to control a 8x2 LCD via the STM32F030 microcontroller.
//
//    Mike Shegedin, EZdenki.com
//
//    Version 1.0   16 Aug 2023   Updated comments
//    Version 0.9      Jul 2023   Started
//
//    Target Microcontroller: STM32F030F4xx
//
//  HARDWARE SETUP
//  ==============
//  See STM32F030-CMSIS-LCD-lib for details on how to connect the STM32F030 microcontroller
//  and the 16x2 LCD module.

#include "stm32f030x6.h"  // Primary CMSIS header file
#include "STM32F030-CMSIS-LCD-lib.c"


int
main()
{
  LCD_init();

  LCD_cmd( LCD_1ST_LINE );
  LCD_puts( "3.3V I/O");
  LCD_cmd( LCD_2ND_LINE );
  LCD_puts( "LCD DISP");

  while( 1 ) ;
  return 1;
}  
