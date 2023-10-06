#include "uop_msb.h"
#include <cstdio>
using namespace uop_msb;

// Hardware Definitions
#define TRAF_RED1_PIN PC_2

// Inputs
DigitalIn SW_BLUE(USER_BUTTON);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);

// Timer(modified version from Timer)
TimerCompat tmr1;
TimerCompat tmr_debounce;

int last_sw;
int curr;
int main()
{
    //Time how long it takes to perform a printf
    tmr1.start();
    printf("Hello World How Are You\n");
    tmr1.stop();

    //Print out how long it took
    unsigned long long dur = tmr1.read_ms();
    printf("The time taken was %llu milliseconds\n", dur);    

    //Now to use a timer to implement a delay
    tmr1.start();
    last_sw = SW_BLUE;
    
    while (true) {
        //Wait for switch press
        if (SW_BLUE != last_sw){
        tmr_debounce.start();
            if (tmr_debounce.elapsed_time() >= 300ms){
             tmr_debounce.stop();
                last_sw = SW_BLUE;
                if (SW_BLUE == 0){
                    //Turn on LED
                    ledRed = !ledRed;
                    }
        }
        }
       

        //Wait for 500ms
       // tmr1.reset();
       // while (tmr1.elapsed_time() < 500ms); //How about this for C++ magic :)

     //   wait_us(500000);

        //Turn off LED
        //ledRed = 0;
    }
}



