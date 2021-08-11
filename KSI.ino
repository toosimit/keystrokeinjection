#include "Keyboard.h"
int A = 131;
void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(2) == LOW) {
    //
    delay(1000);
    Keyboard.write(KEY_LEFT_GUI);
    delay(100);
    keyPrinter("firefox+") ;
    delay(1000);
    keyPrinter("fuck you bitch+") ;
  }
}
void keyPrinter(String inputStr) {
  int i = 0;
  char chr = inputStr[0];

  int lnt = inputStr.length();
  for (int i = 0; i <= lnt; i++) {

    if (inputStr[i] == '+') {
      //      Serial.println("Enter");
      Keyboard.write(KEY_RETURN);
      delay(30);
    }
    if (inputStr[i] != '+') {
      Keyboard.write(inputStr[i]);
      delay(30);
    }
  }
  delay(5000);
}
