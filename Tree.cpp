#include "Tree.h"




//Calculates the height of the node given as a parameter
int Tree::height(avlnode * temp)
{
    int left_h=0;
    int right_h=0;
    if (temp->left!=NULL)
    {
        left_h = height(temp->left);
    }
    if (temp->right!=NULL)
    {
        right_h = height(temp->right);
    }


    if (left_h>right_h)
    {
        return left_h+1;
    }
    else
    {
        return right_h+1;
    }
}



//Calculates the AVL balance of the node given as a parameter by substracting
//the height of the left child from the height of the right child
int Tree::balance_factor(avlnode * temp)
{
    int left_h;
    int right_h;

    if (temp->left!=NULL)
    {
        left_h = height(temp->left);
    }
    else
    {
        left_h=0;
    }

    if (temp->right!=NULL)
    {
        right_h = height(temp->right);
    }
    else
    {
        right_h=0;
    }
    return left_h-right_h;
}

//The action of balancing the tree to the given node, according to each individual circumstance
avlnode * Tree::balance(avlnode * temp)
{
    int bal=balance_factor(temp);
    if (bal>1)
    {
        if (balance_factor(temp->left)>0)
        {
            temp=LL_rotation(temp);
        }
        else
        {
            temp=LR_rotation(temp);
        }
    }
    else if (bal<-1)
    {
        if (balance_factor(temp->right)>0)
        {
            temp=RL_rotation(temp);
        }
        else
        {
            temp=RR_rotation(temp);
        }
    }
    return temp;
}



//The insertion function. It takes as parameters a pointer to a node and two IDs which establish a
//link between them. Firstly, it checks if the given node already exists in the AVL tree. If it does
//then it is inserted as a new link in this node's list. If it does not, then the program puts it
//in the appropriate position inside the avl tree and inserts the parameters as its first link.



avlnode * Tree::insertion(avlnode * temp, int value, int value1)
{
    avlnode * temp1 = findnode(value);
    if (temp1!=NULL)
    {
        ((temp1->head2)->head)=(temp1->head2)->add(value1);
        return temp;
    }
    if (temp==NULL)
    {
        temp = new avlnode;
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        temp->head2=new Connection;
        ((temp->head2)->head)=(temp->head2)->add(value1);
    }
    else if (value>temp->data)
    {
        temp->left=insertion(temp->left, value, value1);
        temp=balance (temp);
    }
    else if (value<temp->data)
    {
        temp->right=insertion(temp->right, value, value1);
        temp=balance (temp);
    }
    return temp;
}


// The print calls itself firstly for the right and then the left subtree
// in order to return the nodes in increasing order.
void Tree::print(avlnode * temp)
{
    if (temp==NULL) return;
    print (temp->right);
    std::cout << std::endl;
    std::cout << temp->data;
    std::cout << "     " << "with the following connections: " ;
    (temp->head2)->print((temp->head2)->head);
    print (temp->left);
    return;
}



//The function findnode takes the inserted int parameter and compares with the nodes
//of the AVL tree. It returns the found node of the AVL tree, if it is found. If not,
//NULL is returned. Because our tree is balanced, the function checks the root.
//If it is larger, then the function is repeated for the root of the left subtree.
//If it is not larger, the function is repeated for the root of the right subtree.


avlnode * Tree::findnode (int value)
{
    if (RootOfAvl==NULL) return NULL;
    avlnode * temp = new avlnode;
    temp=RootOfAvl;
    while (temp->data!=value)
    {
        if (value>temp->data)
        {
            if (temp->left!=NULL)
            {
                temp=temp->left;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if (temp->right!=NULL)
            {
                temp=temp->right;
            }
            else
            {
                return NULL;
            }
        }
    }
    return temp;
}

avlnode * Tree::RR_rotation(avlnode * temp)
{
    avlnode * temp1= temp->right;
    temp->right=temp1->left;
    temp1->left=temp;
    if (RootOfAvl==temp)
    {
        RootOfAvl=temp1;
        return RootOfAvl;
    }
    return temp1;
}

avlnode * Tree::LL_rotation(avlnode * temp)
{
    avlnode * temp1= temp->left;
    temp->left=temp1->right;
    temp1->right=temp;
    if (RootOfAvl==temp)
    {
        RootOfAvl=temp1;
        return RootOfAvl;
    }
    return temp1;
}

avlnode * Tree::LR_rotation (avlnode * temp)
{
    avlnode * temp1= temp->left;
    avlnode * temp2= temp1->right;
    temp1->right=temp2->left;
    temp2->left=temp1;
    temp->left=temp2;
    temp->left=temp2->right;
    temp2->right=temp;
    if (RootOfAvl==temp)
    {
        RootOfAvl=temp2;
        return RootOfAvl;
    }
    return temp2;
}

avlnode * Tree::RL_rotation (avlnode * temp)
{
    avlnode * temp1= temp->right;
    avlnode * temp2= temp1->left;
    temp1->left=temp2->right;
    temp2->right=temp1;
    temp->right=temp2;
    temp->right=temp2->left;
    temp2->left=temp;
    if (RootOfAvl==temp)
    {
        RootOfAvl=temp2;
        return RootOfAvl;
    }
    return temp2;
}


//Removelink performs a search to find the head of the linked list which we want to remove the node from,
//and then removal is called to remove it from the list and the function ends.


void Tree::removelink(int x, int y)
{
    avlnode * temp1=findnode(x);
    conn * temp2=(temp1->head2)->head;
    while ((temp2)!=NULL)
    {
        if (temp2->data==y)
        {
            (temp1->head2)->removal(y);
            return;
        }
        temp2=temp2->next;
    }
}

