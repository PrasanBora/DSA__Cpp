
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
    // default value of next will be the index of arr
    for(int i=0;i<size-1;i++)
        next[i]=i+1;
    // for last element no element exist therfore putting -1 
    next[size-1]=-1;

    // default values of front and rear for queues 
    for(int j=0;j<nq;j++)
    {
        front[j]=-1;
        rear[j]=-1;
    }
  }

  void enqueue(int val ,int qn)
  {
    // is space is available thatis any freespot is present or not 
    if(freespot==-1)
    {
        cout<<"Overflow ! Arr is full"<<endl;
        return;
    }
    // store freespot
      int index= freespot;
    // update the freespot that is next for index
      freespot=next[index];

    // check is pushing first element to queue
     if(front[qn-1]==-1)
        front[qn-1]=index; // updating the front as its first element 

     
     else 
        next[rear[qn-1]]=index; // making the link between last element 
                                 //and new element using the next arr
      
        arr[index]=val; // store val to arr
        rear[qn-1]=index; // updating the rear for queue
        next[index]=-1;  // marking the next of current index as -1 representing a 
                         // a value is there 
    
        cout<< " ELEMENT  ADDED "<<endl;
  }
  
  void dequeue(int qn)
  {
    // check if queue is empty or not 
     if(front[qn-1]==-1)
    {
        cout<<"Underflow ! queue is empty"<<endl;
        return;
    }
    // store front of queue to be deleted
    int index = front[qn-1];
    // update front of queue
    front[qn-1]=next[index];
     
    // create link btw deleted space and freespot 
    next[index]=freespot;
    // update freespot to index 
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