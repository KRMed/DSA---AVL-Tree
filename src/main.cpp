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
	tree.insert("Ivan", 90);
	tree.printInOrder();
	tree.printPreOrder();
	tree.printPostOrder();
	tree.printLevelCount();
	tree.search(25);
	tree.search("Eve");
	tree.search("Ivan");
	tree.remove(20);
	tree.remove(30);
	tree.remove(40);
	tree.printInOrder();
	return 0;
}
