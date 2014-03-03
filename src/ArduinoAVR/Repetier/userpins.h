#define KNOWN_BOARD
/*****************************************************************
* ArxPrint Pin Assignments
******************************************************************/

#ifndef __AVR_ATmega2560__
#error Oops!  Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu.
#endif

#define X_STEP_PIN     81  // PJ4
#define X_DIR_PIN      33  // PC4
#define X_MIN_PIN      -1  // PK2 (64)
#define X_MAX_PIN      65  // PK3
#define X_ENABLE_PIN   26  // PA4
//#define X_MS1_PIN      -1
//#define X_MS2_PIN      -1

#define Y_STEP_PIN     87  // PJ3
#define Y_DIR_PIN      34  // PC3
#define Y_MIN_PIN      -1  // PK4 (66)
#define Y_MAX_PIN      67  // PK5
#define Y_ENABLE_PIN   25  // PA3
//#define Y_MS1_PIN      69
//#define Y_MS2_PIN      39

#define Z_STEP_PIN     80  // PJ2
#define Z_DIR_PIN      35  // PC2
#define Z_MIN_PIN      -1  // PK6 (68)
#define Z_MAX_PIN      69  // PK7
#define Z_ENABLE_PIN   24  // PA2
//#define Z_MS1_PIN      68
//#define Z_MS2_PIN      67

#define HEATER_BED_PIN 46  // PL3
#define TEMP_BED_PIN   0 

#define HEATER_0_PIN   45  // PL4
#define TEMP_0_PIN     1

#define HEATER_1_PIN   44  // PL5
#define TEMP_1_PIN     2

#define HEATER_2_PIN   -1
#define TEMP_2_PIN     -1

#define E0_STEP_PIN    14  // PJ1
#define E0_DIR_PIN     36  // PC1
#define E0_ENABLE_PIN  23  // PA1
//#define E0_MS1_PIN     65
//#define E0_MS2_PIN     66

#define E1_STEP_PIN    15  // PJ0
#define E1_DIR_PIN     37  // PC0
#define E1_ENABLE_PIN  22  // PA0
//#define E1_MS1_PIN     63
//#define E1_MS2_PIN     64

//#define DIGIPOTSS_PIN  38
//#define DIGIPOT_CHANNELS {4,5,3,0,1} // X Y Z E0 E1 digipot channels to stepper driver mapping

#define SDPOWER        -1
#define SDSS           53  // PB0
#define LED_PIN        13  // PB7
#define FAN_PIN         6  // PH3 aka Servo 0
#define PS_ON_PIN       7  // PH4 aka Servo 1
#define KILL_PIN       -1
#define SUICIDE_PIN    -1  //PIN that has to be turned on right after start, to keep power flowing.

#define E0_PINS E0_STEP_PIN,E0_DIR_PIN,E0_ENABLE_PIN,
#define E1_PINS E1_STEP_PIN,E1_DIR_PIN,E1_ENABLE_PIN,

#define SCK_PIN          52  // PB1
#define MISO_PIN         50  // PB3
#define MOSI_PIN         51  // PB2
//#define MAX6675_SS       53

#define PROBE_PIN  8  // PH5
#define SERVO1_PIN  9  // PH6
