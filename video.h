#ifndef VIDEO_H
#define VIDEO_H
#include "ivkobject.h"

class Video : virtual public IVKObject
{
    int owner_id;
    std::string title;
    std::string description;
    int duration;
    std::string photo_130;
    std::string photo_320;
    std::string photo_640;
    time_t date;
    time_t adding_date;
    int views;
    std::string player;
    std::string access_key;
    bool processing;
    bool live;

    std::array<VKValue, 15> values;
public:
    Video();

    int getOwnerId() const
    {
        return owner_id;
    }

    std::string getTitle() const
    {
        return title;
    }

    std::string getDescription() const
    {
        return description;
    }

    int getDuration() const
    {
        return duration;
    }

    int getDurationMM() const
    {
        return duration / 60;
    }

    int getDurationSS() const
    {
        return duration - getDurationMM() * 60;
    }

    std::string getPhoto130Url() const
    {
        return photo_130;
    }

    std::string getPhoto320Url() const
    {
        return photo_320;
    }

    std::string getPhoto640Url() const
    {
        return photo_640;
    }

    time_t getDate() const
    {
        return date;
    }

    time_t getAddingDate() const
    {
        return adding_date;
    }

    int getViewsCount() const
    {
        return views;
    }

    std::string getPlayerUrl() const
    {
        return player;
    }

    std::string getAccessKey() const
    {
        return access_key;
    }

    bool isProcessing() const
    {
        return processing;
    }

    bool isLive() const
    {
        return live;
    }

///Overrides:
    virtual ObjectType getType() const
    {
        return ObjectType::VIDEO;
    }
};

#endif // VIDEO_H
