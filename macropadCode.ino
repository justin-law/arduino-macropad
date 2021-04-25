//
//USB Rotary Volume Control
//

#include "HID-Project.h"

//right now the rotary doesnt have press control, press control bound to the mx switch on pin 5
#define ROTARY_A A2
#define ROTARY_B A3
#define ROTARY_C 5
#define KEY1 4
#define KEY2 3
#define KEY3 2

boolean A, a, B, b, C, c, D, d, E, e, F, f;
char line[80];
int n, t;

void setup() {
  Serial.begin(38400);
  Serial.write("Starting...\n");
  Serial.end();
  pinMode(ROTARY_A, INPUT_PULLUP);
  pinMode(ROTARY_B, INPUT_PULLUP);
  pinMode(ROTARY_C, INPUT_PULLUP);  
  pinMode(KEY1, INPUT_PULLUP);
  pinMode(KEY2, INPUT_PULLUP);
  pinMode(KEY3, INPUT_PULLUP);
  
  a = b = c = d = e = f = false;
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
    C = digitalRead(ROTARY_C) == LOW;
    D = digitalRead(KEY1) == LOW;
    E = digitalRead(KEY2) == LOW;
    F = digitalRead(KEY3) == LOW;
    
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
      Consumer.write(MEDIA_PLAY_PAUSE);
    }
    c = C;

    if (D && ! d) {
      Consumer.write(MEDIA_NEXT);
    }
    d = D;

    if (E && ! e) {
      //Consumer.write(MEDIA_NEXT);
      /*
      Keyboard.press(HID_KEYBOARD_LEFT_CONTROL);
      Keyboard.press('n');
      delay(100);
      Keyboard.releaseAll();*/
      //Consumer.write(MEDIA_PREV);
      Keyboard.press(KEY_SPACE);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press(KEY_SPACE);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press(KEY_ENTER);
      delay(100);
      Keyboard.releaseAll();
    }
    e = E;

    if (F && ! f) {
      //Consumer.write(MEDIA_PLAY_PAUSE);
      Keyboard.press(KEY_LEFT_WINDOWS );
      Keyboard.press('x');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press('u');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press('s');
      delay(100);
      Keyboard.releaseAll();
    }
    f = F;
  }

}
