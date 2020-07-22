#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n);

int main()
{
    vector<string> strs{"10","0","1"};
    int m,n;
    cin>>m>>n;
    int result;
    result=findMaxForm(strs,m,n);
    cout<<"result="<<result;
    return 0;
}


int findMaxForm(vector<string>& strs, int m, int n)
{
    //º∆À„(x,y)
    int N=strs.size();
    vector<vector<int>> nums(N,vector<int>(2));
    for(int i=0;i<N;i++)
    {
        nums[i][0]=count(strs[i].begin(),strs[i].end(),'0');
        nums[i][1]=count(strs[i].begin(),strs[i].end(),'1');
    }

    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    for(int i=0;i<N;i++)
    {
        int zeros=nums[i][0];
        int ones=nums[i][1];
        for(int x=m;x>=0;x--)
            for(int y=n;y>=0;y--)
                if(x>=zeros&&y>=ones)
                    dp[x][y]=max(dp[x][y],dp[x-zeros][y-ones]+1);
    }

    return dp[m][n];
}


