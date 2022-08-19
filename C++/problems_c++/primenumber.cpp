 
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     return 0;
 }
 
 int countPrimes(int n) {
        int count=0;
        vector<bool>prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i <= n;i++)
            if(prime[i])     
               for(int j=i*i;j<=n;j=j+i)
                    prime[j]=0;
        for(int j=0;j<n;j++)
               if(prime[j])count++;
        return count;   
    }