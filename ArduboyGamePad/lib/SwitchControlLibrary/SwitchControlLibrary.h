/*
MIT License

Copyright (c) 2019 celclow

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

https://github.com/celclow/SwitchControlLibrary

*/
#pragma once

#include <ArduinoSTL.h>
#include <list>

#include "CustomHID.h"

enum class Button
{
    Y = 0x0001,
    B = 0x0002,
    A = 0x0004,
    X = 0x0008,
    L = 0x0010,
    R = 0x0020,
    ZL = 0x0040,
    ZR = 0x0080,
    MINUS = 0x0100,
    PLUS = 0x0200,
    LCLICK = 0x0400,
    RCLICK = 0x0800,
    HOME = 0x1000,
    CAPTURE = 0x2000,
};

enum class Hat
{
    UP = 0x00,
    UP_RIGHT = 0x01,
    RIGHT = 0x02,
    DOWN_RIGHT = 0x03,
    DOWN = 0x04,
    DOWN_LEFT = 0x05,
    LEFT = 0x06,
    UP_LEFT = 0x07,
    NEUTRAL = 0x08,
};

enum class HatButton
{
    UP = 0b0001,
    RIGHT = 0b0010,
    DOWN = 0b0100,
    LEFT = 0b1000,
};

enum class Stick
{
    MIN = 0,
    NEUTRAL = 128,
    MAX = 255,
};

typedef struct
{
    uint16_t Button;
    uint8_t Hat;
    uint8_t LX;
    uint8_t LY;
    uint8_t RX;
    uint8_t RY;
    uint8_t VendorSpec;
} USB_JoystickReport_Input_t;

class HatState
{
private:
    std::list<HatButton> _hat_button_state;

    Hat getHat();

public:
    HatState();

    Hat pressHatButton(HatButton hat_button);
    Hat releaseHatButton(HatButton hat_button);
};

class SwitchControlLibrary_
{
private:
    USB_JoystickReport_Input_t _joystickInputData;
    HatState _hatState;

public:
    SwitchControlLibrary_();

    void sendReport();

    void pressButton(Button button);
    void releaseButton(Button button);

    void moveHat(Hat hat);
    void pressHatButton(HatButton hat_button);
    void releaseHatButton(HatButton hat_button);

    void moveLeftStick(uint8_t lx, uint8_t ly);
    void moveRightStick(uint8_t rx, uint8_t ry);

    void clearReport();
};

SwitchControlLibrary_ &SwitchControlLibrary();
  