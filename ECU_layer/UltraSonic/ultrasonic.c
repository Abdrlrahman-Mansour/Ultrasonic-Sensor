/* 
 * File:   ultrasonic.h
 * Author: Abdelrahman Mansour
 *
 * Created on August 5, 2024, 1:07 AM
 */
#include "ultrasonic.h"

 static unsigned int pulse_width;
 static unsigned int distance_Sensor;


void init_timer1(void) {
    T1CON = 0x31; // Timer1 with prescaler 1:8
    TMR1H = 0;   // Clear Timer1
    TMR1L = 0;
}
void init_ultrasonic(void) {
    TRIG_PIN_DIR = 0;  // Set TRIG_PIN as output
    ECHO_PIN_DIR = 1;  // Set ECHO_PIN as input
    init_timer1();
}
void send_trigger_pulse(void) {
    TRIG_PIN = 1;
    __delay_us(10);   // 10µs delay
    TRIG_PIN = 0;
}
unsigned int measure_distance(void) {
    
   

    send_trigger_pulse();

    while (!ECHO_PIN); // Wait for the pulse to start

    // Start Timer1
    TMR1H = 0;
    TMR1L = 0;

    while (ECHO_PIN); // Wait for the pulse to end

    // Stop Timer1
    pulse_width = (TMR1H << 8) | TMR1L;  // Get the pulse width

    // Calculate distance in cm (assuming sound speed 340m/s and clock frequency 4MHz)
    distance_Sensor = (pulse_width * SOUND_SPEED_CM_PER_US) / 2; // Convert pulse width to distance

    return distance_Sensor;
}
