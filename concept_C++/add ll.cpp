/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:  
    
    ListNode * add(ListNode * l1, ListNode * l2, int & carry)
    {
        if(! l1 && !l2 )
            return NULL;
        
        ListNode * temp =new ListNode (-1);
        temp->next=add(l1->next,l2->next,carry);
        temp->val=(l1->val + l2->val + carry)%10;
        carry =(l1->val + l2->val + carry)/10;
        
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode * h1=l1;
        ListNode * h2=l2;
        
        while(h1 || h2)
        {
            if(!h1)
            {
                ListNode * temp = new ListNode (0,l1);
                l1=temp;
                if(h2)
                h2=h2->next;
            }
             if(!h2)
            {
                ListNode * temp = new ListNode (0,l2);
                l2=temp;
                 if(h1)
                 h1=h1->next;
            }
           else 
           {
               h1=h1->next;
               h2=h2->next;
           }
           
        }
            ListNode * ans=new ListNode (0);
            int carry =0;
            ans->next=add(l1,l2,carry);
        
        if(carry)
        {
            ListNode * temp = new ListNode (carry,ans->next);
            return temp;
        }
        
        return ans->next;
    }
};