#include "vkobjectfactory.h"
#include "ivkobject.h"
#include "audio.h"
#include "photo.h"
#include "message.h"
#include "account.h"
#include "user.h"
#include "Error.h"

VKObjectFactory::VKObjectFactory()
{
}

MessageAttachments VKObjectFactory::buildMessageAttachments(nlohmann::json json, int size)
{
    if(json.is_array())
    {
        MessageAttachments attachments(size);
        int pos = 0;
        for(auto it : json)
        {
            std::string type = it["type"];
            if(!type.compare("audio"))
            {
                attachments.objects[pos++] = buildAudio(it["audio"]);
            }
            else if(!type.compare("photo"))
            {
                attachments.objects[pos++] = buildObject<Photo>(it["photo"]);
            }
            else
                attachments.objects[pos++] = nullptr;
        }
        return attachments;
    }
    else throw ErrorCode::JSON_TYPE_NOT_MATCH;
}

std::shared_ptr<IVKObject> VKObjectFactory::build(nlohmann::json json)
{
    return nullptr;
}

std::shared_ptr<Audio> VKObjectFactory::buildAudio(nlohmann::json json)
{
    Audio * audio = new Audio();
    for(VKValue v : audio->values)
    {
        nlohmann::json::const_iterator it = json.find(v.getKey());
        if(it != json.end())
        {
            if(v.isBool())
            {
                int i = it.value();
                v.getBool() = i != 0;
            }
            else if(v.isInt())
                v.getInt() = it.value();
            else if(v.isString())
                v.getString() = it.value();
            else if(v.isTime())
                v.getTime() = it.value();
        }
    }
    std::shared_ptr<Audio> ptr(audio);
    return ptr;
}

std::shared_ptr<User> VKObjectFactory::buildUser(nlohmann::json json)
{
    User * user = new User();
    for(VKValue v : user->values)
    {
        nlohmann::json::const_iterator it = json.find(v.getKey());
        if(it != json.end())
        {
            if(v.isBool())
            {
                int i = it.value();
                v.getBool() = i != 0;
            }
            else if(v.isInt())
                v.getInt() = it.value();
            else if(v.isString())
                v.getString() = it.value();
            else if(v.isTime())
                v.getTime() = it.value();
        }
    }
    std::shared_ptr<User> ptr(user);
    return ptr;
}

std::shared_ptr<Message> VKObjectFactory::buildMessage(nlohmann::json json)
{
    Message * message = new Message();
    for(VKValue v : message->values)
    {
        nlohmann::json::const_iterator it = json.find(v.getKey());
        if(it != json.end())
        {
            if(v.isBool())
            {
                int i = it.value();
                v.getBool() = i != 0;
            }
            else if(v.isInt())
                v.getInt() = it.value();
            else if(v.isString())
                v.getString() = it.value();
            else if(v.isTime())
                v.getTime() = it.value();
        }
    }
    nlohmann::json::const_iterator attach = json.find("attachments");
    if(attach != json.end())
    {
        nlohmann::json a = attach.value();
        message->attachments = buildMessageAttachments(a, a.size());
    }
    std::shared_ptr<Message> ptr(message);
    return ptr;
}

std::shared_ptr<Account> VKObjectFactory::buildAccount(nlohmann::json json)
{
    Account * account = new Account();
    for(VKValue v : account->values)
    {
        nlohmann::json::const_iterator it = json.find(v.getKey());
        if(it != json.end())
        {
            if(v.isBool())
                v.getBool() = it.value();
            else if(v.isInt())
                v.getInt() = it.value();
            else if(v.isString())
                v.getString() = it.value();
            else if(v.isTime())
                v.getTime() = it.value();
        }
    }
    std::shared_ptr<Account> ptr(account);
    return ptr;
}

nlohmann::json VKObjectFactory::toJSON(std::shared_ptr<Account> prt)
{
    nlohmann::json json;
    for(VKValue &v : prt->values)
    {
        if(v.isBool())
            json[v.getKey()] = v.getBool();

        else if(v.isInt())
            json[v.getKey()] = v.getInt();

        else if(v.isString())
            json[v.getKey()] = v.getString().c_str();

        else if(v.isTime())
            json[v.getKey()] = v.getTime();
    }
    return json;
}

template <typename IVKO>
std::shared_ptr<IVKO> VKObjectFactory::buildObject(nlohmann::json json)
{
    IVKO * object = new IVKO();
    for(VKValue &v : object->values)
    {
        nlohmann::json::const_iterator it = json.find(v.getKey());
        if(it != json.end())
        {
            if(v.isBool())
                v.getBool() = it.value();
            else if(v.isInt())
                v.getInt() = it.value();
            else if(v.isString())
                v.getString() = it.value();
            else if(v.isTime())
                v.getTime() = it.value();
        }
    }
    std::shared_ptr<IVKO> ptr(object);
    return ptr;
}
