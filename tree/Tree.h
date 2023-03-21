#include<functional>
#include<memory>

using namespace std;

template<typename T>
class Tree
{
private:
    T data;
    unique_ptr<Tree<T>> left,right;
public:
    Tree();
    Tree(const T& _data);
    ~Tree();
    T getData() const ;
    const Tree<T>* getLeft() const ;
    const Tree<T>* getRight() const ;
    void setLeft(unique_ptr<Tree<T>> _left);
    void setRight(unique_ptr<Tree<T>> _right);
};
template<typename T>
Tree<T>::Tree()
{
    left = nullptr;
    right = nullptr;
}
template<typename T>
Tree<T>::Tree(const T& _data)
{
    data = _data;//类型T应重载复制运算符
    left = nullptr;
    right = nullptr;
}
template<typename T>
Tree<T>::~Tree()
{ }

template<typename T>
T Tree<T>::getData() const
{ return data; }

template<typename T>
const Tree<T>* Tree<T>::getLeft() const
{ return left.get(); }
template<typename T>
const Tree<T>* Tree<T>::getRight() const
{ return right.get(); }
template<typename T>
void Tree<T>::setLeft(unique_ptr<Tree<T>> _left)
{ left = std::move(_left); }

template<typename T>
void Tree<T>::setRight(unique_ptr<Tree<T>> _right)
{ right = std::move(_right); }

