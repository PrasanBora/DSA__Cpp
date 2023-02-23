
#include<bits/stdc++.h>
using namespace std;

  class heap 
  {
    public:
    int arr[100];
    int size =0;
    
    void print()
    {  
      cout<<endl;
      for(int i=1;i<=size;i++)
      {
        cout<<arr[i]<<" ";
      }
    }
    void insert (int val )
    {
      size =size+1;
      int index = size;
      arr[index]=val ;
       while (index> 1)
       {
        int parent = index/2;
        if(arr[parent]<arr[index])
        {
          swap(arr[parent],arr[index]);
          index=parent; 
        }
         else 
         return;
       }
    }
     void delet()
     {
      cout<<"delete_called";
       arr[1]=arr[size];
       size--;
       int i=1;
       while(size>i)
       {
         int left = 2*i ;
         int right =2*i +1;

         if(left <size && arr[i]<arr[left])
            {
              swap( arr[i],arr[left]);
              i=left;
            }
         else if(right <size && arr[i]<arr[right])
            {
              swap( arr[i],arr[right]);
              i=right;
            }
            else 
            return ;
       }
     }

     // heapify function 

     void heapify(int arr[],int n, int i)
     {
       int largest =i;
       int left = 2*i+1;
       int right =2*i+2; 
       
       if(left<n && arr[largest]<arr[left])
       {
         largest=left;
       }
       if(right<n && arr[largest]<arr[right])
       {
         largest=right;
       }

       if(largest!=i)
       {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
       }

     }

     void heapsort(int arr[],int n)
     {
      //making a max heap 
       for(int i=n/2 -1;i>=0;i--)
       {
        heapify(arr,n,i);
       }

       for(int i=n-1;i>=0;i--)
       {
        swap(arr[0],arr[i]);
         heapify(arr,i,0);
       }
     }

  };
int main()
{
    heap h;
    h.insert(10);
    h.insert(12);
    h.insert(0);
    h.insert(1);
    h.insert(19);
    h.insert(13);

    h.print();
    h.delet();

    h.print();
    
    int arr2[] = { -1,12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr2) / sizeof(arr2[0]);
      cout<<endl<<"-----------"<<endl;
    for(int i=0 ;i<N;i++)
    {
      cout<<arr2[i]<<" ";
    }
   
    cout<<endl<<"heap sort called "<<endl;
  
    h.heapsort(arr2,N);
    for(int i=0 ;i<N;i++)
    {
      cout<<arr2[i]<<" ";
    }
    return 0;
}