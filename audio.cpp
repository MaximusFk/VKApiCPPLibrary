#include "audio.h"

Audio::Audio()
{
    values[0] = VKValue(id, "id");
    values[1] = VKValue(owner_id, "owner_id");
    values[2] = VKValue(artist, "artist");
    values[3] = VKValue(title, "title");
    values[4] = VKValue(duration, "duration");
    values[5] = VKValue(uri, "url");
    values[6] = VKValue(lyrics_id, "lyrics_id");
    values[7] = VKValue(album_id, "album_id");
    values[8] = VKValue(genre_id, "genre_id");
    values[9] = VKValue(date, "date");
    values[10] = VKValue(no_search, "no_search");
}

int compute_minutes(int time, int & seconds)
{
    int minute = static_cast<int>(time / 60);
    seconds = time - minute * 60;
    return minute;
}
