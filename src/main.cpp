#include <iostream>
#include "avl_tree.cpp"

using namespace std;

int main(){
	AVLTree tree;
	tree.insert("Alice", 30);
	tree.insert("Bob", 20);
	tree.insert("Charlie", 40);
	tree.printInOrder();
}
