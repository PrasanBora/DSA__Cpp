#include<bits/stdc++.h>
using namespace std;

 int calculate(string s)
    {
        int len=s.length();
        int last=0,current=0,result=0;;
        char sign='+';
        
        for(int i=0;i<len;i++)
        {
             if(s[i]==' ')
                continue;

             while(isdigit(s[i]))
                 current =current*10 + ( s[i++]-'0' ); 
             
            if(sign=='+')
            {
                result+=last;
                last=current;
            }
            else if(sign=='-')
            {
                 result+=last;
                last=-current;
            }
            else if(sign=='*')
                last*=current;
            
            else if(sign=='/')
                last/=current;
            
            if(!isdigit(s[i]))
            {
                sign=s[i];
                current=0;
            }
        }
        result+=last;
        return result;
    }
int main()
{
    return 0;
}