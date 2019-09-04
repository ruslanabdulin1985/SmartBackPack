// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        2 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void circle() {
  pixels.clear(); // Set all pixel colors to 'off'
  int led = 0;
  int leds[2] = {0,1};
  
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    switch (i){
      case 0 : led = 0; leds[0] = 0; leds[1]=1;
        break;
      case 1 : led = 5; leds[0] = 5; leds[1]=0;
        break;
      case 2 : led = 4; leds[0] = 4; leds[1]=5;
        break;
      case 3 : led = 3; leds[0] = 3; leds[1]=4;
        break;
      case 4 : led = 2; leds[0] = 2; leds[1]=3;
        break;
      case 5 : led = 1; leds[0] = 1; leds[1]=2;
        break;
    }

    
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.clear(); // Set all pixel colors to 'off'

//    pixels.setPixelColor(led, pixels.Color(255,69,0));
    
    pixels.setPixelColor(leds[0], pixels.Color(255,69,0));
    pixels.setPixelColor(leds[1], pixels.Color(255,69,0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(150); // Pause before next pass through loop
  }
}

void loop() {
  circle(); 



 
}
