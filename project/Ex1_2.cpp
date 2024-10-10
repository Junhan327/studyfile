#include<iostream>
using namespace std;
class solution
{
    private:
    int n;//序列元素数量
    int list[20];

    public:

    static int result; 

    void permutations(int k)
    {
        if(k==(n-1))//此时产生一种排列方式
        {
            int j=1;
            int currentvalue=0;
            for(int i=0;i<n;i++)
            {
                currentvalue+=list[i]^j;
                j++;
            }
            result |= currentvalue;
        }
        else
        {
            for(int i=k;i<=(n-1);i++)
            {
                int temp2;
                temp2=list[k];
                list[k]=list[i];
                list[i]=temp2;
                permutations(k+1);
                temp2=list[k];
                list[k]=list[i];
                list[i]=temp2;
            }
        }
    }
void getnumber()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        list[i]=temp;
    }
}
};

int solution::result = 0;

int main()
{
    solution a;
    a.getnumber();
    a.permutations(0);
    cout<<solution::result<<endl;
    return 0;
}