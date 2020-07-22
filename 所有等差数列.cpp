#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A);

int main()
{
    int result;
    vector<int> A{2, 4, 4, 6};
    result=numberOfArithmeticSlices(A);
    cout<<result;
    return 0;
}



int numberOfArithmeticSlices(vector<int>& A)
{
    int n=A.size();
    cout<<"n="<<n<<endl;
    map<int,vector<int> >m;
    for(int i=0;i<n;i++)
        m[A[i]].push_back(i);
    vector<vector<int>> dp(n,vector<int>(n,0));
    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"A["<<j<<"]"<<A[j]<<endl;
            int target=(A[j]<<1)-A[i];
            if(m.count(target)>0)
            {
                for(int k:m[target])
                {
                    if(k<j)
                    {
                        cout<<"k="<<k<<endl;
                        dp[i][j]+=dp[j][k]+1;
                    }
                }
            result+=dp[i][j];
            }
        }
    }
    return result;
}





















/*
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        unordered_map<long, vector<int>> m;

        for (int i = 0; i < n; ++i) {
            m[A[i]].push_back(i);
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int c = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long target = 2 * ((long) A[j]) - A[i];
                if (m.count(target) > 0) {
                    for (int k : m[target]) {
                        if (k < j) {
                            dp[i][j] += (dp[j][k] + 1);
                        }
                    }
                    c += dp[i][j];
                }
            }
        }
        return c;
    }
};



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size(); if(len <= 2) return 0;
       vector<unordered_map<int, int>> vec(len);
        int res = 0;
        for(int i = 1; i < len; ++i){
            for(int j = 0; j < i; ++j){
                long delta = long(A[i]) - long(A[j]);
                if(delta > INT_MAX || delta < INT_MIN) continue;
                if(vec[j].count(delta) != 0){
                    vec[i][delta] += vec[j][delta];
                    res += vec[j][delta];
                }
             vec[i][delta] += 1;
                
            }
        }
        
        return res;
    }
};


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<long long, int>> dp(A.size());
        vector<long long> AA(A.size());
        for(int i=0; i<A.size(); i++){
            AA[i] = A[i];
        }
        int i=0;
        int ans = 0;
        for(int i=0; i<AA.size(); i++){
            for(int j=0; j<i; j++){
                long long gap = AA[i] - AA[j];
                int count = 0;
                if(dp[j].find(gap) != dp[j].end()) count = dp[j][gap];
                if(dp[i].find(gap) == dp[i].end()) dp[i][gap] = count + 1;
                else dp[i][gap] = dp[i][gap] + count + 1;
                ans += count;
            }
        }
        return ans;
    }
};



#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        set<int> diff;
		int n = A.size();
		//列举出所有的公差，预处理
		LL ans = 0;
		vector < unordered_map<LL, int>> dp(n);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int sum = 0;
				LL diff = (LL)A[i] - (LL)A[j];
				if (dp[j].count(diff)) {
					sum = dp[j][diff];
				}
				dp[i][diff] += (sum + 1);
				ans += sum;
			}
		}
		return (int)ans;
    }
};



*/