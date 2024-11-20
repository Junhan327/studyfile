#include<iostream>
using namespace std;

class bucket
{
private:
    int key;
public:
    bucket(int key_) :key(key_) {}
    void setkey(int key_)
    {
        key = key_;
    }
    int getkey()
    {
        return key;
    }
};

class hashTable
{
private:
    bucket** table;
    int D;
public:
    hashTable(int D_)
    {
        D = D_;
        table = new bucket * [D];
        for (int i = 0; i < D; i++)
        {
            table[i] = nullptr;
        }
    }
    ~hashTable() {
        delete[]table;
    }
    int search(int key)//返回应该插入的位置或存在的位置；表满的时候返回初始位置
    {
        int init = key % D;
        int j = init;
        do
        {
            if (table[j] == nullptr || table[j]->getkey() == key )
            {
                return j;
            }
            j = (j + 1) % D;
        } while (j != init);
        return j;
    }
    void find(int key)
    {
        int temp = search(key);
        if (table[temp] == nullptr || table[temp]->getkey() != key)
        {
            cout << "-1" << endl;
            return;
        }
        cout << temp << endl;
        return;
    }
    void insert(int key)
    {
        int temp = search(key);
        if (table[temp] == nullptr)
        {
            table[temp] = new bucket(key);
            cout << temp << endl;
            return;
        }
        else if (table[temp]->getkey() == key)
        {
            cout << "Existed" << endl;
            return;
        }
    }
    void erase(int key)
    {
        int temp = search(key);
        if (table[temp] == nullptr || table[temp]->getkey() != key)
        {
            cout << "Not Found" << endl;
            return;
        }
        delete table[temp];
        table[temp] = NULL;
        int init = (temp + 1) % D;//初始检查位置
        int cur = init;
        int num = 0;
        while (table[cur] != nullptr && (cur + 1) % D != init)//遍历到空桶或回到起始位置时终止循环
        {
            int home = table[cur]->getkey() % D;//key的起始位置
            if ((home <= temp && cur > temp) || (cur < home && cur >temp) || (cur < home && home <= temp))
            {
                table[temp] = table[cur];
                table[cur] = nullptr;
                temp = cur;
                num++;
            }
            cur = (cur + 1) % D;
        }
        cout << num << endl;
    }
};
int main()
{
    int D, m;
    cin >> D >> m;
    hashTable mytable(D);
    int opt, x;
    while (m--)
    {
        cin >> opt >> x;
        switch (opt)
        {
        case 0:
        {
            mytable.insert(x);
            break;
        }
        case 1:
        {
            mytable.find(x);
            break;
        }
        case 2:
        {
            mytable.erase(x);
        }
        }
    }
}