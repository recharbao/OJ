#include<iostream>
#include<vector>
using namespace std;
int maximalSquare(int S[][5]);
int main()
{
    int S[][5]={{1,1,1,1,0},
                {1,0,1,1,1},
                {1,1,1,1,1},
                {1,0,1,0,1},
                {1,1,1,1,1}};
    
    int MAX=maximalSquare(S);
    cout<<MAX<<endl;
}

int maximalSquare(int S[][5])
{
    int dp[5][5]={0};
    int MAX=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(dp[i-1][j-1]>=1&&i>0&&j>0)
            {
                int ok=1;
                for(int k=j-dp[i-1][j-1];k<=j;k++)
                    if(S[i][k]==0)
                        ok=0;
                for(int l=i-dp[i-1][j-1];l<=i;l++)
                    if(S[l][j]==0)
                        ok=0;
                if(ok)
                    dp[i][j]=dp[i-1][j-1]+1;
            }
            else  if(S[i][j]==1)
                dp[i][j]=1;
        }
    }
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(dp[i][j]>MAX)
                MAX=dp[i][j];

    return MAX*MAX;
}


