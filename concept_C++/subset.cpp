#include<bits/stdc++.h>
using namespace std;

//------------------
  vector<vector<int>> ans;
      void subsetmaker(vector<int>temp, int index,vector<int>& nums )
      {
          if(index ==nums.size())
          {
              ans.push_back(temp);
              return ;
          }
          //exclude 
          subsetmaker(temp,index+1,nums);
          //include
          temp.push_back(nums[index]);
          subsetmaker(temp,index+1,nums);
      }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>temp;
          subsetmaker(temp,0,nums);
          return ans;
        
    }

    //-------------

     vector<vector<int>> subsets(vector<int>& nums)
    { 
         vector<vector<int>> ans;
          vector<int>temp;
          ans.push_back({ });
        
         for(int i=0;i<nums.size();i++)
         {
             int count=ans.size();
             for(int j=0;j<count;j++)
             {
                 temp=ans[j];
                 temp.push_back(nums[i]);
                 ans.push_back(temp);
                 temp.clear();
             }
         }
          return ans;
    }

    //-------------
int main()
{
    return 0;
}