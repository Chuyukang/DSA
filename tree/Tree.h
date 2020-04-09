#include<functional>
using namespace std;
template<typename T>
class Tree
{
private:
    T data;
    Tree<T> *left,*right;
public:
    Tree();
    Tree(const T& _data);
    ~Tree();
    T getData();
    Tree<T>* getLeft();
    Tree<T>* getRight();
    void setLeft(Tree<T>* _left);
    void setRight(Tree<T>* _left);
};
template<typename T>
Tree<T>::Tree()
{
    left = right = nullptr;
}
template<typename T>
Tree<T>::Tree(const T& _data)
{
    data = _data;//类型T应重载复制运算符
    left = right = nullptr;
}
template<typename T>
Tree<T>::~Tree()
{
    delete left;
    delete right;
}

template<typename T>
T Tree<T>::getData()
{ return data; }

template<typename T>
Tree<T>* Tree<T>::getLeft()
{ return left; }
template<typename T>
Tree<T>* Tree<T>::getRight()
{ return right; }
template<typename T>
void Tree<T>::setLeft(Tree<T>* _left)
{ left = _left; }

template<typename T>
void Tree<T>::setRight(Tree<T>* _right)
{ right = _right; }
