#include<iostream>
using namespace std;

int main()
{
    int A1, B1, C1, A2, B2, C2;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;
    if (A1 * B2 != A2 * B1) cout << 1 << endl;
    else
    {
        if(A1 != 0 && A2 != 0 && A2 * C1 == A1 * C2) cout << -1 << endl;
        else if(A1 != 0 && A2 != 0) cout << 0 << endl;
        else if((A1 == 0 && A2 != 0) || (A1 != 0 && A2 == 0))
        {
            if(B1 != 0 && B2 != 0) cout << 1 << endl;
            else if(B1 == 0 && C1 != 0 || B2 == 0 && C2 != 0) cout << 0 << endl;
            else cout << -1 << endl;
        }
        else if(A1 == 0 && A2 == 0)
        {
            if(((B1 == 0 && C1 == 0) && (B2 == 0 && C2 == 0)) || ((B1 != 0 || B2 != 0) && B1 * C2 == B2 * C1)) cout << -1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}
