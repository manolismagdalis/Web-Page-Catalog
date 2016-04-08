#include "Connection.h"

// Adds a new node to the list. The new node is sorted during insertion.
// Parameter: ID. Returns the head of the list.
conn * Connection::add(int x)
{
    conn * temp = new conn;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if (head==NULL)
    {
       head=temp;
       return head;
    }
    else
    {
        conn * temp1 = head;
        if (temp->data<temp1->data)
        {
            temp1->prev=temp;
            temp->next=temp1;
            temp->prev=NULL;
            head=temp;
            return head;
        }
        else if (temp->data>temp1->data)
        {
            if (temp1->next==NULL)
            {
                temp1->next=temp;
                temp->prev=temp1;
                temp->next=NULL;
                return head;
            }
            else
            {
                while((temp->data>temp1->data) && (temp1->next!=NULL))
                {
                    temp1=temp1->next;
                }
                if (temp->data>temp1->data)
                {
                    temp1->next=temp;
                    temp->prev=temp1;
                    temp->next=NULL;
                    return head;
                }
                else if (temp->data==temp1->data) return head;
                else
                {
                    conn * temp2 = temp1->prev;
                    temp->next=temp1;
                    temp1->prev=temp;
                    temp->prev=temp2;
                    temp2->next=temp;
                    return head;
                }
            }
        }
        return head;
    }
}

// Removes a node from the list. Parameter: ID.
void Connection::removal(int value)
{
    conn * temp = head;
    if (temp==NULL) return;
    while ((temp->next!=NULL)&&(temp->data!=value))
    {
        temp=temp->next;
    }
    if ((temp->data==value)&&(temp->next==NULL))
    {
        if (temp==head)
        {
            head=NULL;
            delete temp;
        }
        else
        {
            conn * temp1 = temp->prev;
            temp1->next=NULL;
            delete temp;
        }
    }
    else if (temp->data==value)
    {
        conn * temp1 = temp->prev;
        conn * temp2 = temp->next;
        temp1->next=temp2;
        temp2->prev=temp1;
        delete temp;
    }
    else
    {
       return;
    }
}

// Prints the list from the node that is inserted as a parameter until the end of the list.
void Connection::print(conn * root)
{
    conn * temp = root;
    while (temp->next!=NULL)
    {
        std::cout << temp->data << "   " ;
        temp=temp->next;
    }
    std::cout << temp->data << "    " ;
    return;
}

