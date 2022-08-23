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
void print(Node* & head)
{
    Node*temp=head;
   while(temp != NULL)
   {
    
    cout<<temp->data<<"  ";
    temp=temp->next;
   }
}
int main()
{
    Node * node1 =new Node(88);
    Node * head=node1;
    print (head);
    cout<<"insertion at front "<<endl;
    insertAtHead(head,45);
    print(head);
    return 0;
}