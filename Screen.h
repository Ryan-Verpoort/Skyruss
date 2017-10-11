#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public:
    Screen(float Width, float Height);

    float getScreenWidth() const;
    float getScreenHeight() const;
    float getScreenCentreX() const;
    float getScreenCentreY() const;
    float getObjectRadius() const;

private:
    float _ScreenWidth;
    float _ScreenHeight;
    float _ScreenCentreX;
    float _ScreenCentreY;
    float _ObjectRadius;
};

#endif