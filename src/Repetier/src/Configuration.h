/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/**************** READ FIRST ************************

   This configuration file was created with the configuration tool. For that
   reason, it does not contain the same informations as the original Configuration.h file.
   It misses the comments and unused parts. Open this file file in the config tool
   to see and change the data. You can also upload it to newer/older versions. The system
   will silently add new options, so compilation continues to work.

   This file is optimized for version 1.0.0dev
   generator: http://www.repetier.com/firmware/dev/

   If you are in doubt which named functions use which pins on your board, please check the
   pins.h for the used name->pin assignments and your board documentation to verify it is
   as you expect.

*/

#define FAST_COREXYZ // need to use non linear solution to get xyz->abcd transform

// The follwing variables are required early to decide on the right modules.
#define NUM_SERVOS 0 // Number of serves available
#define NUM_TOOLS 1
#define NUM_EXTRUDER 1
#define MOTHERBOARD MOTHERBOARD_USER_DEFINED_DUE // Use "userpins.h"
#define EEPROM_MODE EEPROM_I2C
#define USE_CONFIGURATION_BAUD_RATE 1
#define RFSERIAL Serial
#define WAITING_IDENTIFIER "wait"
#define JSON_OUTPUT 1
#define FEATURE_SERVO 1
#define FEATURE_WATCHDOG 1
#define FEATURE_AUTOLEVEL 1
#define FEATURE_Z_PROBE 0
#define FEATURE_RETRACTION 1
#define NUM_AXES 5                   // X,Y,Z and E for extruder A,B,C would be 5,6,7
#define STEPPER_FREQUENCY 100000     // Maximum stepper frequency.
#define PREPARE_FREQUENCY 1000       // Update frequency for new blocks. Must be higher then PREPARE_FREQUENCY.
#define BLOCK_FREQUENCY 500          // Number of blocks with constant stepper rate per second.
#define VELOCITY_PROFILE 2           // 0 = linear, 1 = cubic, 2 = quintic velocity shape
#define Z_SPEED 150                  // Z positioning speed
#define XY_SPEED 150                 // XY positioning speed for normal operations
#define A_SPEED 150                  // A positioning speed
#define E_SPEED 2                    // Extrusion speed
#define G0_FEEDRATE 0                // Speed for G0 moves. Independent from set F value! Set 0 to use F value.
#define MAX_ROOM_TEMPERATURE 25      // No heating below this temperature!
#define TEMPERATURE_CONTROL_RANGE 20 // Start with controlling if temperature is +/- this value to target temperature
#define HOST_RESCUE 0                // Enable host rescue help system
//#define DEBUG_RESCUE                 // Uncomment to add power loss entry in debug menu while printing
#define POWERLOSS_LEVEL 0     // How much time do we have on powerloss, 0 = no move, 1 = short just raise Z, 2 = long full park move
#define POWERLOSS_UP 5        // How much to move up if mode 1 is active
#define Z_PROBE_TYPE 1        // 0 = no z probe, 1 = default z probe, 2 = Nozzle as probe
#define Z_PROBE_BORDER 2      // Safety border to ensure position is allowed
#define Z_PROBE_TEMPERATURE 0 // Temperature for type 2

//#define EXTERNALSERIAL  use Arduino serial library instead of build in. Requires more ram, has only 63 byte input buffer.
// Uncomment the following line if you are using Arduino compatible firmware made for Arduino version earlier then 1.0
// If it is incompatible you will get compiler errors about write functions not being compatible!
//#define COMPAT_PRE1
#define BLUETOOTH_SERIAL 1
#define BLUETOOTH_BAUD 250000

// 0 = Cartesian, 1 = CoreXYZ, 2 = delta, 3 = Dual X-Axis
#define PRINTER_TYPE PRINTER_TYPE_CORE_XYZ
// steps to include as babysteps per 1/BLOCK_FREQUENCY seconds. Must be lower then STEPPER_FREQUENCY/BLOCK_FREQUENCY and be low enough to not loose steps.
#define BABYSTEPS_PER_BLOCK \
    { 10, 10, 10, 10, 10}
// If all axis end stops are hardware based we can skip the time consuming tests each step
#define NO_SOFTWARE_AXIS_ENDSTOPS
// Normally only a delta has motor end stops required. Normally you trigger using axis endstops.
#define NO_MOTOR_ENDSTOPS

#define FEATURE_CONTROLLER CONTROLLER_NONE
// Use more memory to speedup display updates
#define DISPLAY_FULL_BUFFER 1
// Direction 1 or -1
#define ENCODER_DIRECTION -1
// Encoder speed 0 = fastest, 1 or 2 = slowest - set so 1 click is one menu move
// Default is 2 if not set by controller. Us eonly to fix wrong setting
// #define ENCODER_SPEED 2

/* Ratios for core xyz. First index denotes motor and second axis.
For each motor you can set the ratio of x,y,z position that adds
to the position. 0 = no contribution. */
// X motor = x + y + z
#define COREXYZ_X_X 1
#define COREXYZ_X_Y 1
#define COREXYZ_X_Z 1
// Y motor = x - y - z
#define COREXYZ_Y_X 1
#define COREXYZ_Y_Y -1
#define COREXYZ_Y_Z -1
// Z motor = z - x - y
#define COREXYZ_Z_X -1
#define COREXYZ_Z_Y -1
#define COREXYZ_Z_Z 1
// A motor = y - x - z
#define COREXYZ_A_X -1
#define COREXYZ_A_Y 1
#define COREXYZ_A_Z -1

#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 0

// Next 7 lines are required to make the following work, do not change!
#include "boards/pins.h"
#undef IO_TARGET
#define IO_TARGET 4
#undef CONFIG_EXTERN
#define CONFIG_EXTERN extern
#include "drivers/drivers.h"
#include "io/redefine.h"

// Define ZProbe by referencing a endstop defined
CONFIG_VARIABLE_EQ(EndstopDriver, *ZProbe, &zProbeInput)
//CONFIG_VARIABLE_EQ(EndstopDriver, *ZProbe, 0)

/** Axes are homed in order of priority (0..10) if homing direction is not 0. */
#define Z_HOME_PRIORITY 0
#define X_HOME_PRIORITY 1
#define Y_HOME_PRIORITY 2
#define A_HOME_PRIORITY 3

// All fans in this list list become controllable with M106/M107
// by selecteing the fan number with P0..P<NUM_FANS-1>
#define NUM_FANS 2
#define FAN_LIST \
    { &Fan1PWM, &Fan2PWM }

#define NUM_HEATED_BEDS 0
#define HEATED_BED_LIST \
    {}
//    { &HeatedBed1 }

#define NUM_HEATED_CHAMBERS 0
#define HEATED_CHAMBER_LIST \
    {}

#define SERVO_LIST \
    {}
//    { &Servo1 }
#define TOOLS \
    { &ToolExtruder0 } //, &ToolExtruder1, &ToolExtruder2 }

// Heaters enumerate all heaters, so we can loop over them
// or call commands on a specific heater number.
// Suggested order: extruder heaters, heated beds, heated chambers, additional heaters
#define NUM_HEATERS 1
#define HEATERS \
    { &HeaterExtruder0 }
//    { &HeatedBed1, &HeaterExtruder0, &HeaterExtruder1, &HeaterExtruder2 }

// Array to call motor related commands like microstepping/current if supported.
// Id's start at 0 and depend on position in this array.
#define NUM_MOTORS 4
#define MOTORS \
    { &XMotor, &YMotor, &ZMotor, &AMotor }
#define MOTOR_NAMES \
    { PSTR("A"), PSTR("B"), PSTR("C"), PSTR("D") }

#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR 1
#define A_HOME_DIR 0
#define X_MAX_LENGTH 416
#define Y_MAX_LENGTH 410
#define Z_MAX_LENGTH 340
#define A_MAX_LENGTH 500
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define A_MIN_POS 0
#define BED_X_MIN X_MIN_POS
#define BED_X_MAX (X_MIN_POS + X_MAX_LENGTH)
#define BED_Y_MIN Y_MIN_POS
#define BED_Y_MAX (Y_MIN_POS + Y_MAX_LENGTH)

// Park position used when pausing from firmware side
#if PRINTER_TYPE == 2
#define PARK_POSITION_X (0)
#define PARK_POSITION_Y (70)
#else
#define PARK_POSITION_X (X_MIN_POS)
#define PARK_POSITION_Y (Y_MIN_POS + Y_MAX_LENGTH)
#endif
#define PARK_POSITION_Z_RAISE 10

#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 500
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 500
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 500
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_A 500
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 500
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 500
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 500
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_A 500
#define XAXIS_STEPS_PER_MM 320
#define YAXIS_STEPS_PER_MM 320
#define ZAXIS_STEPS_PER_MM 320
#define AAXIS_STEPS_PER_MM 320

// ################## EDIT THESE SETTINGS MANUALLY ################
// ################ END MANUAL SETTINGS ##########################

#undef FAN_BOARD_PIN
#define FAN_BOARD_PIN -1
#define BOARD_FAN_SPEED 255
#define BOARD_FAN_MIN_SPEED 0
#define FAN_THERMO_PIN -1
#define FAN_THERMO_MIN_PWM 128
#define FAN_THERMO_MAX_PWM 255
#define FAN_THERMO_MIN_TEMP 45
#define FAN_THERMO_MAX_TEMP 60
#define FAN_THERMO_THERMISTOR_PIN -1
#define FAN_THERMO_THERMISTOR_TYPE 1

#define MIXING_EXTRUDER 0

#define DRIVE_SYSTEM XYZ_GANTRY
#define EXTRUDER_FAN_COOL_TEMP 50
#define KILL_IF_SENSOR_DEFECT 0
#define RETRACT_ON_PAUSE 2
#define PAUSE_START_COMMANDS ""
#define PAUSE_END_COMMANDS ""
#define SHARED_EXTRUDER_HEATER 0

#define AUTORETRACT_ENABLED 0
#define RETRACTION_LENGTH 3
#define RETRACTION_LONG_LENGTH 13
#define RETRACTION_SPEED 40
#define RETRACTION_Z_LIFT 0
#define RETRACTION_UNDO_EXTRA_LENGTH 0
#define RETRACTION_UNDO_EXTRA_LONG_LENGTH 0
#define RETRACTION_UNDO_SPEED 25
#define FILAMENTCHANGE_X_POS 5
#define FILAMENTCHANGE_Y_POS 5
#define FILAMENTCHANGE_Z_ADD 2
#define FILAMENTCHANGE_REHOME 0
#define FILAMENTCHANGE_SHORTRETRACT 0
#define FILAMENTCHANGE_LONGRETRACT 0
#define JAM_METHOD 1
#define JAM_STEPS 220
#define JAM_SLOWDOWN_STEPS 1000
#define JAM_SLOWDOWN_TO 75
#define JAM_ERROR_STEPS 1500
#define JAM_MIN_STEPS 10
#define JAM_ACTION 1

#define RETRACT_DURING_HEATUP false
#define PID_CONTROL_RANGE 20
#define SKIP_M109_IF_WITHIN 5
#define SCALE_PID_TO_MAX 0
#define TEMP_HYSTERESIS 0
#define EXTRUDE_MAXLENGTH 200

#define HEATER_PWM_SPEED 0
#define COOLER_PWM_SPEED 0

// ############# Heated bed configuration ########################

#define SKIP_M190_IF_WITHIN 5
#define MIN_EXTRUDER_TEMP 150
#define MILLISECONDS_PREHEAT_TIME 30000

// ##                              CNC configuration                                       ##

/*
If the firmware is in CNC mode, it can control a mill with M3/M4/M5. It works
similar to laser mode, but mill keeps enabled during G0 moves and it allows
setting rpm (only with event extension that supports this) and milling direction.
It also can add a delay to wait for spindle to run on full speed.
*/

#define SUPPORT_CNC 0
#define CNC_WAIT_ON_ENABLE 300
#define CNC_WAIT_ON_DISABLE 0
#define CNC_ENABLE_PIN -1
#define CNC_ENABLE_WITH 1
#define CNC_DIRECTION_PIN -1
#define CNC_DIRECTION_CW 1
#define CNC_PWM_MAX 255
#define CNC_RPM_MAX 8000
#define CNC_SAFE_Z 150

#define DEFAULT_PRINTER_MODE 0

// ################ Endstop configuration #####################

#define DOOR_PIN -1
#define DOOR_PULLUP 1
#define DOOR_INVERTING 1
#define ENDSTOP_X_BACK_MOVE 5
#define ENDSTOP_Y_BACK_MOVE 5
#define ENDSTOP_Z_BACK_MOVE 5
#define ENDSTOP_A_BACK_MOVE 0
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 4
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 4
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 4
#define ENDSTOP_A_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_X_BACK_ON_HOME 2
#define ENDSTOP_Y_BACK_ON_HOME 2
#define ENDSTOP_Z_BACK_ON_HOME 2
#define ENDSTOP_A_BACK_ON_HOME 0
#define ALWAYS_CHECK_ENDSTOPS 1
#define MOVE_X_WHEN_HOMED 0
#define MOVE_Y_WHEN_HOMED 0
#define MOVE_Z_WHEN_HOMED 0

// ################# XYZ movements ###################

#define PREVENT_Z_DISABLE_ON_STEPPER_TIMEOUT 0

// ##########################################################################################
// ##                           Movement settings                                          ##
// ##########################################################################################

#define FEATURE_BABYSTEPPING 1
#define BABYSTEP_MULTIPLICATOR 64

// Delta settings
#define DELTA_HOME_ON_POWER 0

#define STEPPER_INACTIVE_TIME 360L
#define MAX_INACTIVE_TIME 1200L
#define MAX_FEEDRATE_X 250
#define MAX_FEEDRATE_Y 250
#define MAX_FEEDRATE_Z 250
#define MAX_FEEDRATE_A 250
#define HOMING_FEEDRATE_X 80
#define HOMING_FEEDRATE_Y 80
#define HOMING_FEEDRATE_Z 80
#define HOMING_FEEDRATE_A 80
// Raise z before homing (1)
#define ZHOME_PRE_RAISE 0
// How much mm should z raise before homing
#define ZHOME_PRE_RAISE_DISTANCE 2
#define ZHOME_MIN_TEMPERATURE 0
#define ZHOME_HEAT_ALL 0
// Height in mm after homing.
#define ZHOME_HEIGHT 340 // 0 Disables move down to home. Maybe it assumes homing was done to z0?
// Home Z at a fixed xy position (1)
#define FIXED_Z_HOME_POSITION 0
#define ZHOME_X_POS 140
#define ZHOME_Y_POS 45
// Raise extruders before switching tools. Used to prevent touching objects while switching.
#define RAISE_Z_ON_TOOLCHANGE 2

#define ENABLE_BACKLASH_COMPENSATION 0
#define X_BACKLASH 0
#define Y_BACKLASH 0
#define Z_BACKLASH 0
#define DIRECTION_DELAY 0
#define MAX_JERK 5
#define MAX_ZJERK 0.3
#define PRINTLINE_CACHE_SIZE 32
#define MOVE_CACHE_LOW 10
#define LOW_TICKS_PER_MOVE 250000
#define EXTRUDER_SWITCH_XY_SPEED 100
#define FEATURE_DITTO_PRINTING 0

#define MAX_AJERK 0.3

// ################# Misc. settings ##################

#define BAUDRATE 250000
#define ENABLE_POWER_ON_STARTUP 1
#define POWER_INVERTING 0
#define KILL_METHOD 1
#define ACK_WITH_LINENUMBER 1
#define KEEP_ALIVE_INTERVAL 2000
#define ECHO_ON_EXECUTE 1
#undef PS_ON_PIN
#define PS_ON_PIN -1

// #################### Z-Probing #####################

#define Z_PROBE_COATING 0
#define Z_PROBE_Z_OFFSET_MODE 1
#define UI_BED_COATING 1
#define EXTRUDER_IS_Z_PROBE 0
#define Z_PROBE_DISABLE_HEATERS 1
#define Z_PROBE_BED_DISTANCE 3
#define Z_PROBE_X_OFFSET 0
#define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_SPEED 5
#define Z_PROBE_SWITCHING_DISTANCE 2
// How often should we test a position 1 .. x. Averages result over all tests.
#define Z_PROBE_REPETITIONS 1
// 0 = use average, 1 = use middle value after ordering z
#define Z_PROBE_USE_MEDIAN 0
// Nozzle distance to bed when z probe triggers
#define Z_PROBE_HEIGHT -0.15
// Delay in ms before we go down again. For BLTouch so signal can disable
#define Z_PROBE_DELAY 0
#define Z_PROBE_START_SCRIPT ""
#define Z_PROBE_FINISHED_SCRIPT ""
#define Z_PROBE_RUN_AFTER_EVERY_PROBE ""
#define Z_PROBE_REQUIRES_HEATING 0
#define Z_PROBE_MIN_TEMPERATURE 0

// How to correct rotated beds
// 0 = Software side by rotating coordinates
// 1 = Move bed physically using 2 motors
#define LEVELING_CORRECTOR 0
// Bed fixture coordinates for motor leveling
#define LC_P1_X 55
#define LC_P1_Y 130
#define LC_P2_X 137
#define LC_P2_Y 45
#define LC_P3_X 137
#define LC_P3_Y 210
#define LC_P2_MOTOR AL1Motor
#define LC_P3_MOTOR AL2Motor
#define LC_STEPS_PER_MM 3382
#define LC_Z_SPEED 0.2
// > 0 will move bed down and wait for removal (heater removed) and will pause another LC_WAIT_BED_REMOVE seconds
#define LC_WAIT_BED_REMOVE 2
// Uncomment to limit correction per autoleveling iteration. Value is the max. correction in mm
// #define LIMIT_MOTORIZED_CORRECTION 0.5

// Leveling method
// 0 = none, 3 = 3 points, 1 = grid, 2 = 4 point symmetric
#define LEVELING_METHOD 2
#define L_P1_X 60
#define L_P1_Y 130
#define L_P2_X 137
#define L_P2_Y 45
#define L_P3_X 137
#define L_P3_Y 210
#define GRID_SIZE 5
#define ENABLE_BUMP_CORRECTION 1          // CPU intensive, so only activate if required
#define BUMP_CORRECTION_START_DEGRADE 0.5 // Until this height we correct 100%
#define BUMP_CORRECTION_END_HEIGHT 2      // From this height on we do no correction
#define BUMP_LIMIT_TO 0                   // Maximum allowed correction up/down, <= 0 off.

#define BENDING_CORRECTION_A 0
#define BENDING_CORRECTION_B 0
#define BENDING_CORRECTION_C 0
#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0

#ifndef SDSUPPORT // Some boards have sd support on board. These define the values already in pins.h
#define SDSUPPORT 1
#undef SDCARDDETECT
#define SDCARDDETECT ORIG_SDCARDDETECT
#define SDCARDDETECTINVERTED 0
#endif
#define SD_EXTENDED_DIR 1 /** Show extended directory including file length. Don't use this with Pronterface! */
#define SD_RUN_ON_STOP ""
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1
#define ARC_SUPPORT 0
#define FEATURE_MEMORY_POSITION 1
#define FEATURE_CHECKSUM_FORCED 0
#define FEATURE_FAN_CONTROL 1
#define FEATURE_FAN2_CONTROL 0
#define ADC_KEYPAD_PIN -1
#define LANGUAGE_EN_ACTIVE 1
#define LANGUAGE_DE_ACTIVE 0
#define LANGUAGE_NL_ACTIVE 0
#define LANGUAGE_PT_ACTIVE 0
#define LANGUAGE_IT_ACTIVE 0
#define LANGUAGE_ES_ACTIVE 0
#define LANGUAGE_FI_ACTIVE 0
#define LANGUAGE_SE_ACTIVE 0
#define LANGUAGE_FR_ACTIVE 0
#define LANGUAGE_CZ_ACTIVE 0
#define LANGUAGE_PL_ACTIVE 0
#define LANGUAGE_TR_ACTIVE 0
#define UI_PRINTER_NAME "Core-XYZ"
#define UI_PRINTER_COMPANY "Aalerud Produktutvikling"
#define UI_PAGES_DURATION 4000
#define UI_SPEEDDEPENDENT_POSITIONING 0
#define UI_DISABLE_AUTO_PAGESWITCH 1
#define UI_AUTORETURN_TO_MENU_AFTER 30000
#define FEATURE_UI_KEYS 0
#define UI_ENCODER_SPEED 2
#define UI_REVERSE_ENCODER 0
#define UI_KEY_BOUNCETIME 10
#define UI_KEY_FIRST_REPEAT 500
#define UI_KEY_REDUCE_REPEAT 50
#define UI_KEY_MIN_REPEAT 50
#define FEATURE_BEEPER 0
#define CASE_LIGHTS_PIN 25
#define CASE_LIGHT_DEFAULT_ON 1
#define UI_START_SCREEN_DELAY 2000
#define UI_DYNAMIC_ENCODER_SPEED 1
#define UI_HEAD "E1:%e0\002C E2:%e1\002C B:%eb\002C"
/**
Beeper sound definitions for short beeps during key actions
and longer beeps for important actions.
Parameter is delay in microseconds and the secons is the number of repetitions.
Values must be in range 1..255
*/
#define BEEPER_SHORT_SEQUENCE 2, 2
#define BEEPER_LONG_SEQUENCE 8, 8
#define UI_SET_MIN_HEATED_BED_TEMP 30
#define UI_SET_MAX_HEATED_BED_TEMP 120
#define UI_SET_MIN_EXTRUDER_TEMP 80
#define UI_SET_MAX_EXTRUDER_TEMP 275
#define UI_SET_EXTRUDER_FEEDRATE 5
#define UI_SET_EXTRUDER_RETRACT_DISTANCE 3

//#define CUSTOM_EVENTS
//#define CUSTOM_MENU
//#define CUSTOM_TRANSLATIONS
#define HALFAUTOMATIC_LEVELING 1
// add z probe height routine
#define ZPROBE_HEIGHT_ROUTINE
#define ZPROBE_REF_HEIGHT 5.97
#define Z_UP_AFTER_HOME 0

#endif
