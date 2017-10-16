#ifndef SCREEN_H
#define SCREEN_H
/**
 * @class Screen
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file Screen.h
 * @brief Screen Rendering class
 *
 * Responsible for setting the physical dimensions of the screen  render window
 * Responsible for providing the pysical screen size to call functions from other classes in order to properly display
 * the game
 * during run-time
 * Also responsible for setting and providing to other class member functions the centre of the screen to be passed into
 * the Player and Enemy objects
 */
class Screen
{
public:
    /**
     * @brief Default Screen Constructor
     *
     * Allows for the creation of the screen rendering objects responsible for setting and providing the physical
     * height, width and centre of the screen'
     * Sets the centre of the sceen as well as the screen radius to properly display all objects on the screen
     * @param Width
     * @param Height
     */
    Screen(float Width, float Height);

    /**
     * @brief Returns the width of the Screen
     * @return _ScreenWidth
     */
    float getScreenWidth() const;

    /**
     * @brief Returns the height of the Screen
     * @return _ScreenHeight
     */
    float getScreenHeight() const;

    /**
     * @brief Returns the centre x-position of the screen
     * @return _ScreenCentreX
     */
    float getScreenCentreX() const;

    /**
     * @brief Returns the centre y-position of the screen
     * @return _ScreenCentreY
     */
    float getScreenCentreY() const;

    /**
     * @brief Returns the object radius
     * @return _ObjectRadius
     */
    float getObjectRadius() const;

private:
    float _ScreenWidth;
    float _ScreenHeight;
    float _ScreenCentreX;
    float _ScreenCentreY;
    float _ObjectRadius;
};

#endif