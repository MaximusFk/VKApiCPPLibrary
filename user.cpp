#include "user.h"

User::User()
{
    values[0] = VKValue(id, "id");
    values[1] = VKValue(first_name, "first_name");
    values[2] = VKValue(last_name, "last_name");
    values[3] = VKValue(deactivated, "deactivated");
    values[4] = VKValue(hidden, "hidden");
}
