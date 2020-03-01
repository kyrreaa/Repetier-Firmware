/*****************************************************************
 * Experimental CoreXYZ Due Board by Kyrre Aalerud
 ******************************************************************/
#ifndef __SAM3X8E__
#error Oops!  Make sure you have 'Arduino Due' selected from the 'Tools -> Boards' menu.
#endif

//#define KNOWN_BOARD
#define CPU_ARCH ARCH_ARM

#define HEATER_PINS_INVERTED 1

/*****************************************************************
* Arduino Due Pin Assignments
******************************************************************/
#define ORIG_X_STEP_PIN 63
#define ORIG_X_DIR_PIN 62
#define ORIG_X_MIN_PIN 22
#define ORIG_X_MAX_PIN 30
#define ORIG_X_ENABLE_PIN 48

#define ORIG_Y_STEP_PIN 65
#define ORIG_Y_DIR_PIN 64
#define ORIG_Y_MIN_PIN 24
#define ORIG_Y_MAX_PIN 38
#define ORIG_Y_ENABLE_PIN 46

#define ORIG_Z_STEP_PIN 67
#define ORIG_Z_DIR_PIN 66
#define ORIG_Z_MIN_PIN 26
#define ORIG_Z_MAX_PIN 34
#define ORIG_Z_ENABLE_PIN 44

// Use E2 (third extruder) as 4'th motor
#define ORIG_A_STEP_PIN 32
#define ORIG_A_DIR_PIN 47
#define ORIG_A_MIN_PIN -1
#define ORIG_A_MAX_PIN -1
#define ORIG_A_ENABLE_PIN 45

#define HEATER_0_PIN 8
// Due analog pin #54
#define TEMP_0_PIN 7
//#define TEMP_0_PIN 4

#define HEATER_1_PIN 9
// Due analog pin #55
#define TEMP_1_PIN 6
//#define TEMP_1_PIN 5

#define HEATER_2_PIN 10
// Due analog pin #56
#define TEMP_2_PIN 5
//#define TEMP_2_PIN 6

#define HEATER_3_PIN 11
// Due analog pin #57
//#define TEMP_3_PIN 4
#define TEMP_3_PIN 3

#define ORIG_E0_STEP_PIN 36
#define ORIG_E0_DIR_PIN 28
#define ORIG_E0_ENABLE_PIN 42

#define ORIG_E1_STEP_PIN 43
#define ORIG_E1_DIR_PIN 41
#define ORIG_E1_ENABLE_PIN 39

#define ORIG_E2_STEP_PIN -1
#define ORIG_E2_DIR_PIN -1
#define ORIG_E2_ENABLE_PIN -1

#define SDSUPPORT 1
#define SDPOWER -1
// 4,10,52 if using HW SPI.
#define SDSS 4
#define ORIG_SDCARDDETECT 14
#define SDCARDDETECTINVERTED 1
#define LED_PIN -1
#define ORIG_FAN_PIN 11
#define ORIG_FAN2_PIN -1
#define ORIG_PS_ON_PIN -1
#define KILL_PIN -1
#define SUICIDE_PIN -1 //PIN that has to be turned on right after start, to keep power flowing.

#define SDA_PIN 20 // 20 or 70
#define SCL_PIN 21 // 21 or 71

#ifndef CUSTOM_CONTROLLER_PINS
// Controller related default pins
#define BEEPER_PIN -1
#define UI_DISPLAY_RS_PIN -1
#define UI_DISPLAY_ENABLE_PIN -1
#define UI_DISPLAY_D4_PIN -1
#define UI_DISPLAY_D5_PIN -1
#define UI_ENCODER_A -1
#define UI_ENCODER_B -1
#define UI_ENCODER_CLICK -1
#define UI_RESET_PIN -1
#define UI_BACK_PIN -1
#endif

#define E0_PINS ORIG_E0_STEP_PIN, ORIG_E0_DIR_PIN, ORIG_E0_ENABLE_PIN,
#define E1_PINS ORIG_E1_STEP_PIN, ORIG_E1_DIR_PIN, ORIG_E1_ENABLE_PIN,
#define E2_PINS ORIG_E2_STEP_PIN, ORIG_E2_DIR_PIN, ORIG_E2_ENABLE_PIN,

#define TWI_CLOCK_FREQ 100000
// see eeprom device data sheet for the following values these are for 24xx256
#define EEPROM_SERIAL_ADDR 0x50  // 7 bit i2c address (without R/W bit)
#define EEPROM_PAGE_SIZE 64      // page write buffer size
#define EEPROM_PAGE_WRITE_TIME 7 // page write time in milliseconds (docs say 5ms but that is too short)
// specify size of eeprom address register
// TWI_MMR_IADRSZ_1_BYTE for 1 byte, or TWI_MMR_IADRSZ_2_BYTE for 2 byte
#define EEPROM_ADDRSZ_BYTES TWI_MMR_IADRSZ_2_BYTE
#define EEPROM_AVAILABLE EEPROM_I2C
