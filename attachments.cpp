#include "attachments.h"
MessageAttachments::MessageAttachments(int size) :
    _size(size)
{
    objects = new std::shared_ptr<IVKObject> [size <= 10 ? size : 10];
}

MessageAttachments::MessageAttachments(const MessageAttachments & another) :
    MessageAttachments(another._size)
{
    for(int i = 0; i < another._size; ++i)
        this->objects[i] = another.objects[i];
}

MessageAttachments::~MessageAttachments()
{
    delete [] objects;
}

int MessageAttachments::size() const
{
    return _size;
}

MessageAttachments & MessageAttachments::operator = (const MessageAttachments & another)
{
    if(this->objects != nullptr)
        delete [] this->objects;
    objects = new std::shared_ptr<IVKObject> [another._size];
    _size = another._size;
    for(int i = 0; i < another._size; ++i)
        this->objects[i] = another.objects[i];
    return *this;
}

std::shared_ptr<IVKObject> MessageAttachments::operator [](int pos)
{
    return objects[pos <= 10 ? pos : 0];
}

