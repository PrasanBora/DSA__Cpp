#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insertNode (Node * & tail,int compare , int info)
{
    if (tail==NULL)
    {
        Node * newnode= new Node(info);
        tail=newnode;
        newnode->next=newnode;
        // return;
    }
    else 
    { 
        Node * curr =tail;
        while(curr->data!=compare)
        {
           curr= curr->next;
        }
        //element found
        Node * temp = new Node (info);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void printnode(Node * tail)
{
    Node * temp=tail;
    if(tail==NULL)
    {
        cout<<"list is empty";
        return ;
    }
    do {
           cout<<tail->data<<"  ";
           tail=tail->next;
    } while(tail!=temp) ;
    cout<<endl;
}

void  deletenode(Node * & tail ,int data)
{
    if(tail==NULL)
    {
        cout<<"underflow list is empty";
        return;
    }
     Node * prev =tail;
     Node * curr =prev->next;

    while(curr->data!=data)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;

      if(curr==prev)
       tail=NULL;

     else if(tail==curr) // for deletion of first element
        { 
            tail=prev;
            // cout<<prev->data<<"----------"; 
        }

    curr->next=NULL;
    delete curr;
}

int main()
{
    Node * tail = NULL;
    insertNode(tail,23,6);
    printnode(tail);

    insertNode(tail,6,9);
    printnode(tail);

    insertNode(tail,9,3);
    printnode(tail);

    insertNode(tail,9,7);
    printnode(tail);
   
    deletenode(tail,6);
    printnode(tail);

     return 0;
}