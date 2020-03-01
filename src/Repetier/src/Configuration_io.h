/*

This file defines io solutions used. This is the lowest level and is the base
for all higher level functions using io operations. At several places we need
subsets of these list of operations. To make configuration easy and easy to 
understand, we use a technique called "x macros". This requires that only
predefined macro names for IO are used here. Do NOT add anything else here
or compilation/functionality will break.

Rules:
1. Each definition will create a class that is named like the first parameter.
This class is later used as input to templates building higher functions. By
convention the names should start with IO followed by something that helps you
identify the function. 
2. Do not use a semicolon at the end. Macro definition gets different meanings
and will add the semicolon if required.

*/

/* Define motor pins here. Each motor needs a setp, dir and enable pin. */

ENDSTOP_NONE(endstopNone)
// For use when no output is wanted, but possible
IO_OUTPUT_FAKE(fakeOut)

// X Motor

IO_OUTPUT(IOX1Step, ORIG_X_STEP_PIN)
IO_OUTPUT(IOX1Dir, ORIG_X_DIR_PIN)
IO_OUTPUT_INVERTED(IOX1Enable, ORIG_X_ENABLE_PIN)

// Y Motor

IO_OUTPUT(IOY1Step, ORIG_Y_STEP_PIN)
IO_OUTPUT(IOY1Dir, ORIG_Y_DIR_PIN)
IO_OUTPUT_INVERTED(IOY1Enable, ORIG_Y_ENABLE_PIN)

// Z Motor

IO_OUTPUT(IOZ1Step, ORIG_Z_STEP_PIN)
IO_OUTPUT(IOZ1Dir, ORIG_Z_DIR_PIN)
IO_OUTPUT_INVERTED(IOZ1Enable, ORIG_Z_ENABLE_PIN)

// A Motor

IO_OUTPUT(IOA1Step, ORIG_A_STEP_PIN)
IO_OUTPUT(IOA1Dir, ORIG_A_DIR_PIN)
IO_OUTPUT_INVERTED(IOA1Enable, ORIG_A_ENABLE_PIN)

// E0 Motor

IO_OUTPUT(IOE0Step, ORIG_E0_STEP_PIN)
IO_OUTPUT_INVERTED(IOE0Dir, ORIG_E0_DIR_PIN)
IO_OUTPUT_INVERTED(IOE0Enable, ORIG_E0_ENABLE_PIN)

// E1 Motor

IO_OUTPUT(IOE1Step, ORIG_E1_STEP_PIN)
IO_OUTPUT(IOE1Dir, ORIG_E1_DIR_PIN)
IO_OUTPUT_INVERTED(IOE1Enable, ORIG_E1_ENABLE_PIN)

// Servo output

//IO_OUTPUT(Servo1Pin, 5)

// Define your endstops inputs

IO_INPUT_INVERTED_PULLUP(IOEndstopXMin, ORIG_X_MIN_PIN)
IO_INPUT_INVERTED_PULLUP(IOEndstopYMin, ORIG_Y_MIN_PIN)
IO_INPUT_INVERTED_PULLUP(IOEndstopZMax, ORIG_Z_MAX_PIN)
IO_INPUT_PULLUP(IOZProbeInput, ORIG_Z_MIN_PIN)

//IO_INPUT(IOJam1, 35)
//IO_INPUT(IOJam2, 33)

// Controller input pins

#if UI_ENCODER_CLICK >= 0
IO_INPUT_INVERTED_PULLUP(ControllerClick, UI_ENCODER_CLICK)
#else
IO_INPUT_DUMMY(ControllerClick, false)
#endif
#if UI_ENCODER_A >= 0
IO_INPUT_INVERTED_PULLUP(ControllerEncA, UI_ENCODER_A)
#else
IO_INPUT_DUMMY(ControllerEncA, false)
#endif
#if UI_ENCODER_B >= 0
IO_INPUT_INVERTED_PULLUP(ControllerEncB, UI_ENCODER_B)
#else
IO_INPUT_DUMMY(ControllerEncB, false)
#endif
#if UI_BACK_PIN >= 0
IO_INPUT_PULLUP(ControllerBack, UI_BACK_PIN)
#else
IO_INPUT_DUMMY(ControllerBack, false)
#endif
#if UI_RESET_PIN >= 0
IO_INPUT_PULLUP(ControllerReset, UI_RESET_PIN)
#else
IO_INPUT_DUMMY(ControllerReset, false)
#endif

// Define our endstops solutions
// You need to define all min and max endstops for all
// axes except E even if you have none!

ENDSTOP_SWITCH_HW(endstopXMin, IOEndstopXMin, X_AXIS, false)
ENDSTOP_NONE(endstopXMax)
ENDSTOP_SWITCH_HW(endstopYMin, IOEndstopYMin, Y_AXIS, false)
ENDSTOP_NONE(endstopYMax)
ENDSTOP_NONE(endstopZMin)
ENDSTOP_SWITCH_HW(endstopZMax, IOEndstopZMax, Z_AXIS, true)
ENDSTOP_NONE(endstopAMin)
ENDSTOP_NONE(endstopAMax)

ENDSTOP_SWITCH_HW(zProbeInput, IOZProbeInput, Z_AXIS, false)

// Define fans

IO_OUTPUT(IOFan1, ORIG_FAN_PIN)
IO_PWM_SOFTWARE(Fan1NoKSPWM, IOFan1, 0)
// IO_PWM_HARDWARE(Fan1PWM, 37,5000)
// IO_PDM_SOFTWARE(Fan1NoKSPWM, IOFan1) // alternative to PWM signals
IO_PWM_KICKSTART(Fan1PWM, Fan1NoKSPWM, 20, 40)
// For debugging - reports new values and then calls real pwm
IO_PWM_REPORT(Fan1Report, Fan1PWM)

// Define temperature sensors
// Typically they require an analog input (12 bit) so define
// them first.

//IO_ANALOG_INPUT(IOAnalogBed1, TEMP_0_PIN, 5)
IO_ANALOG_INPUT(IOAnalogExt0, TEMP_3_PIN, 5)
//IO_ANALOG_INPUT(IOAnalogExt1, TEMP_2_PIN, 5)
//IO_ANALOG_INPUT(IOAnalogExt2, TEMP_3_PIN, 5)

// Need a conversion table for epcos NTC
IO_TEMP_TABLE_NTC(TempTableRAW, TABLE_RAW)

// Now create the temperature inputs

//IO_TEMPERATURE_TABLE(TempBed1, IOAnalogBed1, TempTableRAW)
IO_TEMPERATURE_TABLE(TempExt0, IOAnalogExt0, TempTableRAW)
//IO_TEMPERATURE_TABLE(TempExt1, IOAnalogExt1, TempTableRAW)
//IO_TEMPERATURE_TABLE(TempExt2, IOAnalogExt2, TempTableRAW)

// Use PWM outputs to heat. If using hardware PWM make sure
// that the selected pin can be used as hardware pwm otherwise
// select a software pwm model whcih works on all pins.

#if 1 //MOTHERBOARD == 998
IO_PWM_HARDWARE(PWMBed1x, HEATER_0_PIN, 100)
IO_PWM_HARDWARE(PWMExtruder0x, HEATER_1_PIN, 100)
IO_PWM_HARDWARE(PWMExtruder1x, HEATER_2_PIN, 100)
IO_PWM_HARDWARE(PWMExtruder2x, HEATER_3_PIN, 100)
IO_PWM_INVERTED(PWMBed1, PWMBed1x)
IO_PWM_INVERTED(PWMExtruder0, PWMExtruder0x)
IO_PWM_INVERTED(PWMExtruder1, PWMExtruder1x)
IO_PWM_INVERTED(PWMExtruder2, PWMExtruder2x)
#else
IO_OUTPUT_INVERTED(IOExtr1, HEATER_2_PIN)
//IO_OUTPUT(IOExtr2, HEATER_2_PIN)
//IO_OUTPUT(IOBed1, HEATER_1_PIN)
IO_PWM_SOFTWARE(PWMExtruder1, IOExtr1, 1)
//IO_PWM_INVERTED(PWMExtruder1_I, PWMExtruder1)
//IO_PWM_SOFTWARE(PWMExtruder2, IOExtr2, 1)
//IO_PWM_SOFTWARE(PWMBed1, IOBed1, 1)
#endif
// IO_OUTPUT(IOCooler1, FAN2_PIN)
// IO_PWM_SOFTWARE(PWMCoolerExt1, FAN2_PIN, 0)

// Define all stepper motors used
STEPPER_SIMPLE(XMotor, IOX1Step, IOX1Dir, IOX1Enable, endstopNone, endstopNone)
STEPPER_SIMPLE(YMotor, IOY1Step, IOY1Dir, IOY1Enable, endstopNone, endstopNone)
STEPPER_SIMPLE(ZMotor, IOZ1Step, IOZ1Dir, IOZ1Enable, endstopNone, endstopNone)
STEPPER_SIMPLE(AMotor, IOA1Step, IOA1Dir, IOA1Enable, endstopNone, endstopNone)
STEPPER_SIMPLE(E0MotorBase, IOE0Step, IOE0Dir, IOE0Enable, endstopNone, endstopNone)
//STEPPER_OBSERVEABLE(E1Motor, E1MotorBase)
STEPPER_SIMPLE(E1MotorBase, IOE1Step, IOE1Dir, IOE1Enable, endstopNone, endstopNone)
//STEPPER_OBSERVEABLE(E2Motor, E2MotorBase)
//STEPPER_SIMPLE(AL1Motor, IOAL1Step, IOAL1Dir, IOAL1Enable, endstopNone, endstopNone)
//STEPPER_SIMPLE(AL2Motor, IOAL2Step, IOAL2Dir, IOAL2Enable, endstopNone, endstopNone)

// Servos
//SERVO_ANALOG(Servo1, 0, Servo1Pin, 500, 2500, 1050)

// Heat manages are used for every component that needs to
// control temperature. Higher level classes take these as input
// and simple heater like a heated bed use it directly.

//HEAT_MANAGER_PID(HeatedBed1, 'B', 0, TempBed1, PWMBed1, 120, 255, 5, 30000, 12.0, 33.0, 290.0, 80, 255, true)
HEAT_MANAGER_PID(HeaterExtruder0, 'E', 0, TempExt0, PWMExtruder0, 260, 255, 1000, 10, 20000, 20.0, 0.6, 65.0, 40, 220, false)
//HEAT_MANAGER_PID(HeaterExtruder1, 'E', 2, TempExt1, PWMExtruder1, 260, 255, 10, 20000, 20.0, 0.6, 65.0, 40, 220, false)
//HEAT_MANAGER_PID(HeaterExtruder2, 'E', 3, TempExt2, PWMExtruder2, 260, 255, 10, 20000, 20.0, 0.6, 65.0, 40, 220, false)

// Coolers are stand alone functions that allow it to control
// a fan with external sensors. Many extruders require a cooling
// fan pointer to the extruder to prevent heat rising up.
// These can be controlled by the cooler. Since it is
// independent you just tell what part needs cooling.
// Other use cases are board cooling and heated chambers.

// Define tools. They get inserted into a tool array in configuration.h
// Typical tools are:
// TOOL_EXTRUDER(name, offx, offy, offz, heater, stepper, resolution, yank, maxSpeed, acceleration, advance, startScript, endScript)

TOOL_EXTRUDER(ToolExtruder0, 0, 0, 0, HeaterExtruder0, /*AL1Motor */ E0MotorBase, 1.75, 998.0, 5, 50, 5000, 0, "M117 Extruder 1", "", &Fan1PWM)
//TOOL_EXTRUDER(ToolExtruder1, 0, 0, 0, HeaterExtruder1, /*AL1Motor */ E0MotorBase, 1.75, 147.0, 5, 30, 5000, 40, "M117 Extruder 2", "", &Fan1PWM)
//TOOL_EXTRUDER(ToolExtruder2, 0, 0, 0, HeaterExtruder2, /*AL1Motor */ E0MotorBase, 1.75, 147.0, 5, 30, 5000, 40, "M117 Extruder 3", "", &Fan1PWM)
//TOOL_EXTRUDER(ToolExtruder2, 16.775, 0.615, -0.97, HeaterExtruder2, /*AL2Motor */ E2Motor, 1.75, 147.0, 5, 30, 5000, 40, "M117 Extruder 2\nM400\nM340 P0 S1500 R600\nG4 P300", "M340 P0 S800 R600\nG4 P300", &Fan1PWM)
//TOOL_LASER(Laser3, 0, 0, 0, Fan1NoKSPWM, fakeOut, fakeOut, 3000, 1, 100, 150.0, 1.5, "", "")
//TOOL_CNC(CNC4, 0, 0, 0, Fan1NoKSPWM, fakeOut, fakeOut, fakeOut, 7000, 3000, "", "")

// Use a signal that changes while extruder moves
//JAM_DETECTOR_HW(JamExtruder1, E1Motor, IOJam1, ToolExtruder1, 220, 10, 500)
//JAM_DETECTOR_HW(JamExtruder2, E2Motor, IOJam2, ToolExtruder2, 220, 10, 500)

// Use a signal that is high, when filament is loaded
//FILAMENT_DETECTOR(FilamentDetector1, IOJam1, ToolExtruder1)
//FILAMENT_DETECTOR(FilamentDetector2, IOJam2, ToolExtruder2)
