#include<iostream>
using namespace std;
class queue
{
    private:
        int * element;
        int  queueFront;
        int  queueBack;
        int size;
        int length;
    public:
        queue(int l)
        {
            length =l;
            size = 0;
            element = new int[length];
            queueFront = queueBack = 0;
        }
        ~queue()
        {
            delete[] element;
        }
        void push(const int & theElement)
        {
            queueBack = (queueBack+1) % length;
            element[queueBack]=theElement;
            size++;
        }
        void pop()
        {
            queueFront = (queueFront+1)%length;
            size--; 


              
        }
        bool isEmpty()
        {
            return getsize() == 0;
        }
        int getfront()
        {
            return element[queueFront+1];
        }
        int getsize()
        {
            return size;
        }
};
int main()
{
    int n;
    cin >> n;
    queue myqueue(n);
    for(int i =1;i<=n;i++)
    {
        myqueue.push(i);
    }
    while(myqueue.getsize() >= 2)
    {
        myqueue.pop();
        int theElement = myqueue.getfront();
        myqueue.pop();
        myqueue.push(theElement);
    }
    cout << myqueue.getfront();
}