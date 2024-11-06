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
    chain(int initialCapacity)
    {
        if (initialCapacity > 0)
        {
            head = new chainNode;
            chainNode* p = head;
            for (int i = 1; i < initialCapacity; i++)
            {
                p->next = new chainNode;
                p =  p -> next;
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
        arrofresult[numofarr]=-1;
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
        arrofresult[numofarr] = result;
        numofarr++;
    }

    class myiterator
    {
    public:
        friend class chain;
        chainNode* node;
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
    int N, Q;
    cin >> N >> Q;
    chain mychain(N);
    int index = 0;
    for (chain::myiterator it = mychain.begin(); it != mychain.end1(); it++)
    {
        int a;
        cin >> a;
        it.node->element = a;
    }
    for (int i = 0; i < Q; i++)
    {
        int method;
        cin >> method;
        switch (method)
        {
        case 1:
        {
            int idx, val;
            cin >> idx >> val;
            mychain.insert(idx, val);
            break;
        }
        case 2:
        {
            int val;
            cin >> val;
            mychain.erase(val);
            break;
        }
        case 3:
            mychain.inversion();
            break;
        case 4:
            int val;
            cin >> val;
            mychain.findidx(val);
            break;
        case 5:
            mychain.elementxor();
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < mychain.numofarr; i++)
    {
        cout << mychain.arrofresult[i] << endl;
    }
}