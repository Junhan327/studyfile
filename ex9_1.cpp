#include<iostream>
using namespace std;

template<class T>
class treeNode:
{
    private:
    T value;
    treeNode* leftChild;
    treeNode* rightChild;
    public:
    friend class binaryTree;
    treeNode(T value_):value(value_){}
    T getvalue()
    {
        return value;
    }
};
template<class T>
class binaryTree
{
    private:
    treeNode<T>* root;
    treeNode<T>** nodeList;
    int nodeNum;
    public:
    binaryTree(int num)
    {
        nodeNum = num;
        nodeList = new treeNode<T>*[num+1];
        for(int i=1;i<=num;i++)
        {
            nodeList[i]=nullptr;
        }
        root = new treeNode<T>(1);
        nodeList[1] = root;
        int current_node_num = 1;
        for(int i=1;i<=num;i++)
        {
            treeNode<T> * temp = nodeList[i];
            int a,b;                      //在这里怎么使用模版
            if(a != -1)
            {
                temp->leftChild = new treeNode<T>(a);
                current_node_num++;
                nodeList[current_node_num]=temp->leftChild;
            }
            if(b != -1)
            {
                temp->rightChild = new treeNode<T>(b);
                current_node_num++;
                nodeList[current_node_num]= temp->rightChild;
            }
        }
    }
    treeNode<T>* getroot()
    {
        return root;
    }
    void preOrder(treeNode<T> *node)
    {
        cout<< node->getvalue()<<' ';
        if(node->leftChild)
        {
            return preOrder(node->leftChild);
        }
        if(node->rightChild)
        {
            return preOrder(node -> rightChild);
        }
    }
};
int main()
{
    int n;
    cin >> n;
    binaryTree<int> tree(n);
    tree.preOrder(tree.getroot());
    return 0;
}