#include<iostream>
#include<vector>
using namespace std;
int numberOfArithmeticSlices(vector<int>& A);
int main()
{
    int last;
    int s[]={8,9,10,11};
    vector<int> A(s,s+4);
    last=numberOfArithmeticSlices(A);
    cout<<last;
    return 0;
}

/* int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size()<3)
    return 0;
        int D[A.size()];
        int Dnums=A.size()-1,k=0,sum=0;
        int equal[A.size()];
        for(int i=0;i<A.size();i++)//初始值的确定只能使用循环；
            equal[i]=2;
        for(int i=0;i<Dnums;i++)
            D[i]=A[i+1]-A[i];
        for(int i=0;i<Dnums-1;i++)
        {
            if(D[i]==D[i+1])
                equal[k]++;
            else
                k++;
        }
        for(int i=0;i<=k;i++)
            if(equal[i]>2)
                sum+=(equal[i]-1)*(equal[i]-2)/2;
            return sum;
    }

*/


    /*int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int pre = 3;
        for (int i=2; i<nums.size(); ++i) {
            if (nums[i]-nums[i-1] == nums[i-1] - nums[i-2]) {
                ans += (pre - 2);
                pre++;
            }else{
                pre = 3;
            }
        }
        return ans;
    }

*/

/* int numberOfArithmeticSlices(vector<int>& A) {
		int len = A.size(), result = 0;
		vector<int> dp(len, 0);//dp[i]用于保存以A[i]结尾的等差数列的个数
		for (int i = 2; i < len; ++i) {//等差数列长度需要大于2，所以前两个必定为0
            //判断步长
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
				dp[i] = dp[i - 1] + 1;//转移方程
				result += dp[i];//求和
			}
		}
		return result;
	}
*/


//动态规划


int numberOfArithmeticSlices(vector<int>& A)
{
    int len=A.size(),result=0;
    vector<int> dp(len,0);
    for(int i=2;i<len;i++)
    {
        if(A[i]-A[i-1]==A[i-1]-A[i-2])
        {
            dp[i]=dp[i-1]+1;
            result+=dp[i];
        }
    }
    return result;
}






