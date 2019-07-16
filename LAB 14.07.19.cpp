#include <iostream>

using namespace std;

void MAX(int temp[], int n, int amount);
void MIN(int temp[], int n, int amount);
int main()
{
    int i, j,amount,n=10, k=0;
    int temp[10];
    int coin[4]={5, 10, 20, 25};
    int num[4]={2, 3, 3, 2};
    cout<<"ENTER THE AMOUNT : ";
    cin>>amount;
    cout<<"The coins are: ";
    for(i=0; i<4; i++)
    {
        for(j=0; j<num[i]; j++)
        {
            temp[k]=coin[i];
            cout<< temp[k]<<" ";
            k++;
        }
    }
    cout<<"\nThe coins are: "<<endl;
    MAX(temp, n, amount);
    cout<<"\nThe coins are: "<<endl;
    MIN(temp, n, amount);

    return 0;
}
void MAX(int temp[], int n, int amount)
{
    int i, j, Count=0;
    for(i=0; i<n; i++)
    {
        if(amount>=temp[i])
        {
            amount=amount-temp[i];
            cout<<temp[i]<<" ";
            Count++;
        }

    }
    cout<<"\nMaximum number of coins: "<<Count<<endl;

}

void MIN(int temp[], int n, int amount)
{
    int i, j, Count=0;
    for(i=n-1; i>0; i--)
    {
        if(amount>=temp[i])
        {
            amount=amount-temp[i];
            cout<<temp[i]<<" ";
            Count++;

        }

    }
    cout<<"\nMinimum number of coins: "<<Count<<endl;

}
