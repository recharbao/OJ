#include<iostream>
using namespace std;

void BinInsert(int R[],int n);

int main()
{
    int R[]={3,4,5,7,1,2,0,8,7,12,56,4};
        BinInsert(R,12);
    for(int i=0;i<12;i++)
        cout<<i+1<<"~"<<R[i]<<endl;
    return 0;
}

void BinInsert(int R[],int n)
{
    int low,high,mid,tmp;
    for(int i=1;i<n;i++)
    {
        tmp=R[i];
        low=0;
        high=i-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if(R[mid]>tmp)
                high=mid-1;
            else
                low=mid+1;
        }

        for(int j=i-1;j>=high+1;j--)
            R[j+1]=R[j];
        R[high+1]=tmp;
    }
}




