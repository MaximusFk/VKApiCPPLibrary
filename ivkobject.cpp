#include "ivkobject.h"

const char * type_to_cstring(ObjectType type)
{
    switch(type)
    {
    case ObjectType::AUDIO:
        return "audio";
    case ObjectType::PHOTO:
        return "photo";
    case ObjectType::VIDEO:
        return "video";
    case ObjectType::STICKER:
        return "sticker";
    case ObjectType::USER:
        return "user";
    case ObjectType::MESSAGE:
        return "message";
    default:
        return "";
    }
}

int IVKObject::getId()
{
    return id;
}
