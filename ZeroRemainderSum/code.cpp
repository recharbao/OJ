#include<bits/stdc++.h>
#include<vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;

const int N = 80;
int a[N][N];
int dp[N][N][N][N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }

    forn(i, N)forn(j, N)forn(p, N)forn(q, N) dp[i][j][p][q] = INT32_MIN;
    dp[0][0][0][0] = 0;
    forn(i, n)forn(j, m)forn(p, m / 2 + 1)forn(q, k)
    {
        if(dp[i][j][p][q] == INT32_MIN) continue;
        int curi = (j == m - 1 ? i + 1 : i);
        int curj = (j == m - 1 ? 0 : j + 1);
        //cout << "curj = " << curj << endl;
        if(i != curi)
        {
            //dp[curi][curj][0][q] = dp[i][j][p][q];
            dp[curi][curj][0][q] = max(dp[i][j][p][q], dp[curi][curj][0][q]);
        }
        else
        {
            //dp[curi][curj][p][q] = dp[i][j][p][q];
            dp[curi][curj][p][q] = max(dp[i][j][p][q], dp[curi][curj][p][q]);
        }
        if(p + 1 <= m / 2)
        {
            int r = (q + a[i][j]) % k;
            if(i != curi)
            {
                dp[curi][curj][0][r] = max(dp[curi][curj][0][r], dp[i][j][p][q] + a[i][j]);
            }
            else
            {
                dp[curi][curj][p + 1][r] = max(dp[curi][curj][p + 1][r], dp[i][j][p][q] + a[i][j]);
            }
            
        }

        
    }

    //cout << dp[n][0][0][0] << endl;
    cout << max(0, dp[n][0][0][0]) << endl;

    return 0;
}


// dp[i][j][p][q] i, j位置, p 选择的个数, q 余数



