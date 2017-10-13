#include "Resources.h"

Resources::Resources(Objects ObjectType, string resourcePath)
{
    _ResourcePath = resourcePath;
    _ObjectType = ObjectType;
}

Objects Resources::GetGameObjectType()
{
    return _ObjectType;
}

string Resources::GetObjectResourcePath()
{
    return _ResourcePath;
}
