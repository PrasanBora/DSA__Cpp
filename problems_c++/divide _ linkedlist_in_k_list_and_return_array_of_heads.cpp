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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode *> ans;
        int len=0;
        
        ListNode * temp =head;
        
        while(temp)
        {
            len++;
            temp=temp->next;
        }
         int grp = len/k;
         int extra = len% k;
        
           temp =head;
        while(temp)
        {
            ListNode * newnode = new ListNode (temp->val);
            ans.push_back(newnode);
           
            for(int i=0; i< grp-1  ;i++)
            {   
                 if( temp && temp->next )
                 {
                     temp = temp->next;
                     newnode ->next = new ListNode (temp->val);
                     newnode = newnode->next;   
                 } 
            }
            if(extra && len>k)
            {
                temp=temp->next;
                newnode ->next = new ListNode (temp->val);
                newnode =newnode->next;
                extra--;
            }
            ListNode * h1= temp->next;
            temp->next=NULL;
            temp=h1;           
        }
        while(len<k)
        {
            ans.push_back(NULL);
            len++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}