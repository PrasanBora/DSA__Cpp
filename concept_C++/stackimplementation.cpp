
#include<bits/stdc++.h>
using namespace std;

class stackk
{
    public:
    int top;
    int size ;
    int *arr;

    stackk(int size )
    {
            this->size=size;
            arr = new int[size];
            top=-1;
    }
    
    void push(int element )
    {
       if(size-top > 1)
       {
        top=top+1;
        arr[top]=element;
       }
       else 
       cout<<"stack is full"<<endl;
    }
    
    void pop()
    {
        if(top>-1)
         top--;
         else 
         cout<<"stack underflow";
    }
    
     int peek()
     {
         if(top>-1 && top <size)
         {
            return arr[top];
         }
         else cout<<"stack is empty";
     }

     bool isempty()
     {
          if (top==-1)
          return true;
          else 
          return false ;
     }

};

int main()
{
    stackk st (5);
      st.push(23);
        cout<<st.peek()<<endl;
      st.push(67);
        cout<<st.peek()<<endl;
      st.push(9);
        cout<<st.peek()<<endl;
      st.push(0);
        cout<<st.peek()<<endl;
      st.push(76);
        cout<<st.peek()<<endl;
      st.push(12);
      st.pop();
      st.pop();
        cout<<st.peek()<<endl;
    return 0;
}