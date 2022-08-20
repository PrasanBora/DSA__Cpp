#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
    {
        int left =0;
        int right=height.size()-1;
        int lmax=height[0],rmax=height[right];
        int water=0;
        
        while(left<=right)
        {
            if(lmax<=rmax)
            {
                if(height[left]>lmax)
                  lmax=height[left];
                else 
                    water = water+ (lmax-height[left]);
                left++;
            }
            else 
            {
                if(height[right]>rmax)
                    rmax=height[right];
                 else 
                    water =  water+ (rmax-height[right] );
                right--;
            }
            
        }
        return water;
    }


    ////------------

    int trap(vector<int>& height) 
    {
        int water=0;

        int n=height.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1],height[i]);
            rmax[n-i-1]=max(rmax[n-i],height[n-1-i]);
        }
        for(int j=0;j<n;j++)
            water +=  min(lmax[j],rmax[j]) - height[j];
        
        return water;
    }
int main()
{
    return 0;
}