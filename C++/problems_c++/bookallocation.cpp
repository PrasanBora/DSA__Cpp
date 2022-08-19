// Given an array ‘pages’ of integer numbers, where ‘pages[i]’ represents  the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to their students. 
// Allocate books in a way such that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to a student.
// 3. Book allocation should be in a contiguous manner.

// You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

#include <iostream>
#include <algorithm>  
#include <vector>  

using namespace std;

int checkbooks(int arr[],int nbooks,int mstudents,int avail)
{  
        int sum=0,count=1;
        for(int j=0;j<nbooks;j++)
        {
            // if(avail<arr[j]) 
            // return 0;
            // //if number of available pages are less than pages in a book;
            sum=sum+arr[j];  
          if(sum>avail)
          {
            count++;
            sum=arr[j];
            if(count>mstudents)
              return 0;
          }
        }
        return 1;
}

int allocateBooks(int arr[],int nbooks,int mstudents)
{
    if(mstudents>nbooks)
    {return -1;}

    int totalpages=0;
    for(int i=0;i<nbooks;i++)
    {
        totalpages=totalpages+arr[i];
        // start=max(start,arr[i]);
    }
    int ans,start=0,end=totalpages;
    // cout<<totalpages;  
    while(start<end)
    { 
      int mid=(start+end)/2;
      if(checkbooks(arr,nbooks,mstudents,mid))
      {
         ans=mid;
         end=mid-1;
      }
      else 
      start=mid+1;
    }
    return ans;

}
int main() {
    int n = 4;
    int m = 2;
    int pages[] = {10, 20, 30, 40};
    cout << "The minimum value of the maximum number of pages in book allocation is: " << allocateBooks(pages, n, m) << endl;
}