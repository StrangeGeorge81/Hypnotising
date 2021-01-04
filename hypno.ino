#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 12
#define PIN 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int nas = 0;
//NUMPIXELS 12 <=> 0 to 11

int hue = 0;
// for colors, red or green
// red ==> 0
// green ==> 65535/3 (21845)

int brght = 42;
// brightness up and down
// depends on repetion

uint32_t rgbcolor = pixels.ColorHSV(hue, 255, brght);

void hypno(){
    //changes hue based on {rep()}
    if (nas==0){
        hue=0;
        for (nas=0; nas<=5; nas++){
            pixels.setPixelColor (nas, rgbcolor);
            pixels.show();
            delay(81);
        }
    }    
    if (nas==6){
        hue=21845;
        for(nas=6; nas<=11; nas++){
            pixels.setPixelColor (nas, rgbcolor);
            pixels.show();
            delay(118);
        }
        if (nas>=11){
            nas = 0;
        }
    }
    

}

void rep(){
    // time depending changes {hypno()}
    int reption = 0;
    for(int timer = 0; timer<10; timer++){

        hypno();

    }

}





void setup() {
   pixels.begin();

}

void loop() {
    rep();
}