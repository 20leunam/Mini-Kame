#include <Arduino.h>
#include <Servo.h>
#include "minikame.h"
#include <Octosnake.h>

MiniKame robot;

bool running = 0;

int orden = 0;
int movimiento = 100;

void setup() {

  robot.init();
  Serial.begin(9600);

 // delay(500);
}

void loop() {

  if (Serial.available() > 0) {

    orden = Serial.read();
    Serial.print("I received: ");
    Serial.println(orden, DEC);
  }
  // este else es potencialmente comentable. es para que pare si no recibe nada por serial
  // dicho esto se modificara en funcion de como responda desde el movil
  else{
    orden = 0;
  }

// nada que decir, es el switch principal, cada numero se corresponde a una letra de teclado en codigo ascii que es lo que recive por bluethooth.

  switch (orden) {

     case 119: //w---alante
      robot.run(4,430);
      running = 1;
      break;

     case 97:  //a---izquierda
      robot.turnL(1, 430);
      running = 1;
      break;

     case 100: //d---derecha
      robot.turnR(1, 430);
      running = 1;
      break;

     case 115: //s---stop
      //STOP
      running = 0;
      break;

     case 102: //f---flexiones
      robot.pushUp(2, 500);
      break;

     case 99: //c---cangrejo (saltitos)
      robot.upDown(4, 200);
      break;

     case 106: //j---salto
      robot.jump();
      break;

     case 104: //h---hola
      robot.hello();
      break;

     case 109: //m---moonWalkl
      robot.moonwalkL(4,1000);
     
    //  robot.omniWalk(2,1000,true,5);
    //  frontBack();
    
      break;

     case 98: //b---baile
      robot.dance(2, 700);
      break;

case 48: //0---invertir servos
robot.reverseServo(2);
robot.reverseServo(3);
robot.reverseServo(6);
robot.reverseServo(7);
delay (250);
      break;
      

    default:  //posicion inicial
      robot.zero();
      break;
  }
}

