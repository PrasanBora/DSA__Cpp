#include <iostream>
#include<vector>

using namespace std;

vector<int> bubblesort(vector<int> arr,int size)
{ 
    for(int i=size-1; i>=1; i--)
    { 
        bool swaped =false;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swaped=true;
            }
        }
        if(swaped==false)
        {
            cout<<"no action needed"<<endl;
            return arr;
        }
    }
    return arr;
}

vector<int> insertionsort(vector<int>arr,int size)
{ 
    int key,j;
    for(int i=1;i<size;i++)
    {
      key=arr[i];
      j=i-1;
      while(arr[j]>key && j>=0)
      {
        arr[j+1]=arr[j];
        j=j-1;
      }
    //   cout<<j<<endl;
      arr[j+1]=key;
    }
    return arr;
}

int main()
{
    vector<int> sort={2,4,9,10,3,8,6,7,5,1};
    // {2,4,9,10,3,8,6,7,5,1};
    // {1,2,3,4,5,6,7,8,9,10};

    // vector<int>done=bubblesort(sort,10);

    vector<int>done=insertionsort(sort,10);
    for(int i=0;i<10;i++)
    {
        cout<<done[i];
    }

    return 0;
}
