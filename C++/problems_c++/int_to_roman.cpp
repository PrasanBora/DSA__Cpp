#include<bits/stdc++.h>
using namespace std;

  string intToRoman(int num) 
    {
        vector<string>roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int>value={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        string ans="";
        
        for(int i=0;i<value.size(),num>0;i++)
            {
            
            int div = num/value[i]; //first app.
            num=num%value[i];
            while(div--)
            {ans+=roman[i];}
            
            // while(num>=value[i])  //second app.
          // {
          //           ans+=roman[i];
          //           num-=value[i];
          //   }
        }
        return ans;
    }
int main()
{
    return 0;
}