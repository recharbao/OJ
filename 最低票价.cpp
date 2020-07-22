#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int mincostTickets(vector<int>& days, vector<int>& costs);

int main()
{
    int result;
    vector<int>days{1,4,6,7,8,20};
    vector<int>cost{2,7,15};
    result = mincostTickets(days,cost);
    cout<<"result="<<result;
    return 0;
}

/*
int mincostTickets(vector<int>& days, vector<int>& costs)
{
    if(days.size()==0)
        return 0;
    int tmp1,tmp2,tmp3;
    int n = days.size();
    vector<int>dp(n,0);
    dp[0] = min(costs[0],min(costs[1],costs[2]));

    if(n==1)return dp[0];

    for(int i = 1;i < n;i++)
    {
        int tmp;
        int minus1 = days[i] - 1;
        int minus7 = days[i] - 7;
        int minus30 = days[i] - 30;

        tmp1 = dp[i-1] + costs[0];
        int j = i - 1;
        while (j >= 0 && minus7 < days[j]) j--;
        if(j >= 0)
            tmp2 = dp[j] + costs[1];
        else
        {
            tmp2 = costs[1]; 
        }

        j = i - 1;
        while (j >= 0 && minus30 < days[j]) j--;
        if(j >= 0)
            tmp3 = dp[j] + costs[2];
        else
        {
            tmp3 = costs[2];
        }
        dp[i] = min(tmp1,min(tmp2,tmp3));
    }        

    return dp[n-1];
}


*/


int mincostTickets(vector<int>& days, vector<int>& costs)
{
    if(days.size()==0)
        return 0;
    int tmp1,tmp2,tmp3;
    int n = days.size();
    vector<int>dp(n,0);
    dp[0] = min(costs[0],min(costs[1],costs[2]));

    if(n==1)return dp[0];

    for(int i = 1;i < n;i++)
    {
        int tmp;
        int minus1 = days[i] - 1;
        int minus7 = days[i] - 7;
        int minus30 = days[i] - 30;

        tmp1 = dp[i-1] + costs[0];
        int j = i - 1;
        while (j >= 0 && minus7 < days[j]) j--;
        if(j >= 0)
            tmp2 = dp[j] + costs[1];
        else
            tmp2 = costs[1];

        //j = i - 1;    It is repeated.
        while (j >= 0 && minus30 < days[j]) j--;
        if(j >= 0)
            tmp3 = dp[j] + costs[2];
        else
            tmp3 = costs[2];
        dp[i] = min(tmp1,min(tmp2,tmp3));
    }        

    return dp[n-1];
}