#include<iostream>
#include<cmath>
using namespace std;
int arr[1000000];
int Nums[20];
int result = 0;
void bianli(int &n,int Nums[])
{
    for(int i=0;i<pow(2,n);i++)
    {
        int a=i;
        int CurrentValue=0;
        int place=1;
        for(int j=0;j<n;j++)
        {
            arr[j]=a%2;
            if(arr[j]!=0)
            {
                CurrentValue+=Nums[j]*place;
                place++;
            }
            a=a/2;
        }
        result^=CurrentValue;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        Nums[i]=temp;
    }
    bianli(n,Nums);
    cout<<result<<endl;
    return 0;
}