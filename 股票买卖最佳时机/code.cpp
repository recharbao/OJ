#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxProfit(int k, vector<int>& prices);

int main()
{
    vector<int> prices{7,0,5,8,7,6,5,4,3,2,2,2,2,2,1};
    int result = maxProfit(4, prices);
    cout << "result = " << result << endl;

    return 0;
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    
    if (k*2 > n)
    {
        vector<int> dpHand(n + 1, 0);
        vector<int> dpFree(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int s = dpFree[i - 1] - prices[i - 1];
            int t = dpHand[i - 1];
            dpHand[i] = (i == 1 ? s : (t > s ? t : s));
            if(i > 1) dpFree[i] = max(t + prices[i - 1], dpFree[i - 1]);
        }
        return dpFree[n];
    }
    
    vector<vector<int> > hand(n + 1, vector<int>(k + 1, 0));
    vector<vector<int> > free(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            hand[i][j] = (i == 1 ? free[i - 1][j - 1] - prices[i - 1] : (hand[i - 1][j] > free[i - 1][j - 1] - prices[i - 1] ? hand[i - 1][j] : free[i - 1][j - 1] - prices[i - 1]));
            if(i > 1)   free[i][j] = max(hand[i - 1][j] + prices[i - 1], free[i - 1][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, free[n][i]);
    
    return ans;
}


