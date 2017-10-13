#ifndef OBJECTSPOSITION_H
#define OBJECTSPOSITION_H

/**
 * @class ObjectsPosition
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file ObjectsPosition.h
 * @brief ObjectPostion Class
 *
 * This class provides all information neccessary in determing and setting the location of all objects available during
 *run-time.
 * It is responsible for setting the initial postion of the created object, as well as object specific parameters such
 *as object radius or angle
 *
 *Additionally, it is responsible provding the information it sets to functions using the lacational information of the
 *object during collision detection
 */
class ObjectsPosition
{
public:
    /**
     * @brief Default Constructor for ObjectsPostion class
     */
    ObjectsPosition();

    /**
     * @brief Responsible for setting the initial x-postion of the created object
     * @param InitialX
     */
    void SetInitialX(float InitialX);

    /**
     * @brief Responsible for setting the initial y-postion of the created object
     * @param InitialY
     */
    void SetInitialY(float InitialY);

    /**
     * @brief Responsible for setting the current x-postion of the object at function call
     * @param CurrentX
     */
    void SetCurrentX(float CurrentX);
    /**
     * @brief Responsible for setting the initial y-postion of the object at function call
     * @param CurrentY
     */
    void SetCurrentY(float CurrentY);

    /**
     * @brief Responsible for setting the radius of the created object
     *
     * This function is dependent on the size of the object to created and is texture specific
     * @param Radius
     */
    void setRadius(float Radius);

    /**
     * @brief Responsible for setting the current angle of the created object
     *
     * It is also responsible for overwriting and resetting the current object angle during function call
     * @param Angle
     */
    void setAngle(float Angle);

    /**
     * @brief Responsible for providing the inital x-position of the created object
     * @return
     */
    float GetInitialX() const;

    /**
     * @brief Responsible for providing the inital y-position of the created object
     * @return _InitialX
     */
    float GetInitialY() const;

    /**
     * @brief responsible for provind the current x-postion of the on-screen object being queried
     * @return _CurrentX
     */
    float GetCurrentX() const;

    /**
     * @brief responsible for provind the current y-postion of the on-screen object being queried
     * @return _CurrentY
     */
    float GetCurrentY() const;

    /**
     * @brief Responsible for providing the radius of the quesried object
     * @return _Radius
     */
    float GetRadius() const;

    /**
     * @brief Responsible for providing the current angle of the queried object
     * @return _Angle
     */
    float GetAngle() const;

private:
    float _InitialX;
    float _InitialY;
    float _CurrentX;
    float _CurrentY;
    float _Radius;
    float _Angle;
};

#endif