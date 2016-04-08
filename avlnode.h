#ifndef AVLNODE_H
#define AVLNODE_H

#include "Connection.h"

//Next, we have the data structure for every node in the AVL Tree.
//Each node has a pointer to the left and one to the right as well as a pointer
//to the class that links the nodes of our doubly linked list.


//The node of the AVL Tree
struct avlnode
{
    int data;
    avlnode * left;
    avlnode * right;
    Connection * head2;          //The root which is the head of the linked list.
};

extern avlnode * RootOfAvl;  //We use extern to avoid the multiply defined compilation error

#endif // AVLNODE_H
