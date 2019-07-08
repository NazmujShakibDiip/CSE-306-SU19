#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void dismerge(int a[],int start,int last,int n);
void merge_sort(int a[],int i,int j,int i1,int j1,int Array);
int main()
{
    ifstream input;
     input.open("100000.txt");
     int n,i,j,temp;
    int *a=new int[n];
    input>>n;
    for(i=0;i<n;i++)
    {
        input>>a[i];
    }
    input.close();
     clock_t startTime=clock();
    dismerge(a,0,n-1,n);
    clock_t endTime=clock();
    double timeLapse=double(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<timeLapse<<endl;
    ofstream output;
    output.open("sorted 100k.txt");
    for(i=0;i<n;i++)
    {
        output<<a[i]<<endl;
    }
    output.close();
    delete[]a;
    return 0;
}
void dismerge(int a[],int start,int last,int n)
{
    int mid,z=n;
    if(start<last)
    {
        mid=(start+last)/2;
        dismerge(a,start,mid,z);
        dismerge(a,mid+1,last,z);
        merge_sort(a,start,mid,mid+1,last,z);
    }
}
void merge_sort(int a[],int i,int j,int i1,int j1,int Array)
{
    int k,s,m;
    s=i;
    m=i1;
    k=0;
    int *temp=new int[Array];
    while(s<=j&&m<=j1)
    {
        if(a[s]<a[m])
        {
            temp[k++]=a[s++];
        }
        else
            temp[k++]=a[m++];
    }
    while(s<=j)
    {
        temp[k++]=a[s++];
    }
    while(m<=j1)
    {
        temp[k++]=a[m++];
    }
    for(s=i,m=0;s<=j1;s++,m++)
    {
        a[s]=temp[m];
    }
}
