#include <iostream>
#include "avl_tree.cpp"

using namespace std;

int main(){
	AVLTree tree;
	tree.insert("Alice", 30);
	tree.insert("Bob", 20);
	tree.insert("Charlie", 40);
	tree.insert("Diana", 10);
	tree.insert("Eve", 25);
	tree.insert("Frank", 35);
	tree.insert("Grace", 50);
	tree.insert("Heidi", 5);
	tree.insert("Ivan", 70);
	tree.insert("Ivan", 70);
	tree.printInOrder();
	tree.printPreOrder();
	tree.printPostOrder();
	tree.printLevelCount();
	return 0;
}
