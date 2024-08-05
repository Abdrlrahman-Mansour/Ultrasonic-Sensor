/* 
 * File:   mcal_interrupt_cfg.h
 * Author: Abdelrahman Mansour
 *
 * Created on July 5, 2024, 7:43 AM
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

/*section :     Includes    */
#include "mcal_interrupt_gen_cfg.h"
#include "pic18f4620.h"
#include "../MCAL_std_types.h"
#include "../GPIO/hal_gpio.h"

/*section :     Macros Declarations    */
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCCUR     1
#define INTERRUPT_NOT_OCCUR 0
#define INTERRUPT_PRIORITY_ENABLE    1
#define INTERRUPT_PRIORITY_DISABLE   0

/* ----------------- Macro Functions Declarations -----------------*/

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This macro will enable priority levels on interrupts. */
#define INTERRUPT_PriorityLevelsEnable()  (RCONbits.IPEN = 1)
/* This macro will disable  priority levels on interrupts. */
#define INTERRUPT_PriorityLevelsDisable() (RCONbits.IPEN = 0)

/* This macro will enable high priority global interrupts. */
#define INTERRUPT_GlobalInterruptHighEnable()  (INTCONbits.GIEH = 1)
/* This macro will disable high priority global interrupts. */
#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH = 0)

/* This macro will enable low priority global interrupts. */
#define INTERRUPT_GlobalInterruptLowEnable()   (INTCONbits.GIEL = 1)
/* This macro will disable low priority global interrupts. */
#define INTERRUPT_GlobalInterruptLowDisable()  (INTCONbits.GIEL = 0)
#else
/* This macro will enable global interrupts. */
#define INTERRUPT_GlobalInterruptEnable()  (INTCONbits.GIE = 1)
/* This macro will disable global interrupts. */
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)
/* This macro will enable peripheral interrupts. */
#define INTERRUPT_PeripheralInterruptEnable()  (INTCONbits.PEIE = 1)
/* This macro will disable peripheral interrupts. */
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)
#endif

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority_cfg;
/*section :      Function Declarations    */


#endif	/* MCAL_INTERRUPT_CFG_H */

