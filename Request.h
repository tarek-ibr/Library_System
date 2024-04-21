#ifndef REQUEST_H
#define REQUEST_H

#include "Custom_String_Class.h"

struct Request {
    int memberID;
    Custom_String_Class bookISBN;

    Request(int mid, Custom_String_Class isbn) : memberID(mid), bookISBN(isbn) {}
};

#endif // REQUEST_H
