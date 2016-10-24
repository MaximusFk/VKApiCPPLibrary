#ifndef MESSAGE_H
#define MESSAGE_H
#include "ivkobject.h"
#include "attachments.h"

class Message : public IVKObject
{
    friend class VKObjectFactory;
    std::array<VKValue, 12> values;
private:
    int user_id;
    int from_id;
    time_t date;
    bool read_state;
    bool out;
    std::string title;
    std::string body;

    MessageAttachments attachments;
    bool emoji;
    bool important;
    bool deleted;
    int random_id;

public:
    int getUserId() const
    {
        return user_id;
    }

    int getSenderId() const
    {
        return from_id;
    }

    time_t getDate() const
    {
        return date;
    }

    bool isRead() const
    {
        return read_state;
    }

    bool isOut() const
    {
        return out;
    }

    std::string getTitle() const
    {
        return title;
    }

    std::string getText() const
    {
        return body;
    }

    bool hasEmoji() const
    {
        return emoji;
    }

    bool isImportant() const
    {
        return important;
    }

    bool isDeleted() const
    {
        return deleted;
    }

    int getRandomId() const
    {
        return random_id;
    }

    MessageAttachments getMessageAttachments() const
    {
        return attachments;
    }

    Message();

///Overrides:
    virtual ObjectType getType() const override
    {
        return ObjectType::MESSAGE;
    }

};

#endif // MESSAGE_H
