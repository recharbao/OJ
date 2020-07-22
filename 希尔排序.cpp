#include<iostream>
using namespace std;
void SerSort(int R[],int n);


int main()
{
    int R[]={3,4,5,7,1,2,0,8,7,12,56,4};
        SerSort(R,12);
    for(int i=0;i<12;i++)
        cout<<i+1<<"~"<<R[i]<<endl;
    return 0;
}

void SerSort(int R[],int n)
{
    int d=n/2;
    int j;
    int tmp;
    while (d>0)
    {
        for(int i=d;i<n;i++)
        {
            tmp=R[i];
            j=i-d;
            while (j>=0&&tmp<R[j])
            {
                R[j+d]=R[j];
                j=j-d;
            }
            R[j+d]=tmp;
        }
        d=d/2;
    }
    
}












