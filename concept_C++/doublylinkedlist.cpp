#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node * prev;
    Node * next;

    Node(int info)
    {
        this->data=info;
        this->prev=NULL;
        this->next=NULL;
    }
};

void insertAtHead( Node * & head, int info)
{
   Node * temp = new Node(info);
   head->prev=temp;
   temp->next=head;
   head=temp;
}

void insertAtTail(Node* &tail,int info)
{
    Node* temp =new Node(info);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPos(Node * &head,Node * &tail, int pos,int info)
{
    if(pos==1)
     {
        insertAtHead(head,info);
        return;
     }

        Node * temp=head;
        int count=1;
        while(count<pos-1)
        {
          temp=temp->next;
          count++;
        }

        if(temp->next==NULL)
         {
            insertAtTail(tail,info);
            return;
         }
            Node * sec=new Node(info);
            sec->next=temp->next;
            temp->next->prev=sec;
            temp->next=sec;
            sec->prev=temp;
}

void print(Node* & head)
{
    Node*temp=head;
   while(temp != NULL)
   {
    cout<<temp->data<<"  ";
    temp=temp->next;
   }
   cout<<endl;
}

int main()
{
    Node * node1 =new Node(88);
    Node * head=node1;
    Node * tail =node1;
    print (head);

    cout<<"insertion at front "<<endl;
    insertAtHead(head,45);
    print(head);

   cout<<"insertion at tail"<<endl;
   insertAtTail(tail,69);
   print (head);

   cout<<"insertion at position "<<endl;
   insertAtPos(head,tail,4,57);
   print(head);

    return 0;
}