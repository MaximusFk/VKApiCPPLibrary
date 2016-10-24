#ifndef VKOBJECTFACTORY_H
#define VKOBJECTFACTORY_H
#include <memory>
#include <string>
#include <fstream>
#include "json.hpp"
class IVKObject;
class Audio;
class Account;
class Message;
class MessageAttachments;
class User;

class VKObjectFactory final
{
    std::string system_path;
    std::fstream stream;
public:
    VKObjectFactory();
private:
    MessageAttachments buildMessageAttachments(nlohmann::json, int);
public:
    std::shared_ptr<IVKObject> build(nlohmann::json);
    std::shared_ptr<Audio> buildAudio(nlohmann::json);
    std::shared_ptr<User> buildUser(nlohmann::json);
    std::shared_ptr<Message> buildMessage(nlohmann::json);
    std::shared_ptr<Account> buildAccount(nlohmann::json);
    nlohmann::json toJSON(std::shared_ptr<Account>);

    template <typename IVKO> std::shared_ptr<IVKO> buildObject(nlohmann::json);

    static std::shared_ptr<VKObjectFactory> buildFactory(std::string);
};

#endif // VKOBJECTFACTORY_H
