#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "ds/Tree.h"

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
	auto root = make_unique<Tree<int>>(1);
	root->setLeft(make_unique<Tree<int>>(0));
	root->setRight(make_unique<Tree<int>>(2));

	preOrder(root.get());
	
	return 0;
}

