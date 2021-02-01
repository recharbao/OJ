#include<bits/stdc++.h>
#include<string.h>
#include<vector>
using namespace std;

int a[105][105];
int rowSum[105];
int colSum[105];

void getRowSum(int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < m; j++)
        {
            sum += a[i][j];
        }
        rowSum[i] = sum;
    }
}

void getColSum(int n, int m)
{
    for(int j = 0; j < m; j++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += a[i][j];
        }
        colSum[j] = sum;
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }


    vector<int> r(n, 0);
    vector<int> c(m, 0);
    vector<int> resRow;
    vector<int> resCol;
    int min = -1;
    while (min < 0)
    {
        int index = -1;
        min = 0;
        getRowSum(n, m);
        getColSum(n, m);
        bool row = true;
        for(int i = 0; i < n; i++)
        {
            if(min > rowSum[i])
            {
                index = i;
                min = rowSum[i];
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(min > colSum[i])
            {
                row = false;
                index = i;
                min = colSum[i];
            }
        }

        if(row && min != 0)
        {
            resRow.push_back(index);
            r[index]++;
            for(int i = 0; i < m; i++)
            {
                a[index][i] = -1 * a[index][i];
            }
        }
        else if(min != 0)
        {
            resCol.push_back(index);
            c[index]++;
            for(int i = 0; i < n; i++)
            {
                a[i][index] = -a[i][index];
            }
        }
    }

    int rcnt = 0;
    string ansRow = "";
    for(int i = 0; i < resRow.size(); i++)
    {
        if(r[resRow[i]] % 2 == 1)
        {
            rcnt++;
            r[resRow[i]]--;
            ansRow += " " + to_string(resRow[i] + 1);
        }
    }

    int ccnt = 0;
    string ansCol = "";
    for(int i = 0; i < resCol.size(); i++)
    {
        if(c[resCol[i]] % 2 == 1)
        {
            ccnt++;
            c[resCol[i]]--;
            ansCol += " " + to_string(resCol[i] + 1);
        }
    }
    cout << rcnt << ansRow << endl;
    cout << ccnt << ansCol << endl;
    
    return 0;
}
























// 一开始的想法
/*
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }


    vector<int> resRow;
    vector<int> resCol;
    int min = -1;
    while (min < 0)
    {
        int index = -1;
        min = 0;
        getRowSum(n, m);
        getColSum(n, m);
        bool row = true;
        for(int i = 0; i < n; i++)
        {
            if(min > rowSum[i])
            {
                index = i;
                min = rowSum[i];
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(min > colSum[i])
            {
                row = false;
                index = i;
                min = colSum[i];
            }
        }

        if(row && min != 0)
        {
            resRow.push_back(index);
            for(int i = 0; i < m; i++)
            {
                a[index][i] = -1 * a[index][i];
            }
        }
        else if(min != 0)
        {
            resCol.push_back(index);
            for(int i = 0; i < n; i++)
            {
                a[i][index] = -a[i][index];
            }
        }
    }

    cout << resRow.size();
    for(int i = 0; i < resRow.size(); i++)
    {
        cout << " " << resRow[i] + 1;
    }

    cout << endl << resCol.size();
    for(int i = 0; i < resCol.size(); i++)
    {
        cout << " " << resCol[i] + 1;
    }
    cout << endl;
    
    return 0;
}
*/




/*

4 4
-6 -7 3 5
4 1 -3 5
3 -1 4 -4
-2 4 8 1






*/
