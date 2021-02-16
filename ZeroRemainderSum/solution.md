思路:

纯dp，但细节较复杂, 尤其是转移方程:

// dp[i][j][p][q] i, j位置, p 选择的个数, q 余数
转移方程:

dp[curi][curj][p][q] = max(dp[i][j][p][q], dp[curi][curj][p][q]); 与前面的比较, 看看是否变多，没有变多则按照原来的。

dp[curi][curj][p + 1][r] = max(dp[curi][curj][p + 1][r], dp[i][j][p][q] + a[i][j]); 这个是向后搜索的

有了转移方程，剩下套的就是四重循环了。
