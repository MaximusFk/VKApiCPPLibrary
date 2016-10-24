#ifndef PHOTO_H
#define PHOTO_H
#include "ivkobject.h"

class Photo : public IVKObject
{
    friend class VKObjectFactory;

    int album_id;
    int owner_id;
    int user_id;
    std::string text;
    time_t date;
    std::string photo_75;
    std::string photo_130;
    std::string photo_604;
    std::string photo_807;
    std::string photo_1280;
    std::string photo_2560;

    std::array<VKValue, 12> values;
public:
    Photo();

    int getAlbumId() const
    {
        return album_id;
    }

    int getOwnerId() const
    {
        return owner_id;
    }

    int getUserId() const
    {
        return user_id;
    }

    std::string getText() const
    {
        return text;
    }

    time_t getDate() const
    {
        return date;
    }

    std::string getPhoto75() const
    {
        return photo_75;
    }

    std::string getPhoto130() const
    {
        return photo_130;
    }

    std::string getPhoto604() const
    {
        return photo_604;
    }

    std::string getPhoto807() const
    {
        return photo_807;
    }

    std::string getPhoto1280() const
    {
        return photo_1280;
    }

    std::string getPhoto2560() const
    {
        return photo_2560;
    }

/// Overrides:
    virtual ObjectType getType() const override
    {
        return ObjectType::PHOTO;
    }
};

class Sticker : public IVKObject
{
    friend class VKObjectFactory;

    int product_id;
    std::string photo_64;
    std::string photo_128;
    std::string photo_256;
    std::string photo_352;
    int width;
    int height;

    std::array<VKValue, 8> values;

public:
    Sticker();

    int getProductId() const
    {
        return product_id;
    }

    std::string getPhoto64() const
    {
        return photo_64;
    }

    std::string getPhoto128() const
    {
        return photo_128;
    }

    std::string getPhoto256() const
    {
        return photo_256;
    }

    std::string getPhoto352() const
    {
        return photo_352;
    }

    int getWidth() const
    {
        return width;
    }

    int getHeigth() const
    {
        return height;
    }

/// Overrides:
    virtual ObjectType getType() const override
    {
        return ObjectType::STICKER;
    }
};

#endif // PHOTO_H
