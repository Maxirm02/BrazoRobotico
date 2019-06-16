void setup() {


  Serial.begin(9600);

  myservoBase.attach (servoPinBase);
  myservoArriba.attach (servoPinArriba);
  myservoPinza.attach (servoPinPinza);
  myservoAtras.attach (servoPinAtras);

  myservoBase.write (50);
  myservoArriba.write (101);
  myservoPinza.write (167);
  myservoAtras.write (32);

  //attachInterrupt(0, cambioModo, FALLING);

  //attachInterrupt(1, cambioPosicion, FALLING);

}
void loop() {

  debounce1();#include <Servo.h>

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;  // the number of the pushbutton pin
const int buttonPin2 = 3;

// Variables will change:
int volatile autom = 0;
int volatile posicion = 0;// the current state of the output pin
int buttonState1;          // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin
int buttonState2;          // the current reading from the input pin
int lastButtonState2 = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay1 = 50; // the debounce time; increase if the output flickers
unsigned long lastDebounceTime2 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay2 = 50;

Servo myservoBase;
Servo myservoArriba;
Servo myservoPinza;
Servo myservoAtras;

const int servoPinBase = 7;
const int servoPinArriba = 9;
const int servoPinPinza = 10;
const int servoPinAtras = 11;

const int potPinBase = A0;
const int potPinArriba = A1;
const int potPinPinza = A2;
const int potPinAtras = A3;

int potValueBase = 0;
int potValueArriba = 0;
int potValuePinza = 0;
int potValueAtras = 0;

int angleBase=0;
int angleArriba=0;
int anglePinza=0;
int angleAtras=0;


  debounce2();
 
  if (autom == 1) {
    if (posicion == 0){
     posicion0();
    }
    else {
    automatico();
    }
  }
  else {
    if (posicion == 0){
     posicion0();
    }
    else {
    manual();
    }
  }
 
}
void debounce1() {
  int reading = digitalRead(buttonPin1);
 
  if (reading != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay1) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState1) {
      buttonState1 = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == HIGH) {
        autom = !autom;
      }
    }
  }


  lastButtonState1 = reading;
  Serial.print ("Modo");
  Serial.println (autom);
  Serial.print ("Posicion");
  Serial.println (posicion);
}

void debounce2() {
  int reading = digitalRead(buttonPin2);
 
  if (reading != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay2) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState2) {
      buttonState2 = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState2 == HIGH) {
        posicion = !posicion;
      }
    }
  }
  lastButtonState2 = reading;
  Serial.print ("Modo");
  Serial.println (autom);
  Serial.print ("Posicion");
  Serial.println (posicion);
}
void automatico(){
   
   paulatinoBase (50,22);
  //myservo1.write (165);
 // delay (800);
  //myservo2.write (147);
  paulatinoArriba (101,10);
 // delay (800);
 
 // delay (800);
  paulatinoAtras (32,129);
  //myservo4.write (119);
 // delay (1300);
  myservoPinza.write (16);
 
  paulatinoBase(22, 68);
  //myservo1.write (147);
  //delay(800);
  //myservo2.write (87);
  paulatinoArriba (10,162);
  //delay(800);
  paulatinoAtras (129,14);
  //myservo4.write (179);
  //delay(800);
  myservoPinza.write (160);
 // delay(1300);
 
  paulatinoBase(68, 50);
  //myservo1.write (180);
  //delay(800);
  //myservo2.write (2);
  paulatinoArriba (162,101);
  //delay(800);
  paulatinoAtras (14,32);
  //myservo4.write (174);
  //delay(800);
  myservoPinza.write (13);
  //delay(2000);

  posicion=0;
  //Serial.println ("Automatico");
}

void paulatinoBase (int angle_antBase, int angleBase) {

  if (angle_antBase < angleBase) {
  for (int i = angle_antBase; i <= angleBase; i++) {
    myservoBase.write (i);
    delay(20);
  }
  }

  else {
  for (int i = angle_antBase; i >= angleBase; i--) {
    myservoBase.write (i);
    delay(20);
  }
  }
}

void paulatinoAtras (int angle_antAtras, int angleAtras) {
 
  if (angle_antAtras < angleAtras) {
  for (int i = angle_antAtras; i <= angleAtras; i++) {
    myservoAtras.write (i);
    delay(20);
  }
  }

  else {
  for (int i = angle_antAtras; i >= angleAtras; i--) {
    myservoAtras.write (i);
    delay(20);
  }
  }
}

void paulatinoArriba (int angle_antArriba, int angleArriba) {

  if (angle_antArriba < angleArriba) {
  for (int i = angle_antArriba; i <= angleArriba; i++) {
    myservoArriba.write (i);
    delay(20);
  }
  }

  else {
  for (int i = angle_antArriba; i >= angleArriba; i--) {
    myservoArriba.write (i);
    delay(20);
  }
  }
}

void manual(){
  ServoBase ();
  ServoArriba ();
  ServoPinza ();
  ServoAtras ();
 // Serial.println ("Manual");
}

void ServoBase () {

  potValueBase = analogRead (potPinBase);

  angleBase = map (potValueBase,0,1023,180,0);

  myservoBase.write (angleBase);

  //Serial.print ("ServoBase");
  //Serial.println (angleBase);
 
  delay(30);

 }


void ServoArriba () {

  potValueArriba = analogRead (potPinArriba);

  angleArriba = map (potValueArriba,0,1023,180,0);

  myservoArriba.write (angleArriba);
  //Serial.print ("ServoArriba");
  //Serial.println (angleArriba);

  delay(30);
 }

void ServoPinza () {

  potValuePinza = analogRead (potPinPinza);

  anglePinza = map (potValuePinza,0,1023,180,0);

  myservoPinza.write (anglePinza);
  //Serial.print ("ServoPinza");
  //Serial.println (anglePinza);

  delay(30);


 }

 void ServoAtras () {

  potValueAtras = analogRead (potPinAtras);

  angleAtras = map (potValueAtras,0,1023,180,0);

  myservoAtras.write (angleAtras);
  //Serial.print ("ServoAtras");
  //Serial.println (angleAtras);

  delay(30);

 }

void posicion0 (){
  myservoBase.write (50);
  myservoArriba.write (101);
  myservoPinza.write (167);
  myservoAtras.write (32);
 // Serial.println ("Posición0");
}


