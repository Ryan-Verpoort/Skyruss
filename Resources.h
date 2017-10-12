#ifndef RESOURCES_H
#define RESOURCES_H

#include "Objects.h"
#include "string"

using std::string;

class Resources
{
public:
    Resources(Objects ObjectType, string FilePath);
    Objects GetGameObjectType();
    string GetObjectResourcePath();

private:
    string _ResourcePath;
    Objects _ObjectType;
};

#endif
