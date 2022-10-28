
#include<bits/stdc++.h>
using namespace std;
class kqueues
{
private:
  int n;
  int * front;
  int * rear;
  int * arr;
  int * next;
  int freespot;
  int k;
public:
  kqueues( int size, int nq)
  {
    this->n=size;
    this->k=nq;
    front = new int [nq];
    rear = new int [nq];
    arr = new int [size];
    next=new int [size];
    freespot=0;

    for(int i=0;i<size-1;i++)
        next[i]=i+1;

    next[size-1]=-1;
    for(int j=0;j<nq;j++)
    {
        front[j]=-1;
        rear[j]=-1;
    }
  }

  void enqueue(int val ,int qn)
  {
    if(freespot==-1)
    {
        cout<<"Overflow ! Arr is full"<<endl;
        return;
    }
     int index= freespot;
      freespot=next[index];

     if(front[qn-1]==-1)
        front[qn-1]=index;
     
     else 
        next[rear[qn-1]]=index;
      
        arr[index]=val;
        rear[qn-1]=index;
        next[index]=-1;
       

        cout<< " ELEMENT  ADDED "<<endl;
  }
  
  void dequeue(int qn)
  {
     if(front[qn-1]==-1)
    {
        cout<<"Underflow ! queue is empty"<<endl;
        return;
    }
    int index = front[qn-1];
    front[qn-1]=next[index];

    next[index]=freespot;
    freespot=index;

    cout<<"deleted - "<<arr[index]<<" from q - "<<qn <<endl;
  }
};

int main()
{
    kqueues ks(20,4);
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);
 
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    ks.dequeue(2);
    ks.dequeue(2);
    ks.dequeue(1);
    ks.dequeue(1);
    ks.dequeue(1);
    ks.dequeue(1);

    return 0;
}