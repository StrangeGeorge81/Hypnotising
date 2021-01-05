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
        uint32_t rgbcolor = pixels.ColorHSV(hue, 255, brght);

        for (nas=0; nas<=5; nas++){
            pixels.setPixelColor (nas, rgbcolor);
            pixels.show();
            delay(250);
        }
    }    
    if (nas==6){
        hue=21845;
        uint32_t rgbcolor = pixels.ColorHSV(hue, 255, brght);

        for(nas=6; nas<=11; nas++){
            pixels.setPixelColor (nas, rgbcolor);
            pixels.show();
            delay(500);
        }

        if (nas>11){
            nas = 0;
            pixels.clear();
            pixels.show();
            delay(1000);
        }

    }

}

void pxlsAct(int tme){
    pixels.show();
    delay(tme);
    pixels.clear();
    pixels.show();
}

void flashingR(){
    for (int i=0; i<=11; i=i+2){
        hue=0;
        uint32_t rgbcolor = pixels.ColorHSV(hue, 255, brght);
        nas=i;
        pixels.setPixelColor (nas, rgbcolor);
    }
    pxlsAct(250);
    
}

void flashingG(){
    for (int i=1; i<=12; i=i+2){
        hue=21845;
        uint32_t rgbcolor = pixels.ColorHSV(hue, 255, brght);
        nas=i;
        pixels.setPixelColor (nas, rgbcolor);
    }
    pxlsAct(500);
    
}

void rep(){
    // time depending changes {hypno()}
    
    for(int timer = 0; timer<=10; timer++){
        
        flashingG();
        flashingR();
        nas = 0;
        
    }

}





void setup() {
   pixels.begin();

}

void loop() {
    hypno();
    rep();
    pixels.clear();
    pixels.show();
    delay (1000);

}