#include<bits/stdc++.h>
#include<map>
#include<set>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t, k;
    cin >> t >> k;
    string res = "";
    for(int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        n--, m--;
        if(n > m) {
            swap(n, m);
        }

        int s = m + n + n / (k + 1);

        if (n % (k + 1) == k) {
            // cout << "s = " << s << endl;
            if (s % 2 == 0) {      
                s++;
            }
        }
        // if(m == n && n % k == 0 && (n / k) % 2 == 1) {
        //     s++;
        // }
        //if(k % 2 == 0) {
        if(k > 1) {
            if(s % 2 == 1) {
            //cout <<"tt = " << tt << "  s = " << s << " " << "+" << endl;
            res += "+";
            }else {
                res += "-";
            }
        }else {
            if((m % 2 == 0) && (n % 2 == 0)) {
                res += "-";
            }else {
                res += "+";
            }
        }
        
        //}else {
          //  if(s % 2 == 0) {
            //    cout << "+" << endl;
            //}else {
             //   cout << "-" << endl;
            //}
        //}
    }

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
