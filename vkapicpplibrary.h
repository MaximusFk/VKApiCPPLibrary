#ifndef VKAPICPPLIBRARY_H
#define VKAPICPPLIBRARY_H
#include <initializer_list>
#include <string>
#include <memory>
#include <map>

#include "Error.h"

namespace VKApi {

class INetMethodExecutor;
class MethodNode;
class Method;
class Account;


extern const char * methodAccess;
extern const std::string apiVersion;
extern const char argDelimiter;
extern const char * accessTokenArg;
extern const char * defaultRedirect;

class VKApiCPPLibrary
{
    std::shared_ptr<INetMethodExecutor> executor;
    std::shared_ptr<Account> account;

public:
    VKApiCPPLibrary();

    std::shared_ptr<Account> getCurrentAccount()
    {
        return account;
    }
};

class Arg
{
    struct Impl;
    std::unique_ptr<Impl> impl;
public:
    Arg(std::string name, bool need = false);
    Arg(std::string name, std::string value);
    Arg(const char * name);
    Arg(const Arg & another);
    ~Arg();
    Arg & operator = (const char * arg);
    Arg & operator = (std::string str);
    Arg & operator = (const Arg & another);
    bool operator == (const char * arg) const;
    bool operator == (std::string str) const;
    bool operator == (const Arg & another) const;
    friend bool operator == (const char * arg, const Arg & another);
    friend bool operator == (std::string str, const Arg & another);
};

class MethodNode
{
    std::string name;
    std::string method_access;
    std::string * strings;
    size_t size;
    unsigned long int nodeId;
public:
    MethodNode(std::string name, std::initializer_list<std::string> args, unsigned long ID = 0);
    MethodNode(std::string name, std::initializer_list<std::string> args, std::string access, unsigned long ID = 0);

    ~MethodNode();

    std::string getMethodName() const;

    std::string getMethodAccess() const;

    bool hasArg(std::string str) const;

    unsigned long getMethodNodeID() const;

    Method createMethod() const;
};

class Method
{
    const MethodNode * node;
    std::map<std::string, std::string> parameters;

public:
    Method(const MethodNode & node);
    Method();
    Method(const Method &another);

    Method & set(const char * key, int value);

    Method & set(const char * key, long value);

    Method & set(const char * key, bool value);

    Method & set(const char * key, const char * value);

    Method & add(const char * key, std::string value);

    Method & add(const char * key, int value);

    Method & add(const char * key, long value);

    Method & add(const char *key, bool value);

    Method & operator = (const Method & another);

    std::string & operator [] (const char * str);
    std::string getUri(std::string access_token);
    std::string getUri();

    unsigned long getNodeID() const;

    std::string getMethodName() const;

    bool operator == (const MethodNode & node) const;

    friend bool operator == (const MethodNode & node, const Method & method);
};

namespace Audio
{
extern const MethodNode get;
extern const MethodNode getLyrics;
}

namespace Messages
{
extern const MethodNode getMessages;
extern const MethodNode getDialogs;
extern const MethodNode send;
extern const MethodNode getHistory;
}

namespace Users
{
extern const MethodNode get;
}

namespace Auth
{
extern const MethodNode authorize;
}
}

#endif // VKAPICPPLIBRARY_H
