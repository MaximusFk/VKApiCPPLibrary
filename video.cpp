#include "video.h"

Video::Video()
{
    values[0] = VKValue(id, "id");
    values[1] = VKValue(owner_id, "owner_id");
    values[2] = VKValue(title, "title");
    values[3] = VKValue(description, "description");
    values[4] = VKValue(duration, "duration");
    values[5] = VKValue(photo_130, "photo_130");
    values[6] = VKValue(photo_320, "photo_320");
    values[7] = VKValue(photo_640, "photo_640");
    values[8] = VKValue(date, "date");
    values[9] = VKValue(adding_date, "adding_date");
    values[10] = VKValue(views, "views");
    values[11] = VKValue(player, "player");
    values[12] = VKValue(access_key, "access_key");
    values[13] = VKValue(processing, "processing");
    values[14] = VKValue(live, "live");
}
