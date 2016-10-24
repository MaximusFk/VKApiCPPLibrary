#ifndef AUDIO_H
#define AUDIO_H
#include <string>
#include <array>

#include "ivkobject.h"

int compute_minutes(int, int &);

enum class GenreType : u_int16_t
{
    Rock = 1,
    Pop,
    Rap_HipHop,
    EasyListening,
    Dance_House,
    Instrumental,
    Metal,
    Dubstep,
    DrumAndBuss = 10,
    Trance,
    Chanson,
    Ethnic,
    Acoustic_Vocal,
    Reggae,
    Classical,
    IndiePop,
    Other,
    Speech,
    Alternative = 21,
    ElectroPop_Disco,
    Jazz_Blues = 1001
};

class Audio : virtual public IVKObject
{
    friend class VKObjectFactory;
private:
    int owner_id;
    std::string artist;
    std::string title;
    int duration;
    std::string uri;
    int lyrics_id;
    int album_id;
    int genre_id;
    time_t date;
    bool no_search;

    std::array<VKValue, 11> values;

    Audio();
public:
    Audio(const Audio &) = default;

    int getOwnerId() const
    {
        return owner_id;
    }
    std::string getArtist() const
    {
        return artist;
    }
    std::string getTitle() const
    {
        return title;
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
        return duration - (getDurationMM() * 60);
    }
    std::string getURI() const
    {
        return uri;
    }
    int getLyricsId() const
    {
        return lyrics_id;
    }
    int getGenreId() const
    {
        return genre_id;
    }
    GenreType getGenreType() const
    {
        return static_cast<GenreType>(genre_id);
    }
    time_t getDate() const
    {
        return date;
    }
    bool isNoSearch() const
    {
        return no_search;
    }


///Overrides:
    virtual ObjectType getType() const override
    {
        return ObjectType::AUDIO;
    }
};

#endif // AUDIO_H
