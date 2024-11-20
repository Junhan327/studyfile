#include <iostream>
using namespace std;
class bucket
{
public:
    int key;
    bucket *next;
    bucket(int key_) : key(key_) { next = nullptr; };
};

class hashTable
{
private:
    bucket **table;
    int D;

public:
    hashTable(int D_)
    {
        D = D_;
        table = new bucket *[D];
        for (int i = 0; i < D; i++)
        {
            table[i] = nullptr;
        }
    }
    ~hashTable()
    {
        delete[] table;
    }
    void find(int key)
    {
        int temp = key % D;
        bucket *cur = table[temp];
        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                int length = 0;
                bucket *cur = table[temp];
                while (cur)
                {
                    length++;
                    cur = cur->next;
                }
                cout << length << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Not Found" << endl;
    }
    void insert(int key)
    {
        int temp = key % D;
        bucket *cur = table[temp];
        if (table[temp] == nullptr)
        {
            table[temp] = new bucket(key);
            return;
        }
        while (cur)
        {
            if (cur->key == key)
            {
                cout << "Existed" << endl;
                return;
            }
            cur = cur->next;
        }
        bucket *newbucket = new bucket(key);
        newbucket->next = table[temp];
        table[temp] = newbucket;
        return;
    }
    void erase(int key)
    {
        int temp = key % D;
        if (table[temp] == nullptr)
        {
            cout << "Delete Failed" << endl;
            return;
        }
        bucket *pre = nullptr;
        bucket *cur = table[temp];
        bool isfind = false;
        if (cur->key == key)
        {
            isfind = true;
            table[temp] = cur->next;
            delete cur;
        }
        else
        {
            while (cur)
            {
                if (cur->key == key)
                {
                    isfind = true;
                    pre->next = cur->next;
                    delete cur;
                    break;
                }
                pre = cur;
                cur = cur->next;
            }
        }
        if (!isfind)
        {
            cout << "Delete Failed" << endl;
        }
        else
        {
            int i = key % D;
            int length = 0;
            bucket *cur = table[temp];
            while (cur)
            {
                length++;
                cur = cur->next;
            }
            cout << length << endl;
        }
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