/* 
 * File:   ultrasonic.h
 * Author: Abdelrahman Mansour
 *
 * Created on August 5, 2024, 1:07 AM
 */

#ifndef ULTRASONIC_H
#define	ULTRASONIC_H

/*section :     Includes    */
#include "../../MCAL_layer/TIMER1/hal_timer1.h"


/*section :     Macros Declarations    */
#define TRIG_PIN LATDbits.LATD1  // Assuming RD1 for TRIG
#define ECHO_PIN PORTDbits.RD0   // Assuming RD0 for ECHO

#define TRIG_PIN_DIR TRISDbits.TRISD1
#define ECHO_PIN_DIR TRISDbits.TRISD0

//#define SOUND_SPEED_CM_PER_US 0.0343  // Speed of sound in cm/us
#define SOUND_SPEED_CM_PER_US 0.27601  // Speed of sound in cm/us
/*section :     Macro Function Declarations    */


/*section :     Data Type Declarations    */

/*section :      Function Declarations    */
void init_timer1(void);
void init_ultrasonic(void);
void send_trigger_pulse(void);
unsigned int measure_distance(void);




#endif	/* ULTRASONIC_H */

