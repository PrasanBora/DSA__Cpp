
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor 
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

// insertion 

void insertAtHead(Node* & head ,int info)
{
    Node* temp= new Node(info);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* & tail,int info)
{
    Node* temp= new Node(info);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* & tail ,Node* & head ,int pos,int info)
{
    if(pos==1)  // insertion at head i.e pos=1
     { insertAtHead(head,info);
     return; }

    Node * temp=head;
    int count=1;
    while(count<pos-1)
    {
        temp=temp->next;
        count++;
    }

    if(temp->next==NULL) //insertion at end  pos=len
    {
      insertAtTail(tail,info);
      return;
    }
    Node *insert=new Node(info);
    insert->next=temp->next;
    temp->next=insert;
}
//------------

void print(Node* & head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}

int main()
{
    Node* temp= new Node(10);

    Node* head=temp;
    print(head);
    cout<<endl<<"insertion at head "<<endl;
    insertAtHead(head,25);
    print(head);

     Node * tail =temp;
     cout<<endl<<"insertion at tail "<<endl;
     insertAtTail(tail,86);
     print (head);
   
    cout<<endl<<"insertion at pos "<<endl;
    insertAtPosition(tail,head,4,98);
    print (head);
  
    // cout<<endl<<tail->data;
    // cout<<endl<<head->data;
    return 0;
}