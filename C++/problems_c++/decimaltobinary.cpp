#include<iostream>
#include <math.h>
#include <stdio.h>
 
using namespace std;
int main()
{   
    int decimal;
    int binary[100],i=0;
    
    cin>>decimal;
     while (decimal>0)
     {
        // cout<<i<<endl;
        binary[i]=decimal%2;
        decimal=decimal/2;
         i++;
        
     } 
    
      int mid =i/2;
 for(int j=0;j<mid;j++)
{
      int temp=binary[i-j-1];
      binary[i-j-1]=binary[j];
      binary[j]=temp;
}
int num=0;
for(int j=0;j<i;j++)
{ 
    int bit;
  bit=binary[j]==0 ? 1:0;
  num=num+pow(2,(i-j-1))*bit;
  cout<<num<<endl;
}

    return 0;
}
