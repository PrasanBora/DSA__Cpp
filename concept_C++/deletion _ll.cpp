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


void deletenode(Node* head,int pos)
{ 
    //deletion at particular position
    Node*curr=head;
    Node*prev=NULL;
    int cnt=0; 
    while(cnt<=pos)
    {
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
     delete curr;

} 

int main()
{
    Node* start=new Node(23);
    insertAtHead(start,34);
    return 0;
}