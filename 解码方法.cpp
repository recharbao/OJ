#include<iostream>
using namespace std;

long numDecodings(string s);

int main()
{
    string s="10101010101010101010101010101010101010101";
    //cout<<"s[4]="<<s[4]<<endl;
    long result;
    result=numDecodings(s);
    cout<<result;
    return 0;
}


long numDecodings(string s)
{
    long n=s.size();
    cout<<"n="<<n<<endl;
    long long  dp[n];
    dp[0]=1;
    if(s.size()==1)return dp[0];
    string t;
    string m=to_string(26);
    //cout<<"m="<<m<<endl;
    t=to_string(s[0]-48)+to_string(s[1]-48);
    cout<<"ttt="<<t<<endl;
    t <=m ? dp[1]=2 :dp[1]=1;
    cout<<"dpdp="<<dp[1]<<endl;
    if(s.size()==2)return dp[1];
    for(long i=2;i<n;i++)       
    {
        //cout<<"s[i-1]="<<s[i-1]<<endl;
       // cout<<"s[i]="<<s[i]<<endl;

        t=to_string(s[i-1]-48)+to_string(s[i]-48);
        cout<<"t="<<t<<endl;
        if(t<=m)
        {
            dp[i]=dp[i-1]+dp[i-2];
            cout<<"dp1="<<dp[i]<<endl;
        }
        else
        {
            dp[i]=dp[i-1];
            cout<<"dp2="<<dp[i]<<endl;
        }
    }
    return dp[n-1];         
}



