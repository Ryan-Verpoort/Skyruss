#include "Screen.h"

Screen::Screen(float Width, float Height)
    : _ScreenWidth(Width)
    , _ScreenHeight(Height)
{
    // Set Screen Centre
    _ScreenCentreX = _ScreenWidth / 2.0f;
    _ScreenCentreY = _ScreenHeight / 2.0f;
    // Set Screen Radius _screen height /2 x 90%  Allow for object to be on screen
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