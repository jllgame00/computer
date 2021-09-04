#include <Adafruit_NeoPixel.h>

#define PIN 10   // input pin Neopixel is attached to

#define NUMPIXELS      4 // number of neopixels in strip

#define BRIGHTNESS 100

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int BUTTON = 2; // 버튼 입력 핀번호
int MOTOR = 12; // 모터 입력 핀번호
int STATE = 0;

void setup() //                  -ㅣ
{ //                              ㅣ 핀번호에 입력/출력 지정
  pinMode(BUTTON, INPUT); //      ㅣ
  pinMode(MOTOR, OUTPUT); //      ㅣ
  pixels.begin();
} //                             -ㅣ

void loop() {
  int value = digitalRead(BUTTON);
  if(value == HIGH){
    if(STATE == 0){
      STATE = 1;
    }
    else if(STATE == 1){
      STATE = 0;
    }
  }
  if(STATE == 0){
    digitalWrite(MOTOR, LOW);
    pixels.setBrightness(0);
    pixels.show();
  }
  else if(STATE == 1){
    setColor();
    digitalWrite(MOTOR, HIGH);
    pixels.setBrightness(100);
    pixels.show();
      for (int i=0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
        pixels.show();
        delay(delayval);
    }
  }
  delay(1000);
}
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
