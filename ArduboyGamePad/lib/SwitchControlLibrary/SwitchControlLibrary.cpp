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

#include "SwitchControlLibrary.h"

#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x09, 0x05,       //   USAGE (Game Pad)
    0xa1, 0x01,       //   COLLECTION (Application)
    0x15, 0x00,       //   LOGICAL_MINIMUM (0)
    0x25, 0x01,       //   LOGICAL_MAXIMUM (1)
    0x35, 0x00,       //   PHYSICAL_MINIMUM (0)
    0x45, 0x01,       //   PHYSICAL_MAXIMUM (1)
    0x75, 0x01,       //   REPORT_SIZE (1)
    0x95, 0x10,       //   REPORT_COUNT (16)
    0x05, 0x09,       //   USAGE_PAGE (Button)
    0x19, 0x01,       //   USAGE_MINIMUM (1)
    0x29, 0x10,       //   USAGE_MAXIMUM (16)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x25, 0x07,       //   LOGICAL_MAXIMUM (7)
    0x46, 0x3b, 0x01, //   PHYSICAL_MAXIMUM (315)
    0x75, 0x04,       //   REPORT_SIZE (4)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x65, 0x14,       //   UNIT (20)
    0x09, 0x39,       //   USAGE (Hat Switch)
    0x81, 0x42,       //   INPUT (Data,Var,Abs)
    0x65, 0x00,       //   UNIT (0)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x01,       //   INPUT (Cnst,Arr,Abs)
    0x26, 0xff, 0x00, //   LOGICAL_MAXIMUM (255)
    0x46, 0xff, 0x00, //   PHYSICAL_MAXIMUM (255)
    0x09, 0x30,       //   USAGE (X)
    0x09, 0x31,       //   USAGE (Y)
    0x09, 0x32,       //   USAGE (Z)
    0x09, 0x35,       //   USAGE (Rz)
    0x75, 0x08,       //   REPORT_SIZE (8)
    0x95, 0x04,       //   REPORT_COUNT (4)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x06, 0x00, 0xff, //   USAGE_PAGE (Vendor Defined 65280)
    0x09, 0x20,       //   USAGE (32)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x0a, 0x21, 0x26, //   USAGE (9761)
    0x95, 0x08,       //   REPORT_COUNT (8)
    0x91, 0x02,       //   OUTPUT (Data,Var,Abs)
    0xc0              // END_COLLECTION
};

Hat HatState::getHat()
{

    uint8_t hat_button = 0b0000;
    uint8_t i = 0;
    for (auto itr = _hat_button_state.begin(); itr != _hat_button_state.end() && i < 2; ++itr, ++i)
    {
        hat_button |= static_cast<uint8_t>(*itr);
    }

    Hat hat = Hat::NEUTRAL;
    switch (hat_button)
    {
    case 0b0000:
        hat = Hat::NEUTRAL;
        break;
    case 0b0001:
        hat = Hat::UP;
        break;
    case 0b0010:
        hat = Hat::RIGHT;
        break;
    case 0b0011:
        hat = Hat::UP_RIGHT;
        break;
    case 0b0100:
        hat = Hat::DOWN;
        break;
    case 0b0110:
        hat = Hat::DOWN_RIGHT;
        break;
    case 0b1000:
        hat = Hat::LEFT;
        break;
    case 0b1001:
        hat = Hat::UP_LEFT;
        break;
    case 0b1100:
        hat = Hat::DOWN_LEFT;
        break;
    default:
        hat = Hat::NEUTRAL;
        break;
    }


    return hat;
}

HatState::HatState()
{
}

Hat HatState::pressHatButton(HatButton hat_button)
{
    auto itr = std::find(_hat_button_state.begin(), _hat_button_state.end(), hat_button);
    if (itr == _hat_button_state.end())
    {
        _hat_button_state.push_front(hat_button);
    }

    return getHat();
}

Hat HatState::releaseHatButton(HatButton hat_button)
{
    auto itr = std::find(_hat_button_state.begin(), _hat_button_state.end(), hat_button);
    if (itr != _hat_button_state.end())
    {
        _hat_button_state.erase(itr);
    }
    return getHat();
}

SwitchControlLibrary_::SwitchControlLibrary_()
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    CustomHID().AppendDescriptor(&node);

    memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
    _joystickInputData.LX = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.LY = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.RX = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.RY = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.Hat = static_cast<uint8_t>(Hat::NEUTRAL);
}

void SwitchControlLibrary_::sendReport()
{
    CustomHID().SendReport(&_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void SwitchControlLibrary_::clearReport(){
    memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));

    for(int i=0; i<4; i++){
        _hatState.releaseHatButton(static_cast<HatButton>(0x01 << i));
    }

    _joystickInputData.LX = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.LY = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.RX = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.RY = static_cast<uint8_t>(Stick::NEUTRAL);
    _joystickInputData.Hat = static_cast<uint8_t>(Hat::NEUTRAL);
}

void SwitchControlLibrary_::pressButton(Button button)
{
    _joystickInputData.Button |= static_cast<uint16_t>(button);
}

void SwitchControlLibrary_::releaseButton(Button button)
{
    _joystickInputData.Button &= (static_cast<uint16_t>(button) ^ 0xffff);
}

void SwitchControlLibrary_::moveHat(Hat hat)
{
    _joystickInputData.Hat = static_cast<uint8_t>(hat);
}

void SwitchControlLibrary_::pressHatButton(HatButton hat_button)
{
    _joystickInputData.Hat =  static_cast<uint8_t>(_hatState.pressHatButton(hat_button));
}

void SwitchControlLibrary_::releaseHatButton(HatButton hat_button)
{
    _joystickInputData.Hat = static_cast<uint8_t>(_hatState.releaseHatButton(hat_button));
}

void SwitchControlLibrary_::moveLeftStick(uint8_t lx, uint8_t ly)
{
    _joystickInputData.LX = lx;
    _joystickInputData.LY = ly;
}

void SwitchControlLibrary_::moveRightStick(uint8_t rx, uint8_t ry)
{
    _joystickInputData.RX = rx;
    _joystickInputData.RY = ry;
}

SwitchControlLibrary_ &SwitchControlLibrary()
{
    static SwitchControlLibrary_ obj;
    return obj;
}

#endif
