#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    if(n < 5)
    {
        cout << "YES" << endl;
        return 0;
    }
    vector<vector<ll> > point;
    for(int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vector<ll> tmp;
        tmp.push_back(x);
        tmp.push_back(y);
        point.push_back(tmp);
    }

    bool flag = false;
    for(int i = 0; i < 3; i++)
        for(int j = i + 1; j < 4; j++)
            for(int k = j + 1; k < 5; k++)
                if((point[i][1] - point[j][1]) * (point[j][0] - point[k][0]) == (point[i][0] - point[j][0]) * (point[j][1] - point[k][1]))
                {
                    flag = true;
                    swap(point[i], point[0]);
                    swap(point[j], point[1]);
                    swap(point[k], point[2]);
                }

    if(!flag)
    {
        cout << "NO" << endl;
        return 0;
    }

    flag = true;
    int count = 0;
    for(int i = 3; i < n; i++)
    {
        if((point[0][0] - point[1][0]) * (point[i][1] - point[1][1]) == (point[i][0] - point[1][0]) * (point[0][1] - point[1][1])) continue;
        if((point[0][0] - point[1][0]) * (point[i][1] - point[1][1]) != (point[i][0] - point[1][0]) * (point[0][1] - point[1][1]) && (count >= 2 && (point[3][0] - point[4][0]) * (point[i][1] - point[4][1]) != (point[i][0] - point[4][0]) * (point[3][1] - point[4][1]))) flag = false;
        else if(count == 0)
        {
            count++;
            swap(point[i], point[3]);
        }
        else if(count == 1)
        {
            count++;
            swap(point[i], point[4]);
        }
        
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
