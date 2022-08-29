#include<bits/stdc++.h>
using namespace std;


class ListNode
{
    public:
    int data;
    ListNode* next;

    //constructor 
    ListNode(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL)
            return NULL;
        
        ListNode * start=head;
        ListNode * slow =head;
        ListNode * fast =head;
        
        while (fast!=NULL && fast->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
              while(start!=slow )
               {
                  slow=slow->next;
                  start=start->next;
                }
                   return start; 
            }    
        }
       return NULL;
    }
      void removeLoop(ListNode* & head)
    {
     
        ListNode* meet=detectCycle(head);
        if(head==NULL || meet==NULL)
        return ;
        ListNode * temp=meet;
        while(temp->next!=meet)
             temp=temp->next;
             
             temp->next=NULL;
        
        // code here
        // just remove the loop without losing any nodes
    }