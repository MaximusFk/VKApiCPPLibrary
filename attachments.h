#ifndef ATTACHMENTS_H
#define ATTACHMENTS_H
#include "ivkobject.h"

class MessageAttachments
{
    friend class VKObjectFactory;

    static constexpr int maxSize = 10;
    int _size;
    std::shared_ptr<IVKObject> * objects;
public:
    MessageAttachments(int);
    MessageAttachments(const MessageAttachments &);
    ~MessageAttachments();

    int size() const;

    MessageAttachments & operator = (const MessageAttachments &);
    std::shared_ptr<IVKObject> operator [] (int);
};

#endif // ATTACHMENTS_H
