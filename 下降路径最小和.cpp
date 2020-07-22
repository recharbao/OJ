#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minFallingPathSum(vector<vector<int>>& A);

int main()
{
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    int result;
    result=minFallingPathSum(A);
    cout<<result;
    return 0;
}



int minFallingPathSum(vector<vector<int>>& A)
{
    int m=A.size();
    int n=A[0].size();
    int MIN = INT_MAX;
    vector<vector<int>> dp(m,vector<int>(vector<int>(n,0)));

    for(int i=0;i<n;i++)
    {
        dp[0][i]=A[0][i];
        MIN = min(A[0][i],MIN);
    }
    if(A.size()==1)return MIN;

    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0&&j!=(n-1))
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+A[i][j];
            else if(j==0)
                dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+A[i][j];
            }
        }
    }
   MIN=INT_MAX;
   for(int i=0;i<n;i++)
    {
        if(MIN>dp[m-1][i])
        {
            MIN=dp[m-1][i];
        }
    }

    return MIN;
}