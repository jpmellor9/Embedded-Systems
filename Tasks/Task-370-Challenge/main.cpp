#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;

//Used this to 
Ticker tick;
AnalogIn LDR(AN_LDR_PIN);
void tickISR();
void task1();
double runningsum = 0;
double mean = 0;
DigitalOut redLED(TRAF_RED1_PIN);  

Thread t1;
osThreadId_t mainThreadID;


int main(void)
{
tick.attach(&tickISR, 1ms); 

t1.start(task1);

mainThreadID = ThisThread::get_id();
// uint16_t ldr = LDR.read_u16();
   // printf("ldr = %d\n", ldr);
/*
1. Create an ISR - called by a Ticker every 1ms. This ISR simply has the job of signalling a waiting thread to perform an ADC conversion
2. Create a thread that waits for a signal from the ISR. This thread should ideally have the highest priority
3. Each time it is unblocked by the signal, it should read the ADC (Use `AnalogIn`) for the LDR and add it to a running sum.
4. Every 1s, it should print out the average of the past 1000 samples to the terminal. 
*/
    while (true) {
      
       ThisThread::sleep_for(1000ms);
       redLED = !redLED;
       mean = runningsum/1000;
       runningsum = 0;
       printf("LDR mean = %f\n", mean);

    }
    
}  

void tickISR()
{
    t1.flags_set(1);
}

void task1()
{
    printf("enter\n");

    while(true){
        ThisThread::flags_wait_any(1);
        
         uint16_t ldr = LDR.read_u16();
         runningsum = runningsum + ldr;
         
        
        }
}
