#include <Wire.h>

#define cmpsAddress 0x60    //address dari cmps

byte highBytes, lowBytes;                     //variabel menampung sementara untuk perhitungan sudut kompas
int compassVal, compassOffset;                //variabel data kompas
int compassFront[] = {355, 90, 176, 255};     //value untuk kompass saat hadap depan (diurut dari utara, timur, selatan, barat)
int compassStart = compassFront[2];           //variabel kompas awal, menghadap selatan

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readCompass();
}

void readCompass() {
  //  int smoothing = 10;
  int tempt = 0;
  //  int total = 0;
  //  aku matiin smoothingnya
  //  for (int i = 0; i < smoothing; i++) {

  //read data compass
  Wire.beginTransmission(cmpsAddress);
  Wire.write(1); // Read dari Register 1
  Wire.endTransmission();

  Wire.requestFrom(cmpsAddress, 3); // Request 3 Byte
  while (Wire.available() < 3);
  Wire.read();
  highBytes = Wire.read(); // REG 2
  lowBytes = Wire.read();  // REG 3

  tempt = highBytes;                 // Calculate 16 bit angle
  tempt <<= 8;
  tempt += lowBytes;
  tempt /= 10;

  //    total += tempt;
  //  }

  compassVal = tempt;

  Serial.println (compassVal);
  
  //hitung perbedaan kompas dan sudut start kompas
  //btw ini harusnya kebalik (compassStart - compassVal) tapi kalo mau dibalik, sesuaiin sama program di kakinya juga
  compassOffset = compassVal - compassStart;

  //batasi kalau offset lebih dari 200, biar cari jalan sebaliknya
  //ini juga sesuaiin kalo mau dibalik
  if (compassStart == compassFront[0]) {
    if (compassOffset > 200) compassOffset = (360 + compassFront[0] - compassVal) * -1;
    else if (compassOffset < -200) compassOffset = 360 - compassFront[0] + compassVal;
  }

  // batasin sudut offset biar putaran robot gak keterlaluan
  if (compassOffset > 30) compassOffset = 30;
  else if (compassOffset < -30) compassOffset = -30;
}
