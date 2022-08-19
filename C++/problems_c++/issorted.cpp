#include<bits/stdc++.h>
using namespace std;

bool issorted(int arr[],int size)
{
    if(size==0||size==1)
    return true;
    if(arr[0]>arr[1])
    return false ;
    else
    return issorted(arr+1,size-1);
}
int main()
{
    int arr[]={1,2,3,4,9,6,8};
    int size= sizeof(arr)/sizeof(arr[0]);
   cout<<size<<endl<<issorted(arr,size);
    return 0;
}