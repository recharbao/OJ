#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

 int stoneGameII(vector<int>& piles);

int main()
{
    vector<int> piles{2,7,9,4,4};
    int result;
    result=stoneGameII(piles);
    cout<<result;
}





//dp[i][j]是指剩余i堆石子，当M等于j时玩家一拿到的最大重量
//dp[i][j]=max(sum[N]-sum[i]-dp[i-k][max(j,k)])(1<=k<=2*j);
// dp[i][j] = max{sums[N] - sums[i] - dp[i - k][max(k, j)]} (1 <= k <= 2 * j)
    int stoneGameII(vector<int>& piles) {
        int N = piles.size();
        vector<int> sums(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            sums[i + 1] = sums[i] + piles[i];
        }        
        vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= N; ++i) {
            for (int j = i; j <= N; ++j) {
                dp[i][j] = sums[N] - sums[N - i];
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int k = 1; k <= 2 * j && k <= i; ++k) {
                    dp[i][j] = max(dp[i][j], sums[N] - sums[N - i] - dp[i - k][min(max(k, j), N)]);
                }
            }
        }
        return dp[N][1];
    }

/*
class Solution {
public:
    int mem[102][52];
    int sum[102];
    int n = 0;
    int solve(int start, int M) {
        if (mem[start][M] != -1) return mem[start][M];
        int ret = 0;
        for (int i = 1; i <= 2 * M && start + i - 1 < n; ++i) {
            ret = max(ret, sum[start] - solve(start + i, max(M, i)));
        }
        return mem[start][M] = ret;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(mem, -1, sizeof(mem)); memset(sum, 0, sizeof(sum));
        for (int i = n - 1; i >= 0; --i) sum[i] = sum[i + 1] + piles[i];
        return solve(0, 1);
    }
};


int REM[70][100];
class Solution {
public:
    vector<int> S = vector<int>(105,0);
    int foo(int M,int id,vector<int>& piles){
        if(REM[M][id]){
            return REM[M][id];
        }
        int res= S[piles.size()] - S[id];
        if(id+2*M>=piles.size()){
            REM[M][id] = res;
            return res;
        }
        int ret= INT_MAX;
        for(int i = id+1;i<=id+2*M;i++){
            ret = min(ret,foo(max(M,i-id),i,piles));
        }
        REM[M][id] = res-ret;
        return res - ret;
    }
    int stoneGameII(vector<int>& piles) {
        memset(REM,0,sizeof(REM));
        S[0]= 0;
        for(int i = 1;i<piles.size()+1;i++){
            S[i] = S[i-1] + piles[i-1];
        }
        return foo(1,0,piles);
    }
};


class Solution {
public:
    //记忆化搜索
    int stoneGameII(vector<int>& piles) {
        //dp[i][j]  从i到末尾的石子堆中 M=j的情况下，先手抓的玩家能够获取的最大石子树
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
        int sum = 0;        
        for(int i=0;i<piles.size();i++)
            sum += piles[i];
        return dfs(piles,0,1,dp,sum);
    }
    int dfs(vector<int>& piles,int loc,int M,vector<vector<int>>& dp,int sum){
        if(loc>=piles.size())
            return 0;
        if(dp[loc][M]==0){//未计算过
            int MaxRes =0;
            int takeNum = 0;
            for(int j=1;j<=2*M&&loc+j<=piles.size();j++){
                takeNum += piles[j+loc-1];//先手选取的石子堆石子总数
                //此时先手获取的石子总数最多 即选取之后下一个先手获取的总数最少
                MaxRes = max(MaxRes,sum-dfs(piles,loc+j,max(M,j),dp,sum-takeNum));//五角星max(M,j) Not max(M,2*j) Not 2*j
            }
            dp[loc][M] = MaxRes;
        }   
        return dp[loc][M];
    }
};

*/
