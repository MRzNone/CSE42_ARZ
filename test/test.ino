/*
 Name:    Test_Robot_1.ino
 Created: 10/5/2016 12:18:58 PM
 Author:  Michael
*/

#include<Gadgetron.h>

// Constants that determine which pins on the microcontroller we will use.
#define PWMA 3
#define PWMB 5
#define LED_R 6
#define LED_G 9
#define LED_B 10
#define BUTTON 0
#define BUZZER 1
#define STBY 4
#define AIN1 8
#define AIN2 11
#define BIN1 12
#define BIN2 13
#define LED1 A0
#define LED2 A1
#define LED3 A2
// Several constants used for testing purposes
#define BAUD 9600
#define DRIVE_TIME 500
#define MOTOR_SPEED 100

static const uint8_t PROGMEM
circle_bmp[] =
{ B00111100,
B01000010,
B10000001,
B10000001,
B10000001,
B10000001,
B01000010,
B00111100 },
square_bmp[] =
{ B11111111,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B11111111 };

// Create the variables that represent the wheels and the buttons
Motor wheels = Motor(STBY, PWMA, AIN1, AIN2, PWMB, BIN1, BIN2);
MomentaryButton button = MomentaryButton(BUTTON);
RGBLED rgb_led = RGBLED(LED_R, LED_G, LED_B);
LED led1 = LED(LED1);
LED led2 = LED(LED2);
LED led3 = LED(LED3);
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
Buzzer buzzer = Buzzer(BUZZER);
Song song(buzzer);

// This function prepares the robot to run!
void setup() {
  matrix.begin(0x70);
  wheels.setup();
  button.setup();
  rgb_led.setup();
  led1.setup();
  led2.setup();
  led3.setup();
  buzzer.setup();
  rgb_led.set(0, 0, 0);
  matrix.clear();
}

// The loop function runs the test code over and over again until power down 
// or reset
void loop() {
  button.waitUntilPressed();
  drawCircle();
}

void drawCircle()
{
  for(int i = 0; i < 1000; i++)
  {
    wheels.spinLeft();
    delay(500/60);
    
    wheels.forward();
    delay(28);
  }
}


void draw8()
{
   
  wheels.forward();
  delay(700);

  wheels.spinRight();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinRight();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinRight();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinRight();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinRight();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinRight();
  delay(500);
  


  //  lower half of the 8

  wheels.forward();
  delay(900);

  wheels.spinLeft();
  delay(600);

  wheels.forward();
  delay(700);

  wheels.spinLeft();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinLeft();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinLeft();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinLeft();
  delay(500);

  wheels.forward();
  delay(700);

  wheels.spinLeft();
  delay(500);

  wheels.forward();
  delay(700);
  
  wheels.stop();
}
