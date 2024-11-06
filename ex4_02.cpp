#include<iostream>
using namespace std;
struct chainNode
{
    int element;
    chainNode* next;
};

class myiterator;

class chain
{
private:
    chainNode* head = nullptr;
public:
    int arrofresult[2000];
    int numofarr = 0;
    int size;
    chain(int initialCapacity)
    {
        size = initialCapacity;
        if (initialCapacity > 0)
        {
            head = new chainNode;
            chainNode* p = head;
            for (int i = 1; i < initialCapacity; i++)
            {
                p->next = new chainNode;
                p = p->next;
            }
            p->next = nullptr;
        }
    }
    void insert(int idx, int val)
    {
        chainNode* currentNode = new chainNode;
        currentNode->element = val;
        if (idx == 0)
        {
            currentNode->next = head;
            head = currentNode;
        }
        else
        {
            chainNode* p = head;
            for (int i = 0; i < idx - 1; i++)
            {
                p = p->next;
            }
            currentNode->next = p->next;
            p->next = currentNode;
        }
    }
    void erase(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        chainNode* p = head->next;
        if (head->element == val)
        {
            chainNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        while (p != nullptr)
        {
            if (p->element == val)
            {
                chainNode* temp = p->next;
                p->next = temp->next;
                delete temp;
                return;
            }
            else {
                p = p->next;
            }
        }
        arrofresult[numofarr] = -1;
        numofarr++;
    }

    void findidx(int val)
    {
        chainNode* p = head;
        int i = 0;
        while (p != nullptr)
        {
            if (p->element == val)
            {
                arrofresult[numofarr] = i;
                numofarr++;
                return;
            }
            else
            {
                i++;
                p = p->next;
            }
        }
            arrofresult[numofarr] = -1;
            numofarr++;
    }
    void inversion()
    {
        chainNode* pre = nullptr;
        chainNode* cur = head;
        chainNode* nex = nullptr;
        while (cur != nullptr)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        head = pre;
    }
    void elementxor()
    {
        int index = 0;
        int result = 0;
        myiterator it;
        for (it = begin(); it != end1(); it++)
        {
            result += index ^ (it.node->element);
            index++;
        }
        cout << result << endl;
    }
    void bubbleSort()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        for (int i = 0; i < size; i++)
        {
            chainNode* cur = head->next;
            chainNode* pre = head;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (pre->element > cur ->element)
                {
                    int temp = cur->element;
                    cur->element = pre->element;
                    pre->element = temp;
                }
                cur = cur->next;
                pre = pre->next;
            }
        }
    }
    class myiterator
    {
    public:
        friend class chain;
        struct chainNode* node;
        myiterator(chainNode* theNode = nullptr)
        {
            node = theNode;
        }
        int& operator *()
        {
            return node->element;
        }
        chainNode* operator ->()
        {
            return node->next;
        }
        myiterator& operator++()
        {
            node = node->next;
            return *this;
        }
        myiterator operator++(int)
        {
            myiterator old = *this;
            node = node->next;
            return old;
        }
        bool operator !=(myiterator temp)
        {
            return node != temp.node;
        }
    };
    myiterator begin()
    {
        return myiterator(head);
    }
    myiterator end1()
    {
        return myiterator(nullptr);
    }
    
};

int main()
{
    int N, M;
    cin >> N >> M;
    chain mychain(N);
    chain mychain2(M);
    chain mychain3(N + M);
    for (chain::myiterator it = mychain.begin(); it != mychain.end1(); it++)
    {
        int a;
        cin >> a;
        it.node->element = a;
    }
    for (chain::myiterator it = mychain2.begin(); it != mychain2.end1(); it++)
    {
        int a;
        cin >> a;
        it.node->element = a;
    }
    mychain.bubbleSort();
    mychain2.bubbleSort();
    chain::myiterator chain1 = mychain.begin();
    chain::myiterator chain2 = mychain2.begin();
    chain::myiterator chain3 = mychain3.begin();
    while (chain1.node != nullptr && chain2 != nullptr)
    {
        if (chain1.node->element > chain2.node->element)
        {
            chain3.node->element = chain2.node->element;
            chain2++;
            chain3++;
        }
        else
        {
            chain3.node->element = chain1.node->element;
            chain1++;
            chain3++;
        }
    }
    if (chain1.node == nullptr)
    {
        while (chain3.node != nullptr && chain2.node != nullptr)
        {
            chain3.node->element = chain2.node->element;
            chain2++;
            chain3++;
        }
    }
    else
    {
        while (chain3.node != nullptr && chain1.node != nullptr)
        {
            chain3.node->element = chain1.node->element;
            chain1++;
            chain3++;
        }
    }
    mychain.elementxor();
    mychain2.elementxor();
    mychain3.elementxor();
}