#include<iostream>
using namespace std;
class node
{
public:    
    int key;
    node(int k):key(k){}
    ~node(){}
};

class hashtable
{
private:
    node** table;
    int size;
    int divisor;
public:
    hashtable(int d)
    {
        table = new node * [d];
        divisor = d;
        size = 0;
        for (int i = 0; i < divisor; i++)
            table[i] = NULL;
    }
    int search(int k)
    {
        int i = k % divisor;//起始桶
        int j = i;
        do
        {
            if (table[j] == NULL || table[j]->key == k)
                return j;
            j = (j + 1) % divisor;
        } while (j != i);
        return j;
    }
    void insert(int x)
    {
        int index = search(x);
        if (table[index] == NULL)
        {
            table[index] = new node(x);
            cout << index << endl;
            size++;
        }
        else if (table[index]->key == x)
            cout << "Existed" << endl;
        else
            cout << "Full" << endl;
    }
    void find(int x)
    {
        int i = search(x);
        if (table[i] == NULL || table[i]->key != x)
        {
            cout << -1 << endl;
            return;
        }
        cout << i << endl;
    }
    void dele(int x)
    {
        int i = search(x);
        if (table[i] == NULL || table[i]->key != x)
            cout << "Not Found" << endl;
        else
        {
            delete table[i];
            table[i] = NULL;
            size--;

            int j = (i + 1) % divisor;//当前检查位置
            int f = j;//第一个检查位置
            int num = 0;
            while (table[j] != NULL && (j+1) % divisor != f)//遍历到空桶或回到起始位置时终止循环
            {
                int home = table[j]->key % divisor;//key的起始桶
                if ((home <= i && j > i) || (j > i && j < home)||(home>j&&home<=i))
                {
                    table[i] = table[j];
                    table[j] = NULL;
                    i = j;
                    num++;
                }
                j = (j + 1) % divisor;
            }
            cout << num << endl;
        }
    }
};
int main()
{
    int D, m;
    cin >> D >> m;
    hashtable t(D);
    int flag = 0,x = 0;
    while (m--)
    {
        cin >> flag >> x;
        switch (flag)
        {
        case 0:
        {
            t.insert(x);
            break;
        }
        case 1:
        {
            t.find(x);
            break;
        }
        case 2:
        {
            t.dele(x);
        }
        }
    }
}