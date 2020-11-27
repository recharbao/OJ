
#include<iostream>
using namespace std;


int main()
{
    int k;
    cin >> k;
    int positive = 1e6 - k % 2000;
    int negative = (positive + k) / 2000 - positive;

    cout << 2000 << endl;
    for(int i = 0; i < 1998; i++)   cout << 0 << " ";

    cout << negative << " " << positive << endl;
    
    return 0;
}



