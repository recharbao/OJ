// this pretest is so weak

#include<bits/stdc++.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> len;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        len.push_back(x);
    }
    string type;
    cin >> type;

    bool wter = false;
    ll time = 0;
    ll stamina = 0;
    ll towG = 0;

    for(int i = 0; i < n; i++)
    {
        if(type[i] == 'W')
        {
            wter = true;
            time += len[i] * 3;
            stamina += len[i];
        }
        else if(type[i] == 'L')
        {
            time += len[i];
            stamina -= len[i];
            if(stamina < 0)
            {
                time -= stamina * (wter ? 3 : 5);
                stamina = 0;
            }
        }
        else
        {
            time += len[i] * 5;
            stamina += len[i];
            towG += 2 * len[i];
        }
        towG = min(towG, stamina);
    }

    // cout << "stamina = " << stamina << endl;
    // cout << "towG = " << towG << endl;
    if(stamina > 0)
    {
        time -= 2 * towG;
        time -= (stamina - towG);
    }

    cout << time << endl;

    return 0;
}



/*

3
1 1 1
WLG

5
1 1 1 1 1
WLGGG

*/








//错误想法
/*
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> length;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        length.push_back(x);
    }
    string type;
    cin >> type;

    
    for(int i = 0; i < n; i++)
    {
        if(type[i] != 'L')
        {
            length[i] *= 2;
        }
    }


    int len = 0;
    int v = 6;
    int g = 0;
    int time = 0;
    for(int i = 0; i < n; i++)
    {
        if(type[i] == 'W')
        {
            v = 4;
            time += 2 * length[i];
            len += length[i];
        }
        else if(type[i] == 'G')
        {
            g += length[i];
            time += 3 * length[i];
            len += length[i];
        }
        else if(len >= length[i])
        {
            len -= length[i];
        }
        else
        {
            time += v * (length[i] - len);
            len = 0;
        }
    }

    cout << time << endl;
    time -= 3 * min(g, len);
    time -= 2 * max(len - g, 0);

    cout << time << endl;

    return 0;
}
*/















//下面是一种错误的想法
/*
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> length;
    string type;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        length.push_back(x);
    }
    cin >> type;

    int time = 0;
    int energy = 0;
    bool exitW = false;
    for(int i = 0; i < n; i++)
    {
        if(type[i] == 'G')
        {
            if(!exitW)
            {
                time += 5 * length[i];
                energy += length[i];
            }
            else
            {
                time += (energy + 4 * (length[i] - energy));
                cout << "time = " << time << endl;
                energy -= length[i];
            }
        }
        else if(type[i] == 'L')
        {
            if(energy >= length[i])
            {
                time += length[i];
                energy -= length[i];
            }
            else if(!exitW)
            {
                time += (energy + 6 * (length[i] - energy));
                energy = 0;
            }
            else
            {
                time += (energy + 4 * (length[i] - energy));
                energy = 0;
            }
        }
        else
        {
            if(!exitW)
            {
                exitW = true;
                time -= 2 * energy;
                energy = 0;
            }

            energy += length[i];
            time += 3 * length[i];
        }
    }

    if(!exitW)
    {
        time -= 2 * energy;
    }
    else
    {
        time -= energy;
    }

    cout << time << endl;
    
    return 0;
}
*/


