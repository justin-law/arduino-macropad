// Vanderbilt Maker Club Macro Keyboard Firmware
// Justin Law 2021
//

#include "HID-Project.h"

//right now the rotary doesnt have press control, press control bound to the mx switch on pin 5
#define ROTARY_A 7 //knob spin
#define ROTARY_B 8 //knob spin
#define ROTARY_BUTTON 6  //knob button
#define KEY1 2
#define KEY2 3
#define KEY3 4
#define KEY4 5

boolean A, a, B, b, C, c, D, d, E, e, F, f, G, g;
char line[80];
int n, t;

void setup() {
  Serial.begin(38400);
  Serial.write("Starting...\n");
  Serial.end();
  pinMode(ROTARY_A, INPUT_PULLUP);
  pinMode(ROTARY_B, INPUT_PULLUP);
  pinMode(ROTARY_BUTTON, INPUT_PULLUP);  
  pinMode(KEY1, INPUT_PULLUP);
  pinMode(KEY2, INPUT_PULLUP);
  pinMode(KEY3, INPUT_PULLUP);
  pinMode(KEY4, INPUT_PULLUP);
  
  a = b = c = d = e = f = g = false;
  t = 0;
  n = 0;
  Consumer.begin();
  BootKeyboard.begin();
  Keyboard.begin();
//  System.begin(); // For System functions
//  Gamepad.begin(); // For gamepad functions
//  Mouse.begin(); // For mouse functions
//  AbsoluteMouse.begin(); // For the Absolute Mouse

  //turns off the red leds on the arduino pro micro board
  pinMode(LED_BUILTIN_TX,INPUT);
  pinMode(LED_BUILTIN_RX,INPUT);

}

void loop() {

  if (millis() + 5 > t) {
    A = digitalRead(ROTARY_A) == LOW;
    B = digitalRead(ROTARY_B) == LOW;
    C = digitalRead(ROTARY_BUTTON) == LOW;
    D = digitalRead(KEY1) == LOW;
    E = digitalRead(KEY2) == LOW;
    F = digitalRead(KEY3) == LOW;
    G = digitalRead(KEY4) == LOW;
    
    if (A && !a) 
    {
      if (B) {
        n++;
        Consumer.write(MEDIA_VOL_UP);
      }
      else {
        n--;
        Consumer.write(MEDIA_VOL_DOWN);
      }
    }
    a = A;
    
    if (C && ! c) {
      // Put commands in here
      // To program what you want each button to do

      // Media Controls
      //Consumer.write(MEDIA_PLAY_PAUSE);
      //Consumer.write(MEDIA_NEXT);
      //Consumer.write(MEDIA_PREV);
      //Consumer.write(MEDIA_VOL_UP);
      //Consumer.write(MEDIA_VOL_DOWN);

      // To Press specific keys
      // Keyboard.write('e');

      /*
      To create macros
      Keyboard.press('c');
      delay(100);
      Keyboard.press('n');
      delay(100);
      Keyboard.releaseAll();*/
      
      Keyboard.write('e');
      
    }
    c = C;

    if (D && ! d) {
      
      Keyboard.write('a');
      
    }
    d = D;

    if (E && ! e) {
      
      Keyboard.write('b');

    }
    e = E;

    if (F && ! f) {
      
      Keyboard.write('c');
      
    }
    f = F;

    if (G && ! g) {
      
      Keyboard.write('d');
      
    }
    g = G;

    
  }

}
