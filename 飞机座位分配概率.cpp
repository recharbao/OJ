#include<iostream>
#include<vector>
using namespace std;


 double nthPersonGetsNthSeat(int n);


 int main()
 {
    int n;
    cin>>n;
    double result;
    result=nthPersonGetsNthSeat(n);
    cout<<result;
    return 0;
 }

{1,2,3,4,5,6,7,8,9,10}
double nthPersonGetsNthSeat(int n)
{
    double dp[n+1];
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=1/(double)i+((i-2)/(double)i)*dp[i-1];
    }
    return dp[n];
}



