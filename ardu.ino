#include <FspTimer.h>
#include "ESC2nd.h"
// #include "pitches.h"

Sensor sensor(DEVICE_ADDR1);

Motor motorR('r');
Motor motorL('l');
 
static FspTimer fsp_timer;
//static PinStatus led_state;

// const int BUZZER_PIN 11;
 
void timer_interrupt_callback(timer_callback_args_t* arg){
  uint16_t val[8];
  sensor.read(val);

  if(val[0] < 800)
  {
    if(val[3] < 800)
    {
      motorR.drive(80);
      motorL.drive(80);  
    }
    else if(val[4] < 800)
    {
      motorR.drive(77);
      motorL.drive(83);
    }    
  }
  else if(val[7] < 800)
  {
    if(val[4] < 800)
    {
      motorR.drive(80);
      motorL.drive(80);  
    }
    else if(val[3] < 800)
    {
      motorR.drive(83);
      motorL.drive(77);
    }    
  }

   if(val[1] < 800)
   {
    motorR.drive(150);
    motorL.drive(-100);     
    /*
       motorR.drive(-30);
       motorL.drive(-30);      
       for(int foo_5 = 0; foo_5 < 200; foo_5++)
       {
         ;
       }
       motorR.drive(-150);
       motorL.drive(-150);      
       for(int foo_5 = 0; foo_5 < 600; foo_5++)
       {
        ;
       }
       motorR.drive(-30);
       motorL.drive(-30);      
       for(int foo_5 = 0; foo_5 < 100; foo_5++)
       {
         ;
       }
       motorR.drive(200);
       motorL.drive(-40);
       for(int foo_2 = 0; foo_2 < 30; foo_2++)
       {
         ;
       }      
      */
   }

  else if(val[6] < 800)
  {
    motorR.drive(-100);
    motorL.drive(150);    
    /*
       motorR.drive(-30);
       motorL.drive(-30);      
       for(int foo_5 = 0; foo_5 < 200; foo_5++)
       {
         ;
       }
       motorR.drive(-150);
       motorL.drive(-150);      
       for(int foo_5 = 0; foo_5 < 600; foo_5++)
       {
        ;
       }
       motorR.drive(-30);
       motorL.drive(-30);      
       for(int foo_5 = 0; foo_5 < 100; foo_5++)
       {
         ;
       }
       motorR.drive(-40);
       motorL.drive(200);
       for(int foo_2 = 0; foo_2 < 30; foo_2++)
       {
         ;
       }
      */
  }
  else if(val[2] < 800)
  {
    motorR.drive(200);
    motorL.drive(20);
  }
  else if(val[5] < 800)
  {
    motorR.drive(20);
    motorL.drive(200);
  }

  else
  {
      motorR.drive(60);
      motorL.drive(60);
  }
}
 
void setup(void){
//        led_state=HIGH;
//        pinMode(LED_BUILTIN, OUTPUT);
//        digitalWrite(LED_BUILTIN,led_state);
        uint8_t timer_type = 0;
        int8_t channel = FspTimer::get_available_timer(timer_type);
        fsp_timer.begin(TIMER_MODE_PERIODIC, timer_type, channel, 8000.0f, 0.0f, timer_interrupt_callback, nullptr);
        fsp_timer.setup_overflow_irq();
        fsp_timer.open();
        fsp_timer.start();
}
 
void loop(void){
 
}