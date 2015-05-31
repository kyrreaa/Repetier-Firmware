#define KNOWN_BOARD
/*****************************************************************
* ArxPrint Pin Assignments
******************************************************************/

#ifndef __AVR_ATmega2560__
#error Oops!  Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu.
#endif

/*
// FastIO stuff:
#define DIO80_PIN		PINJ2
#define DIO80_RPORT		PINJ
#define DIO80_WPORT		PORTJ
#define DIO80_DDR		DDRJ
#define DIO80_PWM		NULL

#define DIO81_PIN		PINJ4
#define DIO81_RPORT		PINJ
#define DIO81_WPORT		PORTJ
#define DIO81_DDR		DDRJ
#define DIO81_PWM		NULL

#define DIO82_PIN		PINJ5
#define DIO82_RPORT		PINJ
#define DIO82_WPORT		PORTJ
#define DIO82_DDR		DDRJ
#define DIO82_PWM		NULL

#define DIO83_PIN		PINJ6
#define DIO83_RPORT		PINJ
#define DIO83_WPORT		PORTJ
#define DIO83_DDR		DDRJ
#define DIO83_PWM		NULL

#define DIO84_PIN		PINJ7
#define DIO84_RPORT		PINJ
#define DIO84_WPORT		PORTJ
#define DIO84_DDR		DDRJ
#define DIO84_PWM		NULL

#define DIO85_PIN		PINH7
#define DIO85_RPORT		PINH
#define DIO85_WPORT		PORTH
#define DIO85_DDR		DDRH
#define DIO85_PWM		NULL

#define DIO86_PIN		PINH2
#define DIO86_RPORT		PINH
#define DIO86_WPORT		PORTH
#define DIO86_DDR		DDRH
#define DIO86_PWM		NULL

#define DIO90_PIN		PINE7
#define DIO90_RPORT		PINE
#define DIO90_WPORT		PORTE
#define DIO90_DDR		DDRE
#define DIO90_PWM		NULL

#define DIO91_PIN		PINE2
#define DIO91_RPORT		PINE
#define DIO91_WPORT		PORTE
#define DIO91_DDR		DDRE
#define DIO91_PWM		NULL

#define DIO92_PIN		PIND4
#define DIO92_RPORT		PIND
#define DIO92_WPORT		PORTD
#define DIO92_DDR		DDRD
#define DIO92_PWM		NULL

#define DIO93_PIN		PIND5
#define DIO93_RPORT		PIND
#define DIO93_WPORT		PORTD
#define DIO93_DDR		DDRD
#define DIO93_PWM		NULL

#define DIO94_PIN		PIND6
#define DIO94_RPORT		PIND
#define DIO94_WPORT		PORTD
#define DIO94_DDR		DDRD
#define DIO94_PWM		NULL


*/

#define DIO87_PIN		PINJ3
#define DIO87_RPORT		PINJ
#define DIO87_WPORT		PORTJ
#define DIO87_DDR		DDRJ
#define DIO87_PWM		NULL

// Pin defs
#define ORIG_X_STEP_PIN     75  // PJ4
#define ORIG_X_DIR_PIN      33  // PC4
#define ORIG_X_MIN_PIN      64  // PK2
#define ORIG_X_MAX_PIN      65  // PK3
#define ORIG_X_ENABLE_PIN   26  // PA4

#define ORIG_Y_STEP_PIN     87  // PJ3
#define ORIG_Y_DIR_PIN      34  // PC3
#define ORIG_Y_MIN_PIN      66  // PK4
#define ORIG_Y_MAX_PIN      67  // PK5
#define ORIG_Y_ENABLE_PIN   25  // PA3

#define ORIG_Z_STEP_PIN     72  // PJ2
#define ORIG_Z_DIR_PIN      35  // PC2
#define ORIG_Z_MIN_PIN      68  // PK6
#define ORIG_Z_MAX_PIN      69  // PK7
#define ORIG_Z_ENABLE_PIN   24  // PA2


#define TEMP_0_PIN	0	// PF0 ADC0 Normally Extruder 0
#define TEMP_1_PIN	3	// PF3 ADC3 Normally Heated bed
#define TEMP_2_PIN	1	// PF1 ADC1 Normally Extruder 1
#define TEMP_3_PIN	2	// PF2 ADC2 Normally Extruder 2
#define TEMP_4_PIN	8	// PK0 ADC8
#define TEMP_5_PIN	9	// PK1 ADC9

#define HEATER_0_PIN	45  // PL4
#define HEATER_1_PIN	46  // PL3
#define HEATER_2_PIN	44  // PL5
#define HEATER_3_PIN	12  // PB4 Expanded, using external transistor on Encoder port, pin 2

#define ORIG_E0_STEP_PIN    14  // PJ1
#define ORIG_E0_DIR_PIN     36  // PC1
#define ORIG_E0_ENABLE_PIN  23  // PA1

#define ORIG_E1_STEP_PIN    15  // PJ0
#define ORIG_E1_DIR_PIN     37  // PC0
#define ORIG_E1_ENABLE_PIN  22  // PA0

#define ORIG_E2_STEP_PIN    6	// PH3
#define ORIG_E2_DIR_PIN     7	// PH4
#define ORIG_E2_ENABLE_PIN	8	// PH5

//#define DIGIPOTSS_PIN  38
//#define DIGIPOT_CHANNELS {4,5,3,0,1} // X Y Z E0 E1 digipot channels to stepper driver mapping

#define SDPOWER        -1
#define SDSS           53  // PB0
#define LED_PIN        13  // PB7
#define ORIG_FAN_PIN         6  // PH3 aka Servo 0
#define ORIG_PS_ON_PIN       7  // PH4 aka Servo 1
#define KILL_PIN       -1
#define SUICIDE_PIN    -1  //PIN that has to be turned on right after start, to keep power flowing.

#define E0_PINS E0_STEP_PIN,E0_DIR_PIN,E0_ENABLE_PIN,
#define E1_PINS E1_STEP_PIN,E1_DIR_PIN,E1_ENABLE_PIN,
#define E2_PINS E2_STEP_PIN,E2_DIR_PIN,E2_ENABLE_PIN,

#define SCK_PIN          52  // PB1
#define MISO_PIN         50  // PB3
#define MOSI_PIN         51  // PB2

#define PROBE_PIN  9  // PH6
//#define SERVO1_PIN  9  // PH6 (Needed for extra stepper)
