#ifndef CONNECTION_H
#define CONNECTION_H
#include <iostream>
#include "conn.h"

//The class that is organizing the doubly linked list of type conn
class Connection
{
    public:
        conn * head;
        Connection ()
        {
           head=NULL;
        }
        conn * add(int);
        void removal(int);
        void print(conn *);
};

#endif // CONNECTION_H
