#include<iostream>
using namespace std;
class solution
{
private:
    int n;
    int arr[1000000];
    int Nums[20];

public:
    static int result; 
    void generate(int i)
{
    if(i>=n)//得到一种子集
    {
        int temp=0;
        int j=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                temp +=arr[i]*j;
                j++;
            }     
        }
        result ^= temp;
        return;
    }
    arr[i]=Nums[i];
    generate(i+1);
    arr[i]=0;
    generate(i+1);
}
void getnumber()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        Nums[i]=temp;
    }
}
};
int solution::result =0;
int main()
{
    solution a;
    a.getnumber();
    a.generate(0);
    cout<<a.result<<endl;
    return 0;
}