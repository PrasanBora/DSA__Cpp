
#include <iostream>

using namespace std;

//using while loop
int binarysearch(int arr[],int size, int key)
{
    int start=0;
    int end=size-1;
     int  mid=start+(end-start)/2;
    while(start<=end)
    {
        if(key==arr[mid])
        {
            return mid;
            
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }

        if(key<arr[mid])
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

//using recursion but taking start and end from user --
int binarysearch_rec(int arr[],int start,int end, int key)
{
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
     return mid;
     if(arr[mid]<key)
        binarysearch_rec(arr,mid+1,end,key);
     else 
        binarysearch_rec(arr,start,mid-1,key);   

}
int main()
{
    int list[]={1,3,5,7,8,9};
    cout<<"element found at index "<<binarysearch(list,6,5);

    return 0;
}
