
#include <iostream>

using namespace std;


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

int main()
{
    int list[]={1,3,5,7,8,9};
    cout<<"element found at index "<<binarysearch(list,6,5);

    return 0;
}
