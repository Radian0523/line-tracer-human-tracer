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
    if(val[7] > 1000)
    {
      //前が線上
      if(val[3] < 800)  //左最線
      {
        motorR.drive(100);
        motorL.drive(90);    
      }
      else if(val[4] < 800)  //右最線
      {
        motorR.drive(90);
        motorL.drive(100);   
      }

      if(val[1] < 800)  //左最外
      {
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
        motorR.drive(100);
        motorL.drive(10);
        for(int foo_2 = 0; foo_2 < 30; foo_2++)
        {
         ;
        }
      }
      else if(val[6] < 800) //右最外
      {
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
        motorR.drive(10);
        motorL.drive(100);
        for(int foo_2 = 0; foo_2 < 30; foo_2++)
        {
         ;
        }
      }
      else if(val[2] < 800)
      {
        
      }
    }  
  } //前が線内ここまで

    // if(val[1] < 800)
    // {
    //     motorR.drive(200);
    //     motorL.drive(-20);
    // }

    //ここから前が線外
    else if(val[2] < 800)
    {
      motorR.drive(60);
      motorL.drive(20);
    }
    else
    {
        if(val[6] < 800)  //右最外
        {
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
          for(int foo_6 = 0; foo_6 < 30; foo_6++)
          {
            ;
          } 
        }          
    // }
    // if(val[6] < 800)
    // {
    //   motorR.drive(-20);
    //   motorL.drive(170);
    // }
        else if(val[5] < 700)
        {
          motorR.drive(20);
          motorL.drive(60);
        }
        else
        {
          motorR.drive(60);
          motorL.drive(60); 
    
        }
      

    }
  }

  else if(val[0] < 800)   //線が前
  {
    if(val[7] > 800)
    {
      motorR.drive(80);
      motorL.drive(60);
    }    
  }
  else if(val[7] < 800)
  {
    if(val[0] > 800)
    {
      motorR.drive(60);
      motorL.drive(80);
    }
  }
  else
  {

    if(val[3] < 800)
    {
      motorR.drive(50);
      motorL.drive(30);    
    }

    if(val[4] < 800)
    {
      motorR.drive(30);
      motorL.drive(50);   
    }

   if(val[1] < 800)
   {
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
      
   }
    // if(val[1] < 800)
    // {
    //     motorR.drive(200);
    //     motorL.drive(-20);
    // }
    else if(val[2] < 800)
    {
      motorR.drive(60);
      motorL.drive(20);
    }
    else
    {
      if(val[6] < 800)
      {
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
        for(int foo_6 = 0; foo_6 < 30; foo_6++)
        {
          ;
        } 
                
    // }
    // if(val[6] < 800)
    // {
    //   motorR.drive(-20);
    //   motorL.drive(170);
    // }
      else if(val[5] < 700)
      {
        motorR.drive(20);
        motorL.drive(60);
      }
      else
      {
        motorR.drive(60);
        motorL.drive(60); 
    
      }
    }
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