//  STM32F103-CMSIS-I2C-basic

//  Target Microcontroller: STM32F103 (Blue Pill)
//  Mike Shegedin, 04/2023 (edit as needed)
//
//  Display the simplest case of I2C transmission:
//    1. Setup GPIO and RCC clocks required for I2C functionality
//    2. Initialize I2C timings
//    3. Conduct basic 1-byte I2C transmit sequence
//
//  Target I2C device: I2C 16x2 LCD Driver Module based on 
//  HARDWARE SETUP
//  ==============
//  The 16x2 LCD module requires 5V signals to operate but the
//  STM32 operates at 3.3V. Fortunately most STM32 GPIO pins are
//  5V tolerant, so if they are set to floating output, they can
//  be tied to 5V with pullup resistors. Other values of
//  resistors may work, but 5.6 k ohm resisters were verified as
//  working.
//
//  Needless to say, this means that an external 5V supply is
//  required. One option is to use the 5V line on the Blue Pill
//  when it is powered via the USB port.
//
//     Blue Pill  16x2 LCD  INLINE  5V/GND
//     =========  ========  ======  ======
//        GND ----- VSS ------------- GND
//         5V ----- VDD ------------- 5V
//                                /-- 5V
//                   VO -[10k Pot]**     (LCD contrast control)
//                                \-- GND
//         B14 ----- RS -- [100K]* -- 5V
//                   RW ------------- GND
//         B15 ----- EN -- [100K] --- 5V
//                   D0 ------------- GND
//                   D1 ------------- GND
//                   D2 ------------- GND
//                   D3 ------------- GND
//         A8 ------ D4 -- [100K]* -- 5V
//         A9 ------ D5 -- [100K]* -- 5V
//        A10 ------ D6 -- [100K]* -- 5V
//        A11 ------ D7 -- [100K]* -- 5V
//                    A -- [1.0K] --- 5V
//                    K ------------- GND
//
//  Alternative Hardware Setup
//  ==========================
//  This might not work for everyone, but at least for some LCD
//  modules, the pullup resistors may not be required, except
//  for the one between 5V and the LCD RS line. Also, instead of
//  a bulky potentiometer for the contrast control to V0, a 2K
//  resistor between V0 and 5V may be good enough to maintain
//  good contrast.
//
// ** Pot may be replaced by a 2k resistor between V0 and GND.
//         VO -- [ 2k ] --- GND (LCD contrast control)
//        
//  * These pullup resistors to 5V might not be required.
//    Note that the RS line seems to require the pullup resistor.
//        B14 ------ RS
//         A8 ------ D4
//         A9 ------ D5
//        A10 ------ D6
//        A11 ------ D7


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
