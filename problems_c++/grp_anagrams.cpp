#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto i=mp.begin();i!=mp.end();i++)
            ans.push_back(i->second);
        return ans;
    }

/// approach 2  using count sort  i.e first count letter and create new str using that data
    string key (string s)
    {
        vector<int>count(26,0);
         string sg="";
        
        for(int i=0;i<s.size();i++)
            count[s[i]-'a']++;
       
        for(int i=0;i<26;i++)
            sg+=string(count[i],i+'a');
        return sg ;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            mp[key(strs[i])].push_back(strs[i]);
        }
        for(auto i=mp.begin();i!=mp.end();i++)
            ans.push_back(i->second);
        return ans;
    }

int main()
{
    return 0;
}