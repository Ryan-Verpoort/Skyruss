#include "Screen.h"

Screen::Screen(float Width, float Height)
    : _ScreenWidth(Width)
    , _ScreenHeight(Height)
{
    _ScreenCentreX = _ScreenWidth / 2.0f;
    _ScreenCentreY = _ScreenHeight / 2.0f;
    _ObjectRadius = _ScreenHeight * 0.45;
}

float Screen::getScreenWidth() const
{
    return _ScreenWidth;
}

float Screen::getScreenHeight() const
{
    return _ScreenHeight;
}

float Screen::getScreenCentreX() const
{
    return _ScreenCentreX;
}

float Screen::getScreenCentreY() const
{
    return _ScreenCentreY;
}

float Screen::getObjectRadius() const
{
    return _ObjectRadius;
}