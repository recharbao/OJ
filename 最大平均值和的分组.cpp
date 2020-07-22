#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;


double largestSumOfAverages(vector<int>& A, int K);

int main()
{
    vector<int> A{1,2,3};
    int K=3;
    double result;
    result=largestSumOfAverages(A,K);
    cout<<result<<endl;
    return 0;
}


double largestSumOfAverages(vector<int>& A, int K) 
{
    //dp[i][k]表示前i个数被分成k时最大值；
    //dp[i][k]=max(dp[j][k-1]+average(j+1,i));
    //dp[i][0]=average(0,i);

    int n = A.size();

    vector<vector<double>> dp(n,vector<double>(K+1,0));
    for(int i=0;i<n;i++)
    {
        double sum=0;
        for(int j=i;j>=0;j--)
        {
            sum+=A[j];
        }
        dp[i][1]=(sum)/(i+1);
    }


    for(int i = 1;i < n;i++){
        for(int k=2;k<=K;k++){  //考虑很不清楚，注意
            if(k>i+1)break;
            for(int j=i-1;j>=0;j--){
                //计算平均值；
                double sum=0;
                for(int f=i;f>j;f--){
                    sum+=A[f];          //这个地方与下面的有差距
                }
                double average=sum/(i-j);
                dp[i][k]=max(dp[i][k],dp[j][k-1]+average);
            }
        }
    }

    return dp[n-1][K];
}





class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n=A.size();
        double dp[n][K+1];
        memset(dp,0,sizeof(dp));
        int sum[n+1];
        sum[0]=0;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+A[i-1];
        for(int i=0;i<n;i++) dp[i][1]=(double)sum[i+1]/(i+1);
        for(int k=2;k<=K;k++){
            for(int i=k-1;i<n;i++){
                for(int j=k-2;j<i;j++){             //边界处理有差距
                    dp[i][k]=max(dp[i][k],dp[j][k-1]+(double)(sum[i+1]-sum[j+1])/(i-j));
                }
            }
        }
        return dp[n-1][K];
    }
};





