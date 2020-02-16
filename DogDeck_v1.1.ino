/*DogDeck v1.1
* © Hwoadog Engineering
* Feb 15, 2020
* 
* If you paid for it, you did well !
* 
* Wiring : https://tinyurl.com/dogdeckv1-1
*/

#include <KeyboardFR.h>

const int BUSYDOG = 3;
const int READYDOG = 5;
const int ANGRYDOG = 6;
const int DOGFECT = 7;
const int RANDOG = 8;
const int HOTDOG = 9;
const int resMin = 1;
const int resMax = 6;
const int pause = 1000;
int result;
int lastResult = 0;
int angry = 0;

void setup(){
  pinMode(HOTDOG, INPUT);
  pinMode(RANDOG, INPUT);
  pinMode(DOGFECT, INPUT);
  pinMode(ANGRYDOG, INPUT);
  pinMode(BUSYDOG, OUTPUT);
  pinMode(READYDOG, OUTPUT);
}

void TAUNT1(){
  Keyboard.begin();
  Keyboard.println("aux chioutes cloumphy :hamid:");
  delay(pause);
  Keyboard.end();
}
void TAUNT2(){  
  Keyboard.begin();
  Keyboard.println("''*Attack me if you dare... I will dog you !*'' :bobo:");
  delay(100);
  Keyboard.end();
  }
void TAUNT3(){
  Keyboard.begin();
  Keyboard.println(":next: :rot2: :mousse:");
  delay(100);
  Keyboard.end();
  }
void TAUNT4(){
  Keyboard.begin();
  Keyboard.println("check ton stick arcade il a l'air en rade :clint:");
  Keyboard.println("c'pas humain d'en prendre autant dans la gueule :hwoadog:");
  Keyboard.press(130);
  delay(100);
  Keyboard.end();
  }
void TAUNT5(){
  Keyboard.begin();
  Keyboard.println(":jpp:");
  delay(100);
  Keyboard.end();
  }
void TAUNT6(){
  Keyboard.begin();
  Keyboard.println("on fait un cache-cache ?");
  Keyboard.println(":oh::dab:");
  Keyboard.println(":doga:");
  delay(100);
  Keyboard.end();
  }

void ANGRY1(){
  Keyboard.begin();
  Keyboard.println(":sueur:");
  delay(100);
  Keyboard.end();
}
void ANGRY2(){
  Keyboard.begin();
  Keyboard.println(":bobo:");
  delay(100);
  Keyboard.end();
}
void ANGRY3(){
  Keyboard.begin();
  Keyboard.println(":rot2:");
  delay(100);
  Keyboard.end();
}
void ANGRY4(){
  Keyboard.begin();
  Keyboard.println(":rot3:");
  delay(100);
  Keyboard.end();
}
void ANGRY5(){
  Keyboard.begin();
  Keyboard.println(":clint:");
  delay(100);
  Keyboard.end();
}
void ANGRY6(){
  Keyboard.begin();
  Keyboard.println(":gitan:");
  delay(100);
  Keyboard.end();
}
void ANGRY7(){
  Keyboard.begin();
  Keyboard.println(":oh2: ERROR 404 :oh:");
  Keyboard.println("can't lose more than six times in one game.");
  Keyboard.println("check your internet connection and try again.");
  Keyboard.println(":dogb:");
  delay(100);
  Keyboard.end();
}

void loop(){
  digitalWrite(READYDOG, LOW);
  
  if(digitalRead(HOTDOG)) {
    digitalWrite(READYDOG, HIGH);

    if(digitalRead(DOGFECT)) {
      digitalWrite(BUSYDOG, HIGH);
      Keyboard.begin();
      Keyboard.println(":oh: :dab: :oh:");      
      Keyboard.println(":oh:     **DOGFECT**     :oh:");
      Keyboard.println(":oh: :dab: :oh:");
      delay(pause);
      Keyboard.end();
      digitalWrite(BUSYDOG, LOW);
    }
  
    if(digitalRead(RANDOG))  {
      result = random(resMin, resMax);
      while (result == lastResult) {
        result = random(resMin, resMax);
      }
      lastResult = result;
      digitalWrite(BUSYDOG, HIGH);
      if (result == 1){
       TAUNT1();
      }
      if (result == 2){
        TAUNT2();
      }
      if (result == 3){
        TAUNT3();
      }
      if (result == 4){
        TAUNT4();
      }
      if (result == 5){
        TAUNT5();
      }
      if (result == 6){
        TAUNT6();
      }
    delay(pause);
    digitalWrite(BUSYDOG, LOW);
    }

    if(digitalRead(ANGRYDOG)){
    digitalWrite(BUSYDOG, HIGH);
    angry++;
    if(angry == 1){
      ANGRY1();
    }
    if(angry == 2){
      ANGRY2();
    }
    if(angry == 3){
      ANGRY3();
    }
    if(angry == 4){
      ANGRY4();
    }
    if(angry == 5){
      ANGRY5();
    }
    if(angry == 6){
      ANGRY6();
    }
    if(angry > 6){
      ANGRY7();
    }
    delay(pause);
    digitalWrite(BUSYDOG, LOW);
  }
  }
}
