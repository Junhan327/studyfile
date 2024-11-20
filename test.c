#include<iostream>
using namespace std;
class node
{
public:
    int key;
    node* next;
    node(int k) :key(k) { next = NULL; }
    ~node() {}
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
    int search(int k)//寻找k值在桶中的序号
    {
        int i = k % divisor;
        if (table[i] == NULL)
            return -1;
        else
        {
            node* t = table[i];
            int j = 1;
            while (t != NULL)
            {
                if (t->key == k)
                    return j;
                j++;
                t = t->next;
            }
            return -1;
        }
    }
    void find(int k)
    {
        int i = search(k);
        if (i == -1)
        {
            cout << "Not Found" << endl;
            return;
        }
        else
        {
            int i = k % divisor;
            int len = 0;
            node* t = table[i];
            while (t != NULL)
            {
                len++;
                t = t->next;
            }
            cout << len << endl;
        }
    }
    void insert(int k)
    {
        int i = search(k);
        if (i != -1)
        {
            cout << "Existed" << endl;
            return;
        }
        else
        {
            int i = k % divisor;
            if (table[i] == NULL)
                table[i] = new node(k);
            else
            {
                node* temp = new node(k);
                temp->next = table[i];
                table[i] = temp;
            }
        }
    }
    void dele(int k)
    {
        int i = search(k);
        if (i == -1)
        {
            cout << "Delete Failed" << endl;
            return;
        }
        else
        {
            if (i == 1)
            {
                node* temp = table[k % divisor];
                table[k % divisor] = table[k % divisor]->next;
                delete temp;
            }
            else
            {
                node* temp = table[k % divisor];
                for (; i - 2 > 0; i--)
                    temp = temp->next;
                node* t = temp->next;
                temp->next = temp->next->next;
                delete t;
            }
            node* temp = table[k % divisor];
            int len = 0;
            while (temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            cout << len << endl;
        }
    }
};
int main()
{
    int D, m;
    cin >> D >> m;
    hashtable t(D);
    int flag = 0, x = 0;
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