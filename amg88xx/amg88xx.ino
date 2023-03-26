#include <Wire.h>

#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
int AMG_pixelMax = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readAmg();
}

int readAmg () {
  amg.readPixels(pixels);

  float maxi = 0;
  for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
    if (pixels[i] > maxi) {
      maxi = pixels [i];
      if (maxi >= 30)AMG_pixelMax = i;
      else AMG_pixelMax = -1;
    }
  }
  return maxi;
}
