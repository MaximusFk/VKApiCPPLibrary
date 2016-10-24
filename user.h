#ifndef USER_H
#define USER_H

#include "ivkobject.h"

class User : public IVKObject
{

    friend class VKObjectFactory;

    std::string first_name;
    std::string last_name;
    std::string deactivated;
    bool hidden;

    std::array<VKValue, 5> values;
public:
    User();

    std::string getFirstName() const
    {
        return first_name;
    }

    std::string getLastName() const
    {
        return last_name;
    }

    std::string getDeactivatedStatus() const
    {
        return deactivated;
    }

    bool isHidden() const
    {
        return hidden;
    }
/// Overrides:
    virtual ObjectType getType() const override
    {
        return ObjectType::USER;
    }
};

#endif // USER_H
