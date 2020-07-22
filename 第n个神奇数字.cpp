#include<iostream>
#include<algorithm>
using namespace std;

int nthMagicalNumber(int N, int A, int B);

int main()
{
    int N,A,B;
    cout<<"N = "<<endl;
    cin>>N;
    cout<<"A = "<<endl;
    cin>>A;
    cout<<"B = "<<endl;
    cin>>B;
    int result;
    result = nthMagicalNumber(N,A,B);
    cout<<"result = "<<result<<endl;
    return 0;
}
   
int nthMagicalNumber(int N, int A, int B)
{
    const int MOD = 1e9 + 7;
    long left = min(A,B);
    long right = left * N;
    long mid;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        if((mid / A + mid / B - mid / ((A * B)/__gcd(A,B))) >= N) 
            right = mid;
        else
            left = mid + 1;
    }
    
    return left % MOD;
    
}