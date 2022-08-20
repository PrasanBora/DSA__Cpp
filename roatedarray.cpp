
#include <iostream>

using namespace std;

int binarysearch(int arr[],int start, int end,int key)  //binary search function
{
     int  mid=start+(end-start)/2;
    while(start<=end)
    {
        if(key==arr[mid])
        return mid;

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

int pivotsearch(int arr[],int start,int end) //function for searching pivot element
{ 
    int mid=(start+end)/2;
    if(start==end)
        return start;
    
    if(start>end)
        return -1;
    if(arr[mid]>arr[mid+1])
    // (arr[mid]>arr[mid+1])&&(mid<end)
    {
        return mid;
    }
    else if (arr[mid]<arr[mid-1])
    //((arr[mid]<arr[mid-1])&&(mid>end))
    {
        return mid-1;
    }
    
    if(arr[start]>=arr[mid])
    {
        return pivotsearch(arr,start,mid-1);
    }
   
        return pivotsearch(arr,mid+1,end);
    
}


int pivotbinarysearch(int arr[],int start,int end, int key)
//function to deal with pivot element and binary search
{
   int pivot= pivotsearch(arr,start,end);
   cout<<pivot;
   if(pivot==-1)
   {
    return binarysearch(arr,start,end,key);
   }

if(arr[pivot]==key)
{
    return pivot;
}
    if(arr[0]<=key)
    {
      return binarysearch(arr,0,pivot,key);
    }

    else if(arr[0]>key)
    {
     return binarysearch(arr,pivot,end,key);
    }

    return -1;
  
}


int main()
{
    int list[]={4,5,6,7,0,1,2};
    cout<<"element found at index "<<pivotbinarysearch(list,0,6,0);

    return 0;
}
