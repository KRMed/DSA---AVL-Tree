#include "avl_tree.hpp"
#include "messages.hpp"

void AVLTree::insert(std::string name, int id) {
    root = insert(root, name, id);
}

AVLTree::Node* AVLTree::insert(Node* chum, std::string name, int id) {
    if (!chum) {
        std::cout << msg::SUCCESS << std::endl;
        return new Node(name, id);
    }

    if (id < chum->id) {
        chum->leftChild = insert(chum->leftChild, name, id);
    }
    else if (id > chum->id) {
        chum->rightChild = insert(chum->rightChild, name, id);
    } else { 
        std::cout << msg::UNSUCCESS << std::endl;
        return chum;
    }

    //nodeUpdate(chum);
    //return nodeBalance(chum);
    //for now
    return chum;
}

void AVLTree::printInOrder() {
    std::vector<std::string> names;
    printInOrder(root, names);
    for (int i = 0; i < names.size(); i++) {
        std::cout << names[i];

        if (i < names.size() - 1) {
            std::cout << ", ";
        }
        
    }
}

void AVLTree::printInOrder(Node* chum, std::vector<std::string>& names) {
    if (!chum) return;

    printInOrder(chum->leftChild, names);
    names.push_back(chum->name);
    printInOrder(chum->rightChild, names);
    
    return;
}

void AVLTree::printPreOrder() {
    
}

