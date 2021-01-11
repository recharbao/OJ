#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef long long ll;

//记录?点
struct node
{
    int left;
    int right;
    int diff;
    int id;
} orign[100000], change;

bool operator < (const node &s, const node &t)
{
    return s.diff < t.diff;
}


int main()
{
    string s;
    cin >> s;

    priority_queue<node> que;
    int leftCount = 0;
    int cur = 0;
    ll cost = 0;
    bool flag = false;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            leftCount++;
        }
        else if(s[i] == ')')
        {
            leftCount--;
        }
        else
        {
            cin >> orign[cur].left >> orign[cur].right;
            orign[cur].diff = orign[cur].right - orign[cur].left;
            orign[cur].id = i;
            s[i] = ')';
            leftCount--;
            cost += orign[cur].right;
            que.push(orign[cur]);
            cur++;
        }

        if(leftCount < 0)
        {
            if(!que.empty())
            {
                change = que.top();
                que.pop();
            }
            else
            {
                flag = true;
                break;
            }

            cost -= change.diff;
            leftCount += 2;
            s[change.id] = '(';
        }
    }

    if(leftCount != 0 || flag)
        cout << -1 << endl;
    else
    {
        cout << cost << endl;
        cout << s << endl;
    }

    return 0;
}
