#include "photo.h"

Photo::Photo()
{
    values[0] = VKValue(id, "id");
    values[1] = VKValue(album_id, "album_id");
    values[2] = VKValue(owner_id, "owner_id");
    values[3] = VKValue(user_id, "user_id");
    values[4] = VKValue(text, "text");
    values[5] = VKValue(date, "date");
    values[6] = VKValue(photo_75, "photo_75");
    values[7] = VKValue(photo_130, "photo_130");
    values[8] = VKValue(photo_604, "photo_604");
    values[9] = VKValue(photo_807, "photo_807");
    values[10] = VKValue(photo_1280, "photo_1280");
    values[11] = VKValue(photo_2560, "photo_2560");
}

Sticker::Sticker()
{
    values[0] = VKValue(id, "id");
    values[1] = VKValue(product_id, "product_id");
    values[2] = VKValue(photo_64, "photo_64");
    values[3] = VKValue(photo_128, "photo_128");
    values[4] = VKValue(photo_256, "photo_256");
    values[5] = VKValue(photo_352, "photo_352");
    values[6] = VKValue(width, "width");
    values[7] = VKValue(height, "height");
}
