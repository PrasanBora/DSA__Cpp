//Determine Whether Matrix Can Be Obtained By Rotation


// key points : m = number of rows, n = number of colms
// rotate 90 deg once ->   i, j <--> j,  m - i - 1
// rotate 90 deg twice ->  i, j <--> m - i - 1, n - j - 1 
// rotate 90 deg thrice -> i, j <--> n - j - 1, i

#include<bits/stdc++.h>
using namespace std;

 void rotate(vector<vector<int>>& matrix) {
        
        int size=matrix.size();
        int temp=0;
        for(int i=0;i<size ;i++)
            for(int j=i;j<size;j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int k=0;k<size;k++)
        {
            for(int p=0;p<size/2;p++)
            swap(matrix[k][p],matrix[k][size-1-p]);
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for(int i=0;i<4;i++)
        {
            rotate(mat);
            if(mat==target)
                return true;
        }
           return false;
    }

    //-------2Apporach-----------------

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        bool rot1,rot2,rot3,rot4;
         
        rot1=rot2=rot3=rot4=true;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=target[j][n-1-i])
                    rot1=false;
                if(mat[i][j]!=target[n-1-i][n-1-j])
                    rot2=false;
                if(mat[i][j]!=target[n-1-j][i])
                    rot3=false;
                if(mat[i][j]!=target[i][j])
                    rot4=false;
            }
        }
        return rot1||rot2||rot3||rot4;
    }
int main()
{
    return 0;
}