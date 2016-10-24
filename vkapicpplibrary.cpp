#include "vkapicpplibrary.h"
using namespace VKApi;

const char * VKApi::methodAccess = "https://api.vk.com/method";
const std::string VKApi::apiVersion = "5.53";
const char VKApi::argDelimiter = '&';
const char * VKApi::accessTokenArg = "access_token";
const char * VKApi::defaultRedirect = "https://oauth.vk.com/blank.html";

const std::string audio_prefix = "audio";
constexpr unsigned long audio_id = 1000;
const MethodNode Audio::get(audio_prefix + ".get", {"owner_id", "album_id", "audio_ids", "need_user", "offset", "count"}, audio_id+1);
const MethodNode Audio::getLyrics(audio_prefix + ".getLyrics", {"lyrics_id"}, audio_id+2);

const std::string message_prefix = "messages";
constexpr unsigned long message_id = 2000;
const MethodNode Messages::getMessages(message_prefix + ".get", {"out", "offset", "count", "time_offset", "filters", "preview_length", "last_message_id"}, message_id+1);
const MethodNode Messages::getDialogs(message_prefix + ".getDialogs", {"offset", "count", "start_message_id", "preview_length", "unread"}, message_id+2);
const MethodNode Messages::send(message_prefix + ".send", {"user_id", "random_id", "peer_id", "domain", "chat_id", "user_ids", "message", "lat", "long", "attachment", "forward_messages",
                             "sticker_id", "nitification"}, message_id+3);
const MethodNode Messages::getHistory(message_prefix + ".getHistory", {"user_id", "offset", "count", "peer_id", "start_message_id", "rev"}, message_id+4);

const std::string users_prefix = "users";
constexpr unsigned long users_id = 3000;
const MethodNode Users::get(users_prefix + ".get", {"user_ids", "fields", "name_case"}, users_id+1);

const MethodNode Auth::authorize("authorize", {"client_id", "redirect_uri", "display", "scope", "response_type", "state"}, "https://oauth.vk.com");


VKApiCPPLibrary::VKApiCPPLibrary()
{
}


MethodNode::MethodNode(std::string name, std::initializer_list<std::string> args, unsigned long ID) :
    name(name),
    nodeId(ID)
{
    strings = new std::string[size = args.size()];
            size_t pos = 0;
            for(auto arg : args)
    {
        strings[pos++] = arg;
    }
    method_access = methodAccess;
}

MethodNode::MethodNode(std::string name, std::initializer_list<std::string> args, std::string access, unsigned long ID) :
    MethodNode(name, args, ID)
{
    method_access = access;
}

MethodNode::~MethodNode()
{
    delete [] strings;
}

std::string MethodNode::getMethodName() const
{
    return name;
}

std::string MethodNode::getMethodAccess() const
{
    return method_access;
}

bool MethodNode::hasArg(std::string str) const
{
    for(size_t i = 0; i < size; i++)
        if(!strings[i].compare(str))
            return true;
    return false;
}

unsigned long MethodNode::getMethodNodeID() const
{
    return nodeId;
}

Method MethodNode::createMethod() const
{
    return Method(*this);
}

struct Arg::Impl
{
    std::string name;
    bool need;
    std::string value;
    Impl(std::string str, bool n) : name(str), need(n){}
    Impl(std::string str, bool n, std::string str2) : name(str), need(n), value(str2){}
};

Arg::Arg(std::string name, bool need) : impl(new Arg::Impl(name, need)){}

Arg::Arg(std::string name, std::string value) : impl(new Arg::Impl(name, false, value)){}

Arg::Arg(const char *name) : Arg(name, false){}

Arg::Arg(const Arg &another) : impl(new Arg::Impl(another.impl->name, another.impl->need, another.impl->value)){}

Arg::~Arg(){}

Arg & Arg::operator =(const char *arg)
{
    impl->name = arg;
    return *this;
}

Arg & Arg::operator =(std::string str)
{
    impl->name = str;
    return *this;
}

Arg & Arg::operator =(const Arg &another)
{
    impl->name = another.impl->name;
    impl->need = another.impl->need;
    impl->value = another.impl->value;
    return *this;
}

bool Arg::operator ==(const char *arg) const
{
    return this->impl->name == arg;
}

bool Arg::operator ==(std::string str) const
{
    return impl->name == str;
}

bool Arg::operator ==(const Arg &another) const
{
    return impl->name == another.impl->name &&
            impl->need == another.impl->need &&
            impl->value == another.impl->value;
}

bool operator ==(const char *arg, const Arg &another)
{
    return another == arg;
}

bool operator ==(std::string str, const Arg &another)
{
    return another == str;
}

Method::Method(const MethodNode &node) : node(&node){}

Method::Method() : node(nullptr){}

Method::Method(const Method &another) : node(another.node)
{
    this->parameters.insert(another.parameters.begin(), another.parameters.end());
}

Method &Method::set(const char *key, int value)
{
    operator [](key) = std::to_string(value);
    return *this;
}

Method &Method::set(const char *key, long value)
{
    operator [](key) = std::to_string(value);
    return *this;
}

Method &Method::set(const char *key, bool value)
{
    operator [](key) = std::to_string(value);
    return *this;
}

Method &Method::set(const char *key, const char *value)
{
    operator [](key) = value;
    return *this;
}

Method &Method::add(const char *key, std::string value)
{
    if((operator [](key)).empty())
        operator [](key) = value;
    else
    {
        operator [](key) += ',';
        operator [](key) += value;
    }
    return *this;
}

Method &Method::add(const char *key, int value)
{
    return add(key, std::to_string(value));
}

Method &Method::add(const char *key, long value)
{
    return add(key, std::to_string(value));
}

Method &Method::add(const char *key, bool value)
{
    return add(key, value);
}

Method &Method::operator =(const Method &another)
{
    this->node = another.node;
    this->parameters.clear();
    this->parameters.insert(another.parameters.begin(), another.parameters.end());
    return *this;
}

std::string &Method::operator [](const char *str)
{
    if(node->hasArg(str))
        return parameters[str];
    else throw ErrorCode::ARGUMENT_NOT_FOUND;
}

std::string Method::getUri(std::string access_token)
{
    std::string url = node->getMethodAccess() + '/' + node->getMethodName() + '?';
    for(auto pair : parameters)
    {
        url += pair.first;
        url += '=';
        url += pair.second;
        url += argDelimiter;
    }
    url += accessTokenArg;
    url += '=';
    url += access_token;
    url += argDelimiter;
    url += "v=" + apiVersion;
    return url;
}

std::string Method::getUri()
{
    std::string url = node->getMethodAccess() + '/' + node->getMethodName() + '?';
    for(auto pair : parameters)
    {
        url += pair.first;
        url += '=';
        url += pair.second;
        url += argDelimiter;
    }
    url += "v=" + apiVersion;
    return url;
}

unsigned long Method::getNodeID() const
{
    return node->getMethodNodeID();
}

std::string Method::getMethodName() const
{
    return node->getMethodName();
}

bool Method::operator ==(const MethodNode &node) const
{
    return this->node->getMethodNodeID() == node.getMethodNodeID();
}

bool VKApi::operator ==(const MethodNode &node, const Method &method)
{
    return node.getMethodNodeID() == method.getNodeID();
}
