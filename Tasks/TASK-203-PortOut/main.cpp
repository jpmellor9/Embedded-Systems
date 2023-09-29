#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define TRAF_RED2_PIN PC_7
#define LEDMASK 0b0000000011001100
#define LEDMASK2 0b0100000010000001
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds(PortC, LEDMASK);
PortOut leds2(PortB, LEDMASK2);

int main()
{
    while (true) {
        leds = leds ^ LEDMASK;   //Binary 000
        leds2 = leds2 ^ LEDMASK2; 
        wait_us(500000);
       // leds = 0xFFFF;   //Binary 11111111
       // leds2 = 0xFFFF;
       // wait_us(500000);    
    }
}




