#ifndef RESOURCES_H
#define RESOURCES_H

#include "Objects.h"
#include <string>

using std::string;

/**
 * @class Resources
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file Resources.h
 * @brief Resources class
 *
 * Provides the directory path needed to load textures and font to be used during run-time
 */
class Resources
{
public:
    /**
     * @brief Default Constructor for Resources Class
     *
     * Allows for the creation of all Resource objects to be used in the GamePresentation class
     * Provide the file path needed to load resources as well as the object type to be loaded
     * @param ObjectType
     * @param FilePath
     */
    Resources(Objects ObjectType, string FilePath);

    /**
     * @brief Returns the object type when loaded from file
     * @return _ObjectType
     */
    Objects GetGameObjectType();

    /**
     * @brief Provides the directory path needed for loading resources
     * @return _ResourcePath
     */
    string GetObjectResourcePath();

private:
    string _ResourcePath;
    Objects _ObjectType;
};

#endif
