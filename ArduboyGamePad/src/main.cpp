#include <Arduino.h>

#include <Arduboy2.h>
#include <SwitchControlLibrary.h>

#include "ControllerBitMap.h"

Arduboy2 arduboy;
SwitchControlLibrary_ switchCon; //消すとコントローラーとして認識されない, ボタン1個ずつ動作する

void PressedButton(){ 
  switchCon.clearReport();
  
  if(arduboy.pressed(RIGHT_BUTTON)){
    arduboy.print("->");
    arduboy.drawBitmap(OffsetForHatRight.x, OffsetForHatRight.y, PressedHatRightBitMap, PressedHatRightSize.width, PressedHatRightSize.heigh, WHITE);
    switchCon.pressHatButton(HatButton::RIGHT);
  }
  if(arduboy.pressed(LEFT_BUTTON)){
    arduboy.print("<-");
    arduboy.drawBitmap(OffsetForHatLeft.x, OffsetForHatLeft.y, PressedHatLeftBitMap, PressedHatLeftSize.width, PressedHatLeftSize.heigh, WHITE);
    switchCon.pressHatButton(HatButton::LEFT);
  }
  if(arduboy.pressed(UP_BUTTON)){   
    arduboy.print("^");
    arduboy.drawBitmap(OffsetForHatUp.x, OffsetForHatUp.y, PressedHatUpBitMap, PressedHatUpSize.width, PressedHatUpSize.heigh, WHITE);
    switchCon.pressHatButton(HatButton::UP);
  }
  if(arduboy.pressed(DOWN_BUTTON)){
    arduboy.print("v");
    arduboy.drawBitmap(OffsetForHatDown.x, OffsetForHatDown.y, PressedHatDownBitMap, PressedHatDownSize.width, PressedHatDownSize.heigh, WHITE);
    switchCon.pressHatButton(HatButton::DOWN);
  }
  if(arduboy.pressed(A_BUTTON)){
    arduboy.print("B");
    arduboy.drawBitmap(OffsetForBbutton.x, OffsetForBbutton.y, PressedButtonBitMap, PressedButtonSize.width, PressedButtonSize.heigh, WHITE);
    switchCon.pressButton(Button::B); // switchの配置に準拠
  }
  if(arduboy.pressed(B_BUTTON)){
    arduboy.print("A");
    arduboy.drawBitmap(OffsetForAbutton.x, OffsetForBbutton.y, PressedButtonBitMap, PressedButtonSize.width, PressedButtonSize.heigh, WHITE);
    switchCon.pressButton(Button::A); // switchの配置に準拠
  }

  if(arduboy.pressed(A_BUTTON)&&arduboy.pressed(B_BUTTON)){
    if(arduboy.pressed(UP_BUTTON) && arduboy.pressed(LEFT_BUTTON)){  
      switchCon.clearReport();
      arduboy.print("-");
      arduboy.drawBitmap(OffsetForSelect.x, OffsetForSelect.y, PressedSubButtonBitMap, PressedSubButtonSize.width, PressedSubButtonSize.heigh, WHITE);
      switchCon.pressButton(Button::MINUS);
    }
    if(arduboy.pressed(DOWN_BUTTON) && arduboy.pressed(RIGHT_BUTTON)){
      switchCon.clearReport();
      arduboy.print("+");
      arduboy.drawBitmap(OffsetForStart.x, OffsetForStart.y, PressedSubButtonBitMap, PressedSubButtonSize.width, PressedSubButtonSize.heigh, WHITE);
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
    
  arduboy.drawBitmap(0, 0, ControllerBitMap, ControllerSize.width, ControllerSize.heigh, WHITE); 

 if(arduboy.anyPressed(arduboy.buttonsState())){
  arduboy.setCursor(4, 54);
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
 
