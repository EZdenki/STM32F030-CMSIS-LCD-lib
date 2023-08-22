//  ==========================================================================================
//  main.c for STM32F030-CMSIS-LCD-lib.c
//  ------------------------------------------------------------------------------------------
//  Simple functionality to control a 16x2 (or similar) LCD via the STM32F030 microcontroller.
//  ------------------------------------------------------------------------------------------
//  https://github.com/EZdenki/STM32F030-CMSIS-LCD-lib
//  Released under the MIT License
//  Copyright (c) 2023
//  Mike Shegedin, EZdenki.com
//    Version 1.0   16 Aug 2023   Updated comments
//    Version 0.9      Jul 2023   Started
//  ------------------------------------------------------------------------------------------
//  Target Devices: STM32F030F4xx, 16x2 (or 8x2, etc.) LCD display
//  ------------------------------------------------------------------------------------------
//  HARDWARE SETUP:
//    The LCD module requires 4 to 5 Vdc to operate and therefore uses 5V signals. However,
//    the STM32F030 IO pins are not 5V tolerant. To mitigate this, all of the signal lines
//    between the LCD display and the microcontroller will be pulled down using a 10k
//    resistor. The LCD does respond to 3.3 V signals, however, this is a little lower than
//    the 70% of VCC required for a positive pulse according to the datasheet. This can be
//    further mitigated by powering the LCD module with 4.3 V by connecting the VCC pin on the
//    LCD through a diode. By doing so, a high signal would only require 70% of 4.3 V, or
//    3.0 V, making 3.3 signalling sufficient.
//
//          STM32F030        LCD    INLINE  5V/GND
//         ============    =======  ======  ======
//         GND (pin 15) ---- VSS ------------- GND
//         VDD (pin 16) --------------------- 3.3V
//                           VDD - [-Diode+] - 5V
//                                         /-- 5V
//                            VO -[10k Pot]**     (LCD contrast control)
//                                         \-- GND
//          A5 (pin 11) ----- RS --- [10K] --- GND
//                            RW ------------- GND
//          A4 (pin 10) ----- EN --- [10K] --- GND
//                            D0 ------------- GND
//                            D1 ------------- GND
//                            D2 ------------- GND
//                            D3 ------------- GND
//           A0 (pin 6) ----- D4 --- [10K] --- GND
//           A1 (pin 7) ----- D5 --- [10K] --- GND
//           A2 (pin 8) ----- D6 --- [10K] --- GND
//           A3 (pin 9) ----- D7 --- [10K] --- GND
//
//  ==========================================================================================

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
