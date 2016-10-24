#include "message.h"

Message::Message() :
    attachments(0)
{
    values[0] = VKValue(id, "id");
    values[1] = VKValue(user_id, "user_id");
    values[2] = VKValue(from_id, "from_id");
    values[3] = VKValue(date, "date");
    values[4] = VKValue(read_state, "read_state");
    values[5] = VKValue(out, "out");
    values[6] = VKValue(title, "title");
    values[7] = VKValue(body, "body");
    values[8] = VKValue(emoji, "emoji");
    values[9] = VKValue(important, "important");
    values[10] = VKValue(deleted, "deleted");
    values[11] = VKValue(random_id, "random_id");
}
