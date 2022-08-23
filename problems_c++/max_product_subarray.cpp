#include<bits/stdc++.h>
using namespace std;

//-----
int maxProduct(vector<int>& nums) 
    {
        int n=nums.size(),ans=INT_MIN;
        int proback=1;
        int profront=1;
        
        for(int i=0;i<nums.size();i++)
        {
            proback=proback*nums[n-i-1];
            profront=profront*nums[i];
            ans = max(ans,max(profront,proback));
            cout<<proback<<"   "<<profront<<endl;
            if(nums[i]==0)
                profront=1;
            if(nums[n-i-1]==0)
                proback=1;
        }
        return ans;
    }
    //------
     int maxProduct(vector<int>& nums) 
    {
        int n=nums.size(),ans=INT_MIN;
        int proback=1;
        int profront=1;
        
        for(int i=0;i<nums.size();i++)
        {
            proback=proback*nums[n-i-1];
            profront=profront*nums[i];
            ans = max(ans,max(profront,proback));
            cout<<proback<<"   "<<profront<<endl;
            if(nums[i]==0)
                profront=1;
            if(nums[n-i-1]==0)
                proback=1;
        }
        return ans;
    }
    //--------

int main()
{
    return 0;
}