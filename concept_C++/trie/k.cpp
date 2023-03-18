#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution
{
    class trienode
{
  public:
  char data;
  trienode* children[26];
  bool isTerminal;
  
  trienode(char c)
  {
      data =c;
     
      for(int i=0;i<26;i++)
      {
          children[i]=NULL;
      }
       isTerminal =false;
  }
};
class trie
{
    public:
    trienode * root;
  trie()
  {
      root= new trienode('\0');
  }
  
  void insert(trienode * root ,string str)
  {
      if(str.length()==0)
      {
          root->isTerminal =1;
          return;
      }
      trienode * child;
      int index= str[0]-'a';
      if(root->children[index])
      {
          child=root->children[index];
      }
      else 
      {
           child = new trienode(str[0]);
           root->children[index] =child;
      }
      insert(child,str.substr(1));
  }
  void inserttrie(string str)
  {
      insert(root,str);
  }

    void printsuggestion(trienode * curr,string prefix,vector<string> &temp)
    {
         if(curr->isTerminal)
         {
             temp.push_back(prefix);
         }
         for(char ch='a';ch<='z';ch++)
         {
             trienode * next = curr->children[ch];
             if(next != NULL)
             {
                 prefix.push_back(ch);
                 printsuggestion(next,prefix,temp);
                 prefix.pop_back();
             }
         }
    }
    vector<vector<string>>getsuggestion(string s)
    {
        trienode * prev =root;
        vector<vector<string>>ans;
        for(int i =0;i<s.length();i++)
        {
            char last =s[i];
            prefix.push_back(last);
            trienode * curr = prev->children[last-'a'];
            
            if(!curr)
            {
                break;
            }
            else 
            {
                vector<string> temp;
                printsuggestion(curr,prefix,temp);
                
                ans.push_back(temp);
                temp.clear();
                prev=curr;
            }
        }
         return ans;
    }
};    
    public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
         trie* t =new trie ();
        for(int i=0 ;i<n;i++)
        {
            t->inserttrie(contact[i]);
        }
        return t->getsuggestion(s);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}