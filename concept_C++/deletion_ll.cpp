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
void insertAtHead(Node* & head ,int info)
{
    Node* temp= new Node(info);
    temp->next=head;
    head=temp;
}


void deletenode(Node* &head,int pos)
{ 
    if(pos==1)
    {
        Node*temp=head;
      head=head->next;
      delete temp;
    }
    //deletion at particular position
    else {
    Node*curr=head;
    Node*prev=NULL;
    int cnt=1; 
    while(cnt<pos)
    {
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
     delete curr;
    }

} 
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
    Node* start=new Node(23);
    insertAtHead(start,34);
    insertAtHead(start,4);
    insertAtHead(start,98);
    print(start);
    cout<<"start="<<start->data<<endl;
    deletenode(start,1);
    print(start);
    
    return 0;
}