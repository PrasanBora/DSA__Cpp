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
   
int main()
{
    node * root =NULL;
    root = buildtree(root);

    return 0;
}