#include <stdio.h>
#include <p18f4525.h>
#include "sumovore.h"
#include "motor_control.h"
#include "interrupts.h"


// main acts as a cyclical task sequencer
void main(void)
{
   
    initialization(); // function from sumovore.c
                      // it sets up pwm (using timer2),
                      // IO pins, the ADC, the 
                      // USART and the default
                      // threshold
    printf("\n\rKwantlen APSC1299 simple curve follower -- with error codes\n\r"); 
    ClrWdt();         // defined in <p18f4525.h>

threshold = 280u; // to change from default value
                     // uncomment and change to any unsigned int <1024u -- most usually <512u

    while(1)
    {
        check_sensors();    // from sumovore.c
        set_leds();         // function from sumovore.c
	                    // each LED indicates a sensor
	                    // value. If you need to use the LED's for
	                    // a different purpose change this line
	                    // and make your own LED setting function
        motor_control();    // function from motor_control.c 
        ClrWdt();           // defined in <p18f4525.h>
        if(lvd_flag_set())  LVtrap();
    }
}
 