
//  Reverse Words in a String

// Input: s = "the sky is blue"
// Output: "blue is sky the"

#include<bits/stdc++.h>
using namespace std;


 string reverseWords(string s) 
    {   
        vector<string> str;
        string ans="";
        int n=s.length();
        int k;
        for(int i=0;i<n;i++)
        { 
            while(i<n && s[i]==' ') 
                i++;
            k=i;
            while(k<n && s[k]!=' '&& s[k]!='\0')
                k++;
            if(i!=n)
            str.push_back(s.substr(i,k-i));
             i=k;
        }
        for(int p=str.size()-1;p>0;p--)
         ans.append(str[p]+" ");
        ans.append(str[0]);
        return ans;
    }

/////////////// 2 Apporach ///////

string reverseWords(string s) 
{ 
  string temp="";
        vector<string> str;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
                temp=temp+s[i];
            if(s[i]!=' ' && ( s[i+1]==' ' || s[i+1]=='\0') )
            {
                str.push_back(temp);
                temp="";
            }
        }   
        for(int p=str.size()-1;p>0;p--)
         temp.append(str[p]+" ");
        temp.append(str[0]);
        return temp;
       
    }
int main()
{
    return 0;
}