

// this is my bed illumination using PWM to fade the LEDS, not as bright as digital output

// with overide of pins for working with nano 



// include library

#include <NewPing.h>



// setup ports

int redLed = 9;
int greenLed = 10;
int blueLed = 11;


// variable for fade

int fadeValue = 0;



// Hook up HC-SR04 with Trig to Arduino Pin 12, Echo to Arduino pin 13
// Maximum Distance is 400 cm

#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float duration, distance;

int iterations = 5;




void setup() {

 // Serial.begin (9600);


  // put your setup code here, to run once:
  // define outputs
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  //added trig and echo pinMode made it work! (overrides presets in newping library)
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);

 
}

void loop() {
  // put your main code here, to run repeatedly:

  duration = sonar.ping_median(iterations);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound

  distance = (duration / 2) * 0.0343;

 

 // Serial.println(lightReading);


  // trigger distances in Cm
 
  if ((distance <= 100 && distance >= 10))
  {



    int r = 1;
    for (int i = 0; i > -1; i = i + r) {
      analogWrite(redLed, i);
      if (i == 255) r = -1;             // switch direction at peak
      delay(10);
    }

    int g = 1;
    for (int i = 0; i > -1; i = i + g) {
      analogWrite(greenLed, i);
      if (i == 255) g = -1;             // switch direction at peak
      delay(10);
    }

    int b = 1;
    for (int i = 0; i > -1; i = i + b) {
      analogWrite(blueLed, i);
      if (i == 255) b = -1;             // switch direction at peak
      delay(10);
    }


  }


  else
  {
    analogWrite (redLed, LOW);
    analogWrite (greenLed, LOW);
    analogWrite (blueLed, LOW);
  }
  delay (500);
}








