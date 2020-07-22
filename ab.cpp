#include <iostream>
#include<string.h>
#include<vector>
#include <iomanip>
using namespace std;

int main() {
    vector<double> a;
    vector<double> b;
    vector<double> result;
    int counta = -1;
    int countb = -1;
    while (true)
    {
        double tmp;
        cin >> tmp;
        a.push_back(tmp);
        counta ++;
        if(counta >= 2 * a[0])
        {
            break;
        }
       
    }

    while (true)
    {
        double tmp;
        cin >> tmp;
        b.push_back(tmp);
        countb ++;
        if(countb >= 2 * b[0])
        {
            break;
        }
    }
    

    int i_e = 1;
    int j_e = 1;


    while (i_e + 1 < a.size() && j_e + 1 < b.size())
    {
        if(a[i_e] == b[j_e])
        {
            double tmp = a[i_e + 1] + b[j_e + 1];
            if(tmp == 0)
            {
                i_e += 2;
                j_e += 2;
                continue;
            }
            result.push_back(a[i_e]);
            result.push_back(tmp);
            i_e += 2;
            j_e += 2;
        }
        else if(a[i_e] < b[j_e])
        {
            result.push_back(b[j_e]);
            result.push_back(b[j_e + 1]);
            j_e += 2;
        }
        else if(a[i_e] > b[j_e])
        {
            result.push_back(a[i_e]);
            result.push_back(a[i_e + 1]);
            i_e += 2;
        }
    }
    while(i_e + 1 < a.size())
    {
        result.push_back(a[i_e]);
        result.push_back(a[i_e + 1]);
        i_e += 2;
    }

    while(j_e + 1 < b.size())
    {
        result.push_back(b[j_e]);
        result.push_back(b[j_e + 1]);
        j_e += 2;
    }


    cout << result.size()/2;
    for(int i = 0; i < result.size(); i++)
	{
       if(i % 2 == 0)
       {
           cout << " " << int(result[i]);
       }
       else
       {
           cout << " " << setiosflags(ios::fixed)<<setprecision(1) << result[i];
       }
        
    }

    return 0;
}