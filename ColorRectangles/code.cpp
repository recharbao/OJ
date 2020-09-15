
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


int ColRec(vector<vector<int> > a);

int main(){
    vector<int> ColorNum(3);
    vector<vector<int> > num;
    for(int i = 0; i < 3; i++){
        cin >> ColorNum[i];
    }

    int a;

    for(int i = 0; i < 3; i++)
    {
        vector<int> tmp;
        for(int j = 0; j < ColorNum[i]; j++)
        {
            cin >> a;
            tmp.push_back(a);
        }
        num.push_back(tmp);
    }
    int result = ColRec(num);

    cout << result <<endl;

    return 0;
    
}

bool static cmp(int a, int b)
{
    return a > b;
}


int ColRec(vector<vector<int> > a)
{
    int ans = 0;
    int x = a[0].size();
    int y = a[1].size();
    int z = a[2].size();
    vector<vector<vector<int> > > dp(x + 1, vector<vector<int> >(y + 1,vector<int>(z + 1,0)));
    sort(a[0].begin(), a[0].end(), cmp);
    sort(a[1].begin(), a[1].end(), cmp);
    sort(a[2].begin(), a[2].end(), cmp);


    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            for (int k = 0; k <= z; k++)
            {
                if(i < x && j < y)
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[0][i] * a[1][j]);
                if(i < x && k < z)
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[0][i] * a[2][k]);
                if(j < y && k < z)
                    dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + a[1][j] * a[2][k]);                    
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    
    return ans;
}


