#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <array>

#include "ivkobject.h"

enum class VKApiPermissions;

class Account
{
    friend class VKObjectFactory;
    friend class MainWindow;
    std::string access_token;
    int user_id;
    int permissions;

    std::array<VKValue, 3> values;

    void parceURL(std::string);
    static int getUserIdFromURL(std::string);
    static std::string getAccessTokenFromURL(std::string);

    Account(int, std::string);
    Account();
public:
    Account(std::string);
    std::string getAccessToken() const
    {
        return access_token;
    }

    int getUserId() const
    {
        return user_id;
    }

    void setPermissions(int);
    void addPermissions(int);
    void addPermissions(VKApiPermissions);

};

struct exception
{
    std::string errorString;
    std::string what;
};

static std::string out;
static const std::string authUrl = "http://oauth.vk.com/authorize?client_id=5537666&scope=audio&redirect_uri=https://oauth.vk.com/blank.html&display=mobile&response_type=token&v=5.56";

#endif // ACCOUNT_H
