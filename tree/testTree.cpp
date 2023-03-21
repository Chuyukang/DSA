#define TEST

#include <iostream>
#include <memory>
#include "Tree.h"


using namespace std;

void preOrder(const Tree<int>* root) {
	if(root==nullptr) {
		return ;
	}
	cout << root->getData() << '\n';

	preOrder(root->getLeft());
	preOrder(root->getRight());
}

int main()
{
	unique_ptr<Tree<int>> root = make_unique<Tree<int>>(1);
	root->setLeft(make_unique<Tree<int>>(0));
	root->setRight(make_unique<Tree<int>>(2));

	
	preOrder(root.get());
	
	return 0;
}

