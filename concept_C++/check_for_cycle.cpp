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
 bool hasCycle(ListNode *head) 
    {
        if (head==NULL)
            return false;
        
        map<ListNode* , bool>visited;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(visited[temp]==true)
                return true;
            
            visited[temp]=true;
            temp=temp->next;
        }
        return false;
    }
int main()
{
    return 0;
}