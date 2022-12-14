#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
   int data;
   node * left;
   node * right;

   node( int val )
   {
    this->data=val;
    this->left=NULL;
    this->right=NULL;
   }
};
node * buildtree(node * root)
   {
       int d;
       cout<<"Enter data for node :"<<endl;
       cin>>d;
       root = new node(d);
       if (d==-1)
        return NULL;
        cout<<"Enter data for left of : "<<d<<endl;
        root->left = buildtree(root->left);
        cout<<"Enter data for right of : "<<d<<endl;
        root->right= buildtree(root->right);
        return root;
         
   }
   
   void inorder(node * root) //LNR
   {
    if(root==NULL)
     return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);

   }
   void postorder(node * root) //LRN
   {
     if( !root)
     return;
     postorder(root->left);
     postorder(root->right);
     cout<<root->data<<" ";

   }
   void preorder(node * root)
   {
      if( !root)
     return;
       cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
   }
int main()
{
    node * root =NULL;
    root = buildtree(root);
    
    cout<<"Inorder traversal :"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal :"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Preorder traversal :"<<endl;
    preorder(root);
    cout<<endl;

    // 1 2 3 -1 -1 5 -1 9 -1 -1 4 0 7 -1 -1 -1 11 -1 -1
    return 0;
}