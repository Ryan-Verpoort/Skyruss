#ifndef RESOURCES_H
#define RESOURCES_H

#include "Objects.h"
#include "string"

using std::string;

class Resources
{
public:
    Resources(Objects ObjectType, string FilePath);
    Objects getEntityID();
    string getResourcePath();

private:
    string _FilePath;
    Objects _ObjectType;
};

#endif
