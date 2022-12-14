#pragma once

#include<Arduino.h>

struct ImageSize{
    size_t width;
    size_t heigh;
};

struct PositionOffset
{
    int8_t x;
    int8_t y;
};


PROGMEM constexpr unsigned char ControllerBitMap[] = {
    0xff, 0x01, 0x01, 0x81, 0x61, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xe1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xbd, 0x81, 0xbd, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x18, 0x88, 0x48, 0x28, 0x28, 0x48, 0x88, 0x18, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x18, 0x88, 0x48, 0x28, 0xe8, 0x08, 0x08, 0x08, 0x0f, 0xc0, 0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 0xc0, 0x0f, 0x08, 0x08, 0x08, 0xe8, 0x28, 0x48, 0x88, 0x18, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0xc0, 0x40, 0x80, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xbe, 0xaa, 0xb4, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbc, 0x8a, 0xbc, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x18, 0x11, 0x12, 0x14, 0x17, 0x10, 0x10, 0x10, 0xf0, 0x03, 0x04, 0x08, 0x08, 0x08, 0x08, 0x04, 0x03, 0xf0, 0x10, 0x10, 0x10, 0x17, 0x14, 0x12, 0x11, 0x18, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x18, 0x88, 0x8a, 0x4b, 0x48, 0x48, 0x4b, 0x4a, 0x48, 0x48, 0x4b, 0x88, 0x88, 0x08, 0x08, 0x08, 0x8a, 0x8b, 0x48, 0x48, 0x4b, 0x49, 0x4a, 0x48, 0x48, 0x4b, 0x88, 0x88, 0x18, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0xf0, 0x00, 0x00, 0xf8, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xe9, 0x89, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x1f, 0x30, 0x23, 0x25, 0x29, 0x29, 0x25, 0x23, 0x30, 0x1f, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x0f, 0x08, 0x08, 0x11, 0x11, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x11, 0x11, 0x10, 0x10, 0x10, 0x11, 0x11, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x11, 0x11, 0x18, 0x08, 0x0f, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x09, 0x02, 0x04, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x04, 0x03, 0x08, 0x09, 0x09, 0x09, 0x02, 0x04, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x14, 0x13, 0x10, 0x12, 0x12, 0x12, 0x92, 0x7f, 0x00, 0x00, 0xff, 0x0f, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x0f, 
};

PROGMEM constexpr unsigned char PressedButtonBitMap[] ={
    0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 
};

PROGMEM constexpr unsigned char PressedHatUpBitMap[] = {
    0x0c, 0x0e, 0x0f, 0x0f, 0x0e, 0x0c, 
};

PROGMEM constexpr unsigned char PressedHatDownBitMap[] = {
    0x03, 0x07, 0x0f, 0x0f, 0x07, 0x03, 
};

PROGMEM constexpr unsigned char PressedHatRightBitMap[] = {
    0x3f, 0x3f, 0x1e, 0x0c, 
};

PROGMEM constexpr unsigned char PressedHatLeftBitMap[] = {
    0x0c, 0x1e, 0x3f, 0x3f, 
};

PROGMEM constexpr unsigned char PressedSubButtonBitMap[] = {
    0x06, 0x06, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x06, 0x06, 
};


constexpr ImageSize ControllerSize          = {128, 52};
constexpr ImageSize PressedButtonSize       = {14, 14};
constexpr ImageSize PressedHatUpSize        = {6, 4};
constexpr ImageSize PressedHatDownSize      = {6, 4};
constexpr ImageSize PressedHatRightSize     = {4, 6};
constexpr ImageSize PressedHatLeftSize      = {4, 6};
constexpr ImageSize PressedSubButtonSize    = {12, 4};


constexpr PositionOffset OffsetForAbutton   = {106, 31};
constexpr PositionOffset OffsetForBbutton   = {90, 31};
constexpr PositionOffset OffsetForHatUp     = {22, 21};
constexpr PositionOffset OffsetForHatDown   = {22, 40};
constexpr PositionOffset OffsetForHatRight  = {33, 29};
constexpr PositionOffset OffsetForHatLeft   = {13, 29};
constexpr PositionOffset OffsetForSelect    = {53, 38};
constexpr PositionOffset OffsetForStart     = {68, 38};

