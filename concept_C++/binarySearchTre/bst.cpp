#include<bits/stdc++.h>
using namespace std;

class node
 {
    public:
    int data;
    node * left;
    node * right;

    node(int d)
    {
        this->data = d;
        this->left =NULL;
        this->right =NULL;
    }
 }
;

node * insertIntoBST (node * & root, int data)
{
   if(!root)
   {
      root = new node (data);
      return  root;
   }
     
    if(data > root->data)
    root->right =  insertIntoBST(root->right,data);

    else
    root->left = insertIntoBST(root->left,data);
    
    return root;
}
 void takeinput(node *  & root)
 {
    int data;
    cout<<"Enter value to inserted ";
    cin>>data;
    while (data!=-1)
    {
        root = insertIntoBST(root,data);
        cout<<"value inserted  :"<<data<<endl;
        cin>>data;
    }
 }

 void levelOrderTraversal ( node * root)
 {
    if(!root)
     return;

    queue<node * > q ;
    q .push(root);

    while(!q.empty()) 
    {
        int sz= q.size();
        while(sz--)
        {
            // cout<<sz;
            node * temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left)
             q.push(temp->left);

            if(temp->right)
             q.push(temp->right);

        }
        cout<<endl<<"----------"<<endl;
    }
    // return;
 }

// void levelOrderTraversal(node* root) {
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()) {
//         node* temp = q.front();
//         q.pop();

//         if(temp == NULL) { 
//             //purana level complete traverse ho chuka hai
//             cout << endl;
//             if(!q.empty()) { 
//                 //queue still has some child ndoes
//                 q.push(NULL);
//             }  
//         }
//         else{
//             cout << temp -> data << " ";
//             if(temp ->left) {
//                 q.push(temp ->left);
//             }

//             if(temp ->right) {
//                 q.push(temp ->right);
//             }
//         }
//     }

// }


int getmin(node * root)
{
    node * temp =root ;
    while (temp->left)
    {
        temp =temp->left;
    }
    cout<<"min val :";
    return temp->data;
}

int getmax ( node * root)
{
    node * temp = root;
    while(temp->right)
    {
        temp=temp->right;
    }
    cout<<"max val :";
    return temp->data;
}
int main()
{
    node * root =NULL;

    takeinput(root);

    levelOrderTraversal(root);

    cout<<getmin(root);

    cout<<endl <<getmax(root);
    return 0;
}