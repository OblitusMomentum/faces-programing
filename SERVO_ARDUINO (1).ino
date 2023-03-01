#include <SoftwareSerial.h>
#include <Servo.h>

//Declaramos el servo
Servo servo;

//Declaramos la variable
char dato;
int angulo = 90;
int eje1=90;
int eje2=90;
int Led1 = 2;
int Led2 = 4;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  servo.attach(3);
  servo.write(angulo);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop() {
  joystick();
  while(Serial.available()){
    dato = Serial.read();
    delay(10);
    Serial.println(dato);
    switch(dato){
      case 'd':
      //Gira servo hacia la derecha
      angulo = angulo + 2;
      servo.write(angulo);
      break;
      
      case 'i':
      //Gira servo hacia la izquierda
      angulo = angulo - 2;
      servo.write(angulo);
      break;
      
      case 'p':
      //Parar el servo
      angulo = angulo;
      servo.write(angulo);
      break;
      }
   }

 }
void joystick(){
  digitalWrite(Led1, HIGH);

  if(analogRead(0) > 2){
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
  }

  if (analogRead(0)<200 && eje1<180){
    eje1++;
    servo1.write(eje1);
  }

  if (analogRead(0)>700 && eje1>0){
    eje1--;
    servo1.write(eje1);
  }

  delay(15);
}
