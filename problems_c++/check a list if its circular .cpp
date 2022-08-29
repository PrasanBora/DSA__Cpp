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

bool check(Node* head)
{
    if(head==NULL)
    return true;

    Node* temp =head->next;
    while(temp!=NULL && temp != head)
      temp=temp->next;

      return (temp==head);

}

int main()
{
    return 0;
}