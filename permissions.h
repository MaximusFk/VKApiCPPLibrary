#ifndef PERMISSIONS_H
#define PERMISSIONS_H

enum class VKApiPermissions
{
    notify = 1,
    friends = 2,
    photos = 4,
    audio = 8,
    video = 16,
    offers = 32,
    questions = 64,
    pages = 128,
    applink = 256,
    status = 1024,
    notes = 2048,
    messages = 4096,
    wall = 8192,
    ads = 32768,
    offline = 65536,
    docs = 131072,
    groups = 262144,
    notifications = 524288,
    stats = 1048576,
    email = 4194304,
    market = 135217728
};

inline static int operator | (VKApiPermissions t1, VKApiPermissions t2)
{
    return static_cast<int>(t1) | static_cast<int>(t2);
}

inline static int operator | (int t1, VKApiPermissions t2)
{
    return t1 | static_cast<int>(t2);
}

inline static int operator | (VKApiPermissions t1, int t2)
{
    return static_cast<int>(t1) | t2;
}

#endif // PERMISSIONS_H
