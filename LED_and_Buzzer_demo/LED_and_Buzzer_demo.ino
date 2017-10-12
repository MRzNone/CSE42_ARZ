/*
 * Filename: LED_and_Buzzer_demo.ino
 * Description: This sketch details basic usage of the following components:
 * 
 * Light Emitting Diodes (LEDs) [ https://sites.google.com/a/eng.ucsd.edu/robot-parade/robot-parts/leds ]
 * RGB LEDs [ https://sites.google.com/a/eng.ucsd.edu/robot-parade/robot-parts/rgb-leds ]
 * LED Arrays [ https://sites.google.com/a/eng.ucsd.edu/robot-parade/robot-parts/leds-arrays ]
 * Buzzers and Song Objects [ https://sites.google.com/a/eng.ucsd.edu/robot-parade/robot-parts/the-buzzer-and-music ]
 */

// Libraries we will use
#include <Gadgetron.h>

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
LEDArray matrix = LEDArray();
Buzzer buzzer = Buzzer(BUZZER);
Song song(buzzer);

/*
 * This function runs once when the robot first powers on and when it is reset.
 * Setup code goes here.
 */
void setup() {
     wheels.setup(); // initialized the wheels
     button.setup(); // initializen the button
     rgb_led.setup(); // initialize the RGB LED
     led1.setup();
     led2.setup();
     led3.setup();
     matrix.setup();
     
     wheels.spinLeft();
}

/*
 * This function runs over and over again in an infinite loop.
 */
void loop() {
  rgb_led.set(100, 0, 255);
  
  led1.turnOn();
  led2.turnOn();
  led3.turnOn();

  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, circle_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  song.playNextNote();

  
  delay(500);
  
  rgb_led.set(0, 255, 100);
  
  led1.turnOff();
  led2.turnOff();
  led3.turnOff();

  
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, square_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();

  
  delay(500);
  
  song.playNextNote();
  if(song.getIndex() == 14 || song.getIndex() == song.getLength()) {
    wheels.stop();
  }
  if(song.getIndex() == 16) {
    wheels.spinRight();
  }

 
  delay(500);
     
}
