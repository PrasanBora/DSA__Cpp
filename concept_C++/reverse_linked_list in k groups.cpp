#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node * next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node * reversekgroups(Node*head,int k)
{
    if(head==NULL || head->next==NULL)
    return head;
    Node* temp =head;
    for(int i=0;i<k;i++)
    {
        if(temp==NULL)
        return head;
        temp=temp->next;
    }
    //reverse k nodes 
   int count=0;
   Node * curr =head;
   Node * prev = NULL;
   Node * frwd =NULL;
   while(count<k)
   {
    frwd=curr->next;
    curr->next=prev;
    prev=curr;
    curr=prev;
    count++;
   }
  head->next=reversekgroups(frwd,k);

  return prev;
}

//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 
//     ListNode* reverseKGroup(ListNode* head, int k)
//     {
//         ListNode * dummy =new ListNode(0,head); 
//         ListNode * curr =NULL;
//         ListNode * prev = NULL;
//         ListNode * frwd =NULL;
//         ListNode * before=dummy;
//         ListNode * after =head;
        
//       while(true)
//       {  
//       ListNode* temp =after;  
//       for(int i=0;i<k;i++)
//        {
//         if(temp==NULL)
//         return dummy->next;
//         temp=temp->next;
//        }
//        int count=0;
//        curr=after;
//        prev=before;
     
//       while(count<k)
//      {
//       frwd=curr->next;
//       curr->next=prev;
//       prev=curr;
//       curr=frwd;
//       count++;
//      }
//     after->next=curr;
//     before->next=prev;
//     before=after;
//     after=curr;   
//    }      
//     }   

int main()
{
    return 0;
}