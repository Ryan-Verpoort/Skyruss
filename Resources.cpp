#include "Resources.h"

Resources::Resources(Objects ObjectType, string resourcePath)
{
    _FilePath = resourcePath;
    _ObjectType = ObjectType;
}

Objects Resources::getEntityID()
{
    return _ObjectType;
}

string Resources::getResourcePath()
{
    return _FilePath;
}
