#ifndef IVKOBJECT_H
#define IVKOBJECT_H
#include <memory>
#include <array>

enum class ObjectType {
    USER,
    GROUP,
    PHOTO,//
    STICKER,
    AUDIO,//
    VIDEO,//
    DOCUMENT,
    POST,
    MESSAGE,//
    CHAT,
    COMMENT,
    NOTE,
    PAGE,
    MARKET_ITEM,
    MARKET_ALBUM
};

const char * type_to_cstring(ObjectType);

class VKObjectFactory;

using ref_factory = std::shared_ptr<VKObjectFactory>;

class IVKObject
{
    friend class VKObjectFactory;
protected:
    ref_factory Factory;
    int id;
public:
    virtual int getId();
    virtual ObjectType getType() const = 0;
};

class VKValue final
{

    friend class Audio;
    friend class Account;
    friend class Message;
    friend class Photo;
    friend class Video;
    friend class User;
    friend class Sticker;

    int * ivalue = nullptr;
    std::string * svalue = nullptr;
    bool * bvalue = nullptr;
    time_t * tvalue = nullptr;

    const char * key;
public:
    VKValue() : ivalue(nullptr), svalue(nullptr), bvalue(nullptr), tvalue(nullptr){}

protected:
    VKValue(int & i, const char * key) : ivalue(&i), key(key){}
    VKValue(std::string & s, const char * key) : svalue(&s), key(key){}
    VKValue(bool & b, const char * key) : bvalue(&b), key(key){}
    VKValue(time_t & t, const char * key) : tvalue(&t), key(key){}
public:

    bool isInt()
    {
        return ivalue != nullptr;
    }

    bool isString()
    {
        return svalue != nullptr;
    }

    bool isBool()
    {
        return bvalue != nullptr;
    }

    bool isTime()
    {
        return tvalue != nullptr;
    }

    const char * getKey()
    {
        return key;
    }

    int & getInt()
    {
        return *ivalue;
    }

    std::string & getString()
    {
        return *svalue;
    }

    bool & getBool()
    {
        return *bvalue;
    }

    time_t & getTime()
    {
        return *tvalue;
    }
};

#endif // IVKOBJECT_H
