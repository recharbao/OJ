#include<iostream>
#include<algorithm>
using namespace std;

#define  MAXV 1000

//√∞≈›≈≈–Ú(small~big)

void RubbleSort(int S[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(S[i]>S[j])
                swap(S[i],S[j]);
        }
    }
}

//±Í◊ºµƒ√∞≈›≈≈–Ú

void RubbleSort(int S[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(S[j]>S[j-1])
            {
                swap(S[j],S[j-1]);
            }
        }
    }
}




//—°‘Ò≈≈–Ú
void SelectSort(int S[],int n)
{
    for(int i=0;i<n;i++)
    {
        int k=i;
        for(int j=i+1;j<n;j++)
            if(S[k]>S[j])
                k=j;
        if(k!=i)
            swap(S[k],S[i]);
    }
}

//≤Â»Î≈≈–Ú

int partition(int S[],int s,int t)
{
    int tmp=S[s];
    int i=s;
    int j=t;
    while (i<j)
    {
        while (j>i&&S[j]>=tmp)
        {
            j--;
        }
        S[i]=S[j];
        while (i<j&&S[i]<=tmp)
        {
            i++;
        }
        S[j]=S[i];
    }
    S[i]=tmp;
    return  i;
}

void QuickSort(int S[],int s,int t)
{
    int i;
    if(s<t)
    {
        i=partition(S,s,t);
        partition(S,s,i-1);
        partition(S,i+1,t);
    }
}

//πÈ≤¢≈≈–Ú
#include<iostream>
using namespace std;
//Ω´¡Ω∏ˆ”––Ú±ÌπÈ≤¢
void Merge(int R[],int low,int mid,int high)
{
    int k=0;
    int i=low;
    int j=mid+1;
    int *S=new int [high-low+1];
    while (i<=mid&&j<=high)
    {
        if(R[i]<R[j])
        {
            S[k]=R[i];
            i++;
            k++;
        }
        else
        {
            S[k]=R[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        S[k]=R[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        S[k]=R[j];
        j++;
        k++;
    }
    for(i=low,k=0;i<=high;i++,k++)
        R[i]=S[k];
    delete[] S;
}


/* 

void MergePass(int R[],int length,int n)
{
    int i;
    for(i=0;i+2*length-1<n;i=i+2*length)
        Merge(R,i,i+length-1,i+2*length-1);
    if(i+length-1<n-1)
         Merge(R,i,i+length-1,n-1);
}

void MergeSort(int R[],int n)
{
    for(int length=1;length<n;length=length*2)
       MergePass(R,length,n);
}

*/

void MergeSortDC(int R[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSortDC(R,low,mid);
        MergeSortDC(R,mid+1,high);
        Merge(R,low,mid,high);
    }
}

void MergeSort(int R[],int n)
{
    MergeSortDC(R,0,n-1);
}

//’€∞Î≤Â»Î≈≈–Ú

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



//œ£∂˚≈≈–Ú
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

//∂—≈≈–Ú
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
    for(int i=n/2;i>=1;i--)
        sift(R,i,n);
    for(int i=n;i>=2;i--)
    {
        swap(R[1],R[i]);
        sift(R,1,i-1);
    }
}

