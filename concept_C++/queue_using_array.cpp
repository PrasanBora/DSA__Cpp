#include<bits/stdc++.h>
using namespace std;

class queue_
{
    int * arr;
    int front ;
    int rear;
    int size;
    
    public :
      queue_ (int s)
      {
         arr =new int [s];
         front =0;
         rear =0;
      }

      bool isempty( )
      {
        if(rear==size)
         return false ;
         else 
         return true;
      }

      int enqueue(int data)
      {
        if (rear==size)
          {
            cout<<"Queue is full "<<endl;
            return -1 ;
          }
          arr[rear]=data;
          rear++;
      }

      int dequeue()
      {
        if(front == rear )
         {cout<<"queue is empty ";
         return -1;}
         
         int ret =arr[front];
         arr[front]=-1;
         front ++;
         if(front ==rear)
         {
            front =rear=0;
         }
          return ret;
      }

      int frontview ()
      {
        if(front ==rear )
        {
            cout<<"Queue is empty";
            return -1;
        }
        else 
          return arr[front];
      }

};
int main()
{
    queue_ qt(10);
    
    cout<<qt.isempty()<<endl;
    cout<<qt.frontview()<<endl;
    qt.enqueue(23);
    cout<<qt.frontview()<<endl;
    qt.enqueue(06);
    cout<<qt.dequeue()<<endl;
    cout<<qt.frontview()<<endl;
    return 0;
}