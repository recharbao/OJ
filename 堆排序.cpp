#include<iostream>
using namespace std;

void HeadSort(int R[],int n);

void sift(int R[],int low,int high);



void sift(int R[],int low,int high)//1~12
{
    int i=low;
    int j=2*i;
    int tmp=R[i];
    while (j<=high)
    {
        if(j<high&&R[j]<R[j+1])
            j++;
        if(tmp<R[j])
        {
            R[i]=R[j];
            i=j;
            j=2*i;
        }
        else
            break;
    }

    R[i]=tmp;
}

void HeadSort(int R[],int n)
{
    for(int i=n/2;i>=0;i--)
        sift(R,i,n);
    for(int i=n;i>=1;i--)
    {
        swap(R[1],R[i]);
        sift(R,1,i-1);
    }
}




int main()
{
    int R[]={3,4,5,7,1,2,0,8,7,12,56,4};
    HeadSort(R,12);
    for(int i=0;i<12;i++)
        cout<<i+1<<"~"<<R[i]<<endl;
    return 0;
}

