
#include<bits/stdc++.h>
using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0, end=row*col -1;
        int value,mid;
        while(start<=end)
        {
              mid=(end+start)/2;
              value=matrix[mid/col][mid%col];        
            if(value==target)
                return true;
            else if(value<target)
               start=mid+1;
            else if(value>target)
                 end=mid-1;
        }
        return false;
    }

int main()
{
    return 0;
}