#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

int maxProfit(vector<int>& prices);

int main()
{
    vector<int> prices{1,2,3,0,2};
    int result;
    result=maxProfit(prices);
    cout<<result;
    return 0;
}
/*
int maxProfit(vector<int>& prices) 
{
    if(prices.size()==0)
    {
        return 0;
    }
    int n=prices.size();

    //包含三种状态；
    vector<int> Hold(n);
    vector<int> Free(n);
    vector<int> Colddown(n);

    Hold[0]=-prices[0];
    Free[0]=0;
    Colddown[0]=0;    

    for(int i=1;i<n;i++)
    {
        Hold[i] = max(Free[i-1]-prices[i],Hold[i-1]);
        Free[i] = max(Free[i-1],Colddown[i-1]);
        Colddown[i] = Hold[i-1]+prices[i];
    }

    return max(Hold[n-1],max(Free[n-1],Colddown[n-1]));

}

*/




int maxProfit(vector<int>& prices) 
{
    if(prices.size()==0) return 0;
    int n=prices.size();
    //包含三种状态；
    int Hold=-prices[0];
    int Free=0;
    int Colddown=0;
    
    for(int i=1;i<n;i++)
    {
        int pre_Hold=Hold;
        Hold = max(Free-prices[i],Hold);
        Free = max(Free,Colddown);
        Colddown = pre_Hold+prices[i];
    }

    return max(Hold,max(Free,Colddown));

}










class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int cooldown = 0;
        int free = 0;
        for(auto &p : prices){
            int pre_cooldown = cooldown;
            cooldown = hold + p;
            hold = max(free - p, hold);
            free = max(pre_cooldown, free);
        }
        return max(free, cooldown);
    }
};



