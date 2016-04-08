#ifndef TREE_H
#define TREE_H

#include "avlnode.h"

//The class that organizes the AVL nodes
class Tree
{
    public:
        Tree()
        {
            RootOfAvl=NULL;      // Constructor
        }
        int height (avlnode *);
        int balance_factor (avlnode *);
        avlnode * balance (avlnode *);
        avlnode * insertion (avlnode *, int, int);  //
        void print (avlnode *);
        avlnode * findnode (int value);
        avlnode * RR_rotation (avlnode *);
        avlnode * LL_rotation (avlnode *);
        avlnode * LR_rotation (avlnode *);
        avlnode * RL_rotation (avlnode *);
        void removelink(int, int);
};

#endif // TREE_H
