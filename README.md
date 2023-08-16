# STM32F030-CMSIS-LCD-lib.c
Library to interface the STM32F030F4xx to a 16x2 (or other) LCD module. Requires six IO pins. Note that the pins used on the microcontroller are not 5V tolerant and must be tied to GND with a 10 KΩ resistor on each of RS (A5), EN (A4), D4 (A3), D5 (A2), D6 (A1), and D7 (A0). Includes a sample main.c program that initializes the LCD and displays some text.

## The Following Routines are Defined:
+ ```void LCD_init( void )```<br>
	Initializes LCD by initializing required GPIO ports and pins used to talk
	to the LCD. Also initializes the LCD screen itself to be in 4-bit mode.
    	This setup uses GPIO A0, A1, A2, and A3 for LCD data pins 4, 5, 6, 7 respectively.
	GPIO A4 is LCD EN and GPIO A5 is the LCD RS pin.<br>
	Note that these GPIO pins are *not* 5 V tolerant. So they are installed with
	physical pull-down resistors to ground to protect the GPIO pins on the STM32F030
	from 5 V from the LCD. The pins are configured as outputs in a push-pull
	configuration.
+ ```void LCD_cmd( uint8_t data )```<br>
	Send a 1-byte command to the LCD.
+ ```void LCD_putc( char data )```<br>
	Send a character to the LCD.
+ ```void LCD_puts( char *data )```<br>
	Takes a pointer to a null-terminated string and displays that string
	from the current LCD cursor position. Does not check for LCD line/string
	overflow.
