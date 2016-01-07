/**
 * 
 * tcs230.ino
 * 
 * @author Jose Patricio Hijuitl <patriciohc.0@gmail.com>
 */

#include <TimerOne.h>
#include <LiquidCrystal.h>

#include "ColorRecognition.h"
#include "ColorRecognitionTCS230.h"
#include "rgb_to_hsv.c"

/*
#define R 0
#define G 1
#define B 2
*/
int RGB[3] = {0,0,0};
ColorRecognitionTCS230* tcs230;

void setup() {
	Serial.begin(9600);
	tcs230 = ColorRecognitionTCS230::getInstance();
	tcs230->initialize(2, 3, 4);
	LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
	LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
	lcd.begin(16, 2);

//debug
/*	Serial.print("Ajust. blanco...");
	Serial.print("Coloque blanco..");
	Serial.print("Durante 5 sec.");
*/
	lcd.print("Ajust. white...");
	lcd.setCursor(0, 1);
	lcd.print("Show white..");
	lcd.setCursor(0, 1);
	lcd.print("During 5 sec.");
	Show something white to it during 4 seconds.
	tcs230->adjustWhiteBalance();
}

/*
toma 10 lecturas de rgb y retorna el promedio
*/
void avg(){
	RGB[RED]= 0;
	RGB[GREEN]= 0;
	RGB[BLUE]= 0;
	delay(2000);
	for(int i = 0; i<10; i++){
		delay(500);
		RGB[RED] += tcs230->getRed();
		RGB[GREEN] += tcs230->getGreen();
		RGB[BLUE] += tcs230->getBlue();
	}
	RGB[RED] /= 10;
	RGB[GREEN] /= 10;
	RGB[BLUE] /= 10;
}

void loop() {
	int H;
	float S,V;
	lcd.setCursor(0, 1);
	delay(3000);
	avg();
	RGB_to_HSV(RGB, &H, &S, &V);
	if (H < 65 && V > 70){
		lcd.print("add solution");
	}else if(H < 68 && V < 65){
		lcd.print("perfect");
	}else{
		lcd.print("change solution")
	}
/*
	Serial.print("H = ");
	Serial.println(H);
	Serial.print("S = ");
	Serial.println(S);
	Serial.print("V = ");
	Serial.println(V);
	Serial.println("-------------------");
	Serial.print("Red: ");
	Serial.println(tcs230->getRed());
	Serial.print("Green: ");
	Serial.println(tcs230->getGreen());
	Serial.print("Blue ");
	Serial.println(tcs230->getBlue());
	Serial.println("-------------------");
	delay(3000);*/

}
