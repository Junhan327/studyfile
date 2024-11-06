#include<iostream>
using namespace std;
template<class T>
class stack
{
private:
    int size;
    int length;
    T* element;
public:
    stack(int l)
    {
        size = 0;
        length = l;
        element = new T[length];
    }
    ~stack()
    {
        delete[] element;
    }
    bool empty()
    {
        return size == 0;
    }
    int Size()
    {
        return size;
    }
    void push(T x)
    {
        element[size] = x;
        size++;
    }
    T pop()
    {
        size--;
        return element[size];
    }
    T top()
    {
        return element[size-1];
    }
};
template<class T>
void compute(stack<T>& number, char op) {
    double b = number.pop();
    double a = number.pop();
    switch (op)
    {
        case '+': number.push(a + b); break;
        case '-': number.push(a - b); break;
        case '*': number.push(a * b); break;
        case '/': number.push(a / b); break;
    }
}

int precedence(char op)
{
    switch(op)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '(': return 0;
        case ')': return 0;
    }   
}


int main()
{
    int num;
    cin >> num;
    stack<double> number(2000);
    stack<char> op(2000);
    double* result = new double[num];
    for (int i = 0; i < num; i++)
    {
        char* a = new char[2000];
        cin >> a;
        for (int i = 0; a[i] != '\0'; i++)
        {
            if (a[i] >= 48)
            {
                number.push(a[i] - '0');
            }
            else if (a[i] == '(')
            {
                op.push(a[i]);
            }
            else if (a[i] == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    compute(number, op.pop());
                }
                op.pop();
            }
            else
            {
                while (!op.empty() && precedence(op.top()) >= precedence(a[i]))   //这样就能把乘法和除法直接运算掉
                {
                    compute(number, op.pop()); // 执行所有优先级高或相等的运算
                }
                op.push(a[i]);
            }
        }
        while (!op.empty())
        {
            compute(number, op.pop());
        }
        result[i] = number.pop();
        delete[] a;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%.2f\n", result[i]);
    }
    delete[] result;
}