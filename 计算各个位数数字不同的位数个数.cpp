#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countNumbersWithUniqueDigits(int n);

int main()
{
    int n=3,result;
    result=countNumbersWithUniqueDigits(n);
    cout<<result;
    return 0;
}

int countNumbersWithUniqueDigits(int n)
{
    if(n==0)return 1;
    if(n>10)return 0;
    if(n==1)return 10;
    int sum=10;
    int list[10]={9,9,8,7,6,5,4,3,2,1};
    for(int i=2;i<=n;i++)
    {
        int tmp=1;
        for(int j=0;j<i;j++)
            tmp*=list[j];
        sum+=tmp;
    }
    
    return sum;
}

