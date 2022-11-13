#include <Arduino.h>

#include <Arduboy2.h>
#include <SwitchControlLibrary.h>

#include "ControllerBitMap.h"

Arduboy2 arduboy;
SwitchControlLibrary_ switchCon; //消すとコントローラーとして認識されない, ボタン1個ずつ動作する

void PressedButton(){ 
  switchCon.clearReport();

  if(arduboy.pressed(A_BUTTON)&&arduboy.pressed(B_BUTTON) 
    && (arduboy.pressed(UP_BUTTON) && arduboy.pressed(LEFT_BUTTON))){
      switchCon.clearReport();
      arduboy.drawBitmap(OffsetForSelect.x, OffsetForSelect.y, PressedSubButtonBitMap, PressedSubButtonSize.width, PressedSubButtonSize.heigh, WHITE);
      switchCon.pressButton(Button::MINUS);
  }

  else if((arduboy.pressed(A_BUTTON)&&arduboy.pressed(B_BUTTON))
    &&(arduboy.pressed(DOWN_BUTTON) && arduboy.pressed(RIGHT_BUTTON))){
      switchCon.clearReport();
      arduboy.drawBitmap(OffsetForStart.x, OffsetForStart.y, PressedSubButtonBitMap, PressedSubButtonSize.width, PressedSubButtonSize.heigh, WHITE);
      switchCon.pressButton(Button::PLUS);
  }

  else{
    if(arduboy.pressed(RIGHT_BUTTON)){
      arduboy.drawBitmap(OffsetForHatRight.x, OffsetForHatRight.y, PressedHatRightBitMap, PressedHatRightSize.width, PressedHatRightSize.heigh, WHITE);
      switchCon.pressHatButton(HatButton::RIGHT);
    }
    if(arduboy.pressed(LEFT_BUTTON)){
      arduboy.drawBitmap(OffsetForHatLeft.x, OffsetForHatLeft.y, PressedHatLeftBitMap, PressedHatLeftSize.width, PressedHatLeftSize.heigh, WHITE);
      switchCon.pressHatButton(HatButton::LEFT);
    }
    if(arduboy.pressed(UP_BUTTON)){
      arduboy.drawBitmap(OffsetForHatUp.x, OffsetForHatUp.y, PressedHatUpBitMap, PressedHatUpSize.width, PressedHatUpSize.heigh, WHITE);
      switchCon.pressHatButton(HatButton::UP);
    }
    if(arduboy.pressed(DOWN_BUTTON)){
      arduboy.drawBitmap(OffsetForHatDown.x, OffsetForHatDown.y, PressedHatDownBitMap, PressedHatDownSize.width, PressedHatDownSize.heigh, WHITE);
      switchCon.pressHatButton(HatButton::DOWN);
    }
    if(arduboy.pressed(A_BUTTON)){
      arduboy.drawBitmap(OffsetForBbutton.x, OffsetForBbutton.y, PressedButtonBitMap, PressedButtonSize.width, PressedButtonSize.heigh, WHITE);
      switchCon.pressButton(Button::B); // switchの配置に準拠
    }
    if(arduboy.pressed(B_BUTTON)){
      arduboy.drawBitmap(OffsetForAbutton.x, OffsetForBbutton.y, PressedButtonBitMap, PressedButtonSize.width, PressedButtonSize.heigh, WHITE);
      switchCon.pressButton(Button::A); // switchの配置に準拠
    }
  }
  
  switchCon.sendReport();
}

void setup() {
  arduboy.boot();
  arduboy.display();
  arduboy.flashlight();

  arduboy.waitNoButtons();
}

void loop() {
  if (!(arduboy.nextFrame())){
    return;
  }
  
  arduboy.clear();
  
  // 画面上にコントローラーを表示
  arduboy.drawBitmap(0, 0, ControllerBitMap, ControllerSize.width, ControllerSize.heigh, WHITE); 

  // ボタンの入力処理
  if(arduboy.anyPressed(arduboy.buttonsState())){
    PressedButton();
  }
  else{
    switchCon.clearReport();
    switchCon.sendReport();
  }

  // 下部テキスト 
  arduboy.setCursor(4, 56);
  arduboy.print("-:^+<+A+B");
  arduboy.println("  +:v+>+A+B");

  arduboy.display();
} 
 
