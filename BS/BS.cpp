#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int i,j,hand,n;
    ifstream inp;
    inp.open("in.txt");
    inp>>n;
    int *a=new int[n];
    for(i=0;i<n;i++)
    {
        inp>>a[i];
    }
    inp.close();
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {  if(a[j]>a[j+1]){
            hand=a[j];
            a[j]=a[j+1];
            a[j+1]=hand;
        }
        }
    }
    ofstream oup;
    oup.open("ou.txt");
    for(i=0;i<n;++i)
    {
        oup<<a[i]<<" ";
    }
    oup.close();
    delete[] a;
    return 0;
}
