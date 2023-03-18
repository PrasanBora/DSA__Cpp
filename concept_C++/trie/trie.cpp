//trie implementation 
#include<bits/stdc++.h>
using namespace std;

class trienode
{
    public :
    char data ;
    trienode* children[26];
    bool isterminal ;

    trienode(char ch )
    {
        data =ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isterminal = false;
    }
};
class trie 
{
  public:
  trienode * root;
   trie()
   {
    root = new trienode('\0');
   }
  void inserttrie(trienode * root ,string str)
  {
    //base case 
    // cout<<str[0]<<endl;
    if(str.length()==0)
    {
        root->isterminal =true;
        return;
    }
    //getting the char 
    int index = str[0]-'A';
    trienode * child ;
    // if value is present just move pointer to next char 
    if(root->children[index] !=NULL)
    {
        child=root->children[index];
    }
    else // absent 
    {
        // cout<<"newnode"<<"--"<<str[0]<<endl;
        child=new trienode(str[0]);
        root->children[index]=child;
    }
    inserttrie(child,str.substr(1));

  }
  // function to call insertrie
  void insert(string st)
  {
    inserttrie(root,st);
  }
  // function for search 
  bool search(string str)
  {
     return searchtrie(root,str);
  }
  
  bool searchtrie(trienode * root ,string str )
  {
   if(str.length()==0)
    {
        return root->isterminal ;
    }
    //getting the char 
    int index = str[0]-'A';
    trienode * child ;
    // if value is present just move pointer to next char 
    if(root->children[index])
    {
        child=root->children[index];
    }
    else // absent 
    {
       return false;
    }
    //  cout<<"search "<<index;
     return searchtrie(child,str.substr(1));
  }

};
int main()
{
    trie *t =new trie();
    t->insert("HELOL");
    t->insert("HELI");
    t->insert("HEJ");
    cout<<" present : "<<t->search("HELOLJJ");
   
}