#include "account.h"
#include "permissions.h"

Account::Account(std::string url) :
    Account()
{
    parceURL(url);
}

Account::Account(int id, std::string access) :
    Account()
{
    access_token = access;
    user_id = id;
}

Account::Account()
{
    permissions = 0;
    values[0] = VKValue(access_token, "access_token");
    values[1] = VKValue(user_id, "user_id");
    values[2] = VKValue(permissions, "permissions");
}

void Account::addPermissions(VKApiPermissions perm)
{
    permissions |= static_cast<int>(perm);
}

void Account::addPermissions(int perms)
{
    permissions |= perms;
}

void Account::setPermissions(int perms)
{
    permissions = perms;
}

std::string Account::getAccessTokenFromURL(std::string url)
{
    auto startIndex = url.find("access_token=");
    if(startIndex == std::string::npos)
        return std::string("");
    startIndex += 13;
    auto chars = url.find_first_of('&', startIndex) - startIndex;
    return url.substr(startIndex, chars);
}

int Account::getUserIdFromURL(std::string url)
{
    auto startIndex = url.find("user_id=");
    if(startIndex == std::string::npos)
        return 0;
    startIndex += 8;
    auto f = url.find_first_of('&', startIndex);
    auto chars = (f == std::string::npos ? std::string::npos : f - startIndex);
    url = url.substr(startIndex);
    int r;
    try {
        r = std::stoi(url);
    }
    catch(std::invalid_argument a)
    {
        exception e;
        e.errorString = url;
        e.what = a.what();
        throw e;
    }

    return r;
}

void Account::parceURL(std::string url)
{
    this->user_id = getUserIdFromURL(url);
    this->access_token = getAccessTokenFromURL(url);
}
