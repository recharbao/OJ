#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestArithSeqLength(vector<int>& a);

int main()
{
    int s[]={2,3};
    vector<int> a(s,s+2);
    int last;
    last=longestArithSeqLength(a);
    cout<<last;
    return 0;
}

int longestArithSeqLength(vector<int>& a)
{
    map<int,int> pos;
    int ans=0;
    int n=a.size();
    if(n<=2)return n;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int target=(a[i]<<1)-a[j];
            auto iter=pos.find(target);
            if(iter==pos.end())
            {
                dp[i][j]=2;
            }
            else
            {
                int k=iter->second;
                dp[i][j]=dp[k][i]+1;
                ans=max(ans,dp[i][j]);
            }
            
        }
        pos[a[i]]=i;
    }
    return ans;
}





/*

int longestArithSeqLength(vector<int>& a) {
    const int n = a.size();
    if (n <= 2) {
        return n;
    }

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    unordered_map<int, int> pos;

    int ans = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const int pre = (a[i] << 1) - a[j];
            auto iter = pos.find(pre);
            if (iter == pos.end()) {
                dp[i][j] = 2;
            } else {
                const int k = iter->second;
                dp[i][j] = dp[k][i] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        pos[a[i]] = i;
    }

    return ans;
}


*/




/*

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int,int>> dp(A.size());
        int n=A.size();
        int res=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int d=A[i]-A[j];
                if(dp[j].find(d)==dp[j].end()){
                    dp[i][d]=2;
                }
                else{
                    dp[i][d]=dp[j][d]+1;
                }
                res=max(res,dp[i][d]);
            }
        }
        return res;
    }
};
*/

















