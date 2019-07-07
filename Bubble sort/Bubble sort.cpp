#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    ifstream input;
     input.open("10000.txt");
     int n,i,j,temp;
    int *a=new int[n];
    input>>n;
    for(i=0;i<n;i++)
    {
        input>>a[i];
    }
    input.close();
     clock_t startTime=clock();
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
            }
        }
    }
    clock_t endTime=clock();
    double timeLapse=double(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<timeLapse<<endl;
    ofstream output;
    output.open("sorted 10k.txt");
    for(i=0;i<n;i++)
    {
        output<<a[i]<<endl;
    }
    output.close();
    delete[]a;
    return 0;
}
