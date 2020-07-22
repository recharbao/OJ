#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countNumbersWithUniqueDigits(int n);

int main()
{
    int result,n=4;
    result=countNumbersWithUniqueDigits(n);
    cout<<result;
    return 0;
}


    int countNumbersWithUniqueDigits(int n) {
        vector<int> f = {9,9,8,7,6,5,4,3,2,1};
        int t = 1;
        for (int k=1; k<=n; k++) {
            int p = 1;
            for (int i=0; i<k; i++) p = p*f[i];
            t += p;
        }
        return t;
    }






/*
int countNumbersWithUniqueDigits(int n)
{
    if(n==0||n>10)return 0;
    if (n==1)return 10;

    int dp=10;

    
}
*/