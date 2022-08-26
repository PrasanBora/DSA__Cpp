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

void insertAtHead( Node * & head,Node * & tail, int info)
{
    if(head==NULL)
    {
          Node * temp = new Node(info);
          head=temp;
          tail=temp;
    }
    else 
    {
          Node * temp = new Node(info);
          head->prev=temp;
         temp->next=head;
         head=temp;
    }
  
}

void insertAtTail(Node* &tail,Node * & head,int info)
{
    if(tail==NULL)
    {
         Node* temp =new Node(info);
         head=temp;
         tail=temp;
    }
    Node* temp =new Node(info);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPos(Node * &head,Node * &tail, int pos,int info)
{
    if(pos==1)
     {
        insertAtHead(head,tail,info);
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
            insertAtTail(tail,head,info);
            return;
         }
            Node * sec=new Node(info);
            sec->next=temp->next;
            temp->next->prev=sec;
            temp->next=sec;
            sec->prev=temp;
}


void deleteNode(Node* & head,Node* & tail,int pos)
{
    if (pos==1)
    {
        Node * temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else 
    {
        int count =1;
        Node * curr = head;
        Node * prev = NULL;
        while (count<pos)
        {
          prev = curr;
          curr = curr->next;
          count++;
        }
        prev->next=curr->next;
        curr->prev=NULL;
        if(curr->next==NULL)
           { tail=prev;}
        curr->next=NULL;
        delete curr;

    }
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
    insertAtHead(head,tail,45);
    print(head);

   cout<<"insertion at tail"<<endl;
   insertAtTail(tail,head,69);
   print (head);

   cout<<"insertion at position "<<endl;
   insertAtPos(head,tail,3,57);
   print(head);

   cout<<"deletion at position "<<endl;
   deleteNode(head,tail,4);
   print (head);
   cout<<"head  "<<head->data<<endl;;
   cout<<"tail  "<<tail->data<<endl;

    return 0;
}