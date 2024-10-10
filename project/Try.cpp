#include<iostream>
using namespace std;
template<class T>
class mySort
{
    private:
    int num;//需排序的数的个数
    public:
    mySort(int Num):num(Num){}
    ~mySort(){}
    void RankSort()
    {
        T *nums = new T[num];
        for(int i=0;i<num;i++)
        {
            cin>>nums[i];
        }
        T *rank = new T[num];//存放各数的名次
        for(int i = 0;i<num;i++)
        {
            //将名次全部初始化为0
            rank[i]=0;
        }
        for(int i =1;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<=nums[i])
                {
                    rank[i]++;
                }
                else
                {
                    rank[j]++;    
                }
            }
        }
        T *temp = new T[num];
        for(int i=0;i<num;i++)
        {
            temp[rank[i]]=nums[i];//将元素存放到对应名次的位置
        }
        for(int i=0;i<num;i++)
        {
            cout<<temp[i]<<' ';
        }
        delete []temp;
        delete []rank;
        delete []nums;
    }

    void SelectionSort()
    {
        T *nums = new T[num];
        for(int i=0;i<num;i++)
        {
            cin>>nums[i];
        }
        bool Sorted = false;
        for(int i=num;i>1&&!Sorted;i--)
        {
            Sorted = true;
            int indexOfMax = 0;
            for(int j=1;j<i;j++)
            {
                if(nums[indexOfMax]<=nums[j])
                {   
                    indexOfMax = j;
                }
                else
                    Sorted = false; //如果右面有更小的数，说明数列未有序
            }
            T temp = nums[indexOfMax];
            nums[indexOfMax]=nums[i-1];
            nums[i-1]=temp;
        }
        for(int i=0;i<num;i++)
        {
             cout<<nums[i]<<' ';
        }
        delete []nums;
    }
    void bubbleSort()
    {
        T *nums = new T[num];
        for(int i=0;i<num;i++)
        {
            cin>>nums[i];
        }
        for(int i=0;i<num;i++)
        {
            bool swapped =false;
            for(int j=0;j<num-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    T temp = nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    swapped = true;
                }
            }
            if(!swapped)
            {
                break;
            }
        }
        for(int i=0;i<num;i++)
        {
            cout<<nums[i]<<' ';
        }
        delete []nums;
    }
    void insertSort()
    {
        T *nums = new T[num];
        for(int i=0;i<num;i++)
        {
            cin>>nums[i];
        }
        for(int i=1;i<num;i++)
        {
            T temp = nums[i];
            int j;
            for(j=i-1;j>=0&&temp<nums[j];j--)//从i-1逐个与nums[i]比较，若比nums[i]大，则更换值
            {
                nums[j+1]=nums[j];
            }
            //循环结束，将temp放到对应的位置上
            nums[j+1]=temp;
        }
        for(int i=0;i<num;i++)
        {
            cout<<nums[i]<<' ';
        }
        delete []nums;
    }
};
int main()
{
    int N;
    cin>>N;
    mySort<int>SORT(N);
    SORT.RankSort();
    //SORT.SelectionSort();
    //SORT.bubbleSort();
   //SORT.insertSort();
}