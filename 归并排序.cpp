#include<iostream>
using namespace std;
//将两个有序表归并
/* 
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
*/


void Merge(int R[],int low,int mid,int high)
{
    int k=0;
    int *S=new int [high-low+1];
    int i=low;
    int j=mid+1;
    while (i<=mid&&j<=high)
    {
        if(R[i]<R[j])
        {
            S[k]=R[i];
            k++;
            i++;
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
        k++;
        i++;
    }
    while (j<=high)
    {
        S[k]=R[j];
        k++;
        j++;
    }
    for(k=0,i=low;i<=high;i++,k++)
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



int main()
{
    int R[]={3,4,5,7,1,2,0,8,7,12,56,4};
        MergeSort(R,12);
    for(int i=0;i<12;i++)
        cout<<i+1<<"~"<<R[i]<<endl;
    return 0;
}




