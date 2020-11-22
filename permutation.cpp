#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;


int main()
{
    ll m1;
    cin >> m1;
    string m = to_string(m1);
    ll n;
    cin >> n;

    sort(m.begin(), m.end());
    int count = 0;
    do{
        ll tmpm = stoll(m);
        if(tmpm % n == 0 && m[0] != '0') count++;
    }while (next_permutation(m.begin(), m.end()));
    
    cout << count << endl;

    return 0;
}


/*
int main()
{
    //string s = "435";
    string s = "345";
    do{
        cout << s << endl;
    }while (next_permutation(s.begin(), s.end()));
    return 0;
}

*/
