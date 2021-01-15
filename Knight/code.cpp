#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cout << 2 * i / 3 << " " << 2 * i % 3 << endl;
    
    return 0;
}
