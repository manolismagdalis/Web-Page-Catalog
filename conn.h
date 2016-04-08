#ifndef CONN_H_INCLUDED
#define CONN_H_INCLUDED

//The node of every neighbour
struct conn
{
    int data;
    conn * next;
    conn * prev;
};

#endif // CONN_H_INCLUDED
