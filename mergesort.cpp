#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void merge(vector<int>&nums,int start, int end)
    {
        int mid= (start+end)/2;
        
        int *arr1=new int[mid-start+1];
        int *arr2=new int[end-mid];
        
        int len1=mid-start+1;
        int len2=end-mid;
        
        int k=start;
        for(int i=0;i<len1;i++)
           arr1[i]=nums[k++]; 
         for(int i=0;i<len2;i++)
           arr2[i]=nums[k++]; 
        
        //merge
        int i1=0,i2=0;
        int j=start;  //main array
        
        while(i1<len1 && i2<len2)
        {
            if(arr1[i1]<arr2[i2])
            {
                nums[j++]=arr1[i1++];
            }
            else
            {
                nums[j++]=arr2[i2++];
            }     
        }
        while(i1<len1)
            nums[j++]=arr1[i1++];
        while(i2<len2)
            nums[j++]=arr2[i2++];
        
    }
    
    void mergesort(vector<int>&nums,int start, int end)
    {
        if(start>=end)
            return;
        int mid=(start+end)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        
        merge(nums ,start,end);
    }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};
int main()
{
    return 0;
}