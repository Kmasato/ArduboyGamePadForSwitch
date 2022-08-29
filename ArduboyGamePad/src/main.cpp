#include <Arduino.h>

#include <Arduboy2.h>
#include <SwitchControlLibrary.h>

Arduboy2 arduboy;
SwitchControlLibrary_ switchCon; //消すとコントローラーとして認識されない, ボタン1個ずつ動作する

void PressedButton(){ 
  switchCon.clearReport();
  
  if(arduboy.pressed(RIGHT_BUTTON)){
    arduboy.print("->");
    switchCon.pressHatButton(HatButton::RIGHT);
  }
  if(arduboy.pressed(LEFT_BUTTON)){
    arduboy.print("<-");
    switchCon.pressHatButton(HatButton::LEFT);
  }
  if(arduboy.pressed(UP_BUTTON)){   
    arduboy.print("^");
    switchCon.pressHatButton(HatButton::UP);
  }
  if(arduboy.pressed(DOWN_BUTTON)){
    arduboy.print("v");
    switchCon.pressHatButton(HatButton::DOWN);
  }
  if(arduboy.pressed(A_BUTTON)){
    arduboy.print("B");
    switchCon.pressButton(Button::B); // switchの配置に準拠
  }
  if(arduboy.pressed(B_BUTTON)){
    arduboy.print("A");
    switchCon.pressButton(Button::A); // switchの配置に準拠
  }

  if(arduboy.pressed(A_BUTTON)&&arduboy.pressed(B_BUTTON)){
    if(arduboy.pressed(UP_BUTTON) && arduboy.pressed(LEFT_BUTTON)){
      switchCon.clearReport();
      arduboy.print("-");
      switchCon.pressButton(Button::MINUS);
    }
    if(arduboy.pressed(DOWN_BUTTON) && arduboy.pressed(RIGHT_BUTTON)){
      switchCon.clearReport();
      arduboy.print("+");
      switchCon.pressButton(Button::PLUS);
    }
  }
  switchCon.sendReport();
}

void setup() {
  arduboy.boot();
  arduboy.display();
  arduboy.flashlight();

  arduboy.bootLogo();

  arduboy.waitNoButtons();

  //Serial.begin(9600);
}

void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // first we clear our screen to black
  arduboy.clear();

 if(arduboy.anyPressed(arduboy.buttonsState())){
  arduboy.setCursor(4, 9);
  //Serial.print("Pressed:");
  PressedButton();
 }
 else{
  switchCon.clearReport();
  switchCon.sendReport();
 }


  // then we finally we tell the arduboy to display what we just wrote to the display
  arduboy.display();
} 
 
