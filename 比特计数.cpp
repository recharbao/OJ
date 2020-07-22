#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> countBits(int num);


int main()
{
    int num;
    cin>>num;
    vector<int> dp;
    dp=countBits(num);
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i];
    }
    return 0;
}
/*
vector<int> countBits(int num)
{
    vector<int> dp(num+1,0);
    int r=0;
    int point=0;
    for(int i=1;i<=num;i++)
    {
       if(point>=pow(2,r))
       {
           point=0;
            r++;
       }
        dp[i]=dp[point++]+1;
    }
    return dp;
}
*/





vector<int> countBits(int num)
{
    vector<int> dp(num+1,0);
    dp[0]=0;
    dp[1]=1;
    int r=1;
    int point=0;
    for(int i=2;i<=num;i++)
    {
       if(point>=(r<<1))
       {
           point=0;
            r=(r<<1);
            cout<<"r="<<r<<endl;
       }
        dp[i]=dp[point++]+1;
    }
    return dp;
}

/*
vector<int> countBits(int num)
{
    vector<int> dp(num+1,0);
    dp[0]=0;
    dp[1]=1;
    int r=1;
    int point=0;
    for(int i=2;i<=num;i++)
    {
       if(point>=pow(2,r))
       {
           point=0;
            r++;
            cout<<"r="<<r<<endl;
       }
        dp[i]=dp[point++]+1;
    }
    return dp;
}

*/