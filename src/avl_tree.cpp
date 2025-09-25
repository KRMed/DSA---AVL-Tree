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

    nodeUpdate(chum);
    return balance(chum);
}

void AVLTree::universalPrint(std::vector<std::string>& names) {
    for (int i = 0; i < names.size(); i++) {
        std::cout << names[i];

        if (i < names.size() - 1) {
            std::cout << ", ";
        }
        
    }
    std::cout << std::endl;
}

void AVLTree::printInOrder() {
    std::vector<std::string> names;
    printInOrder(root, names);
    universalPrint(names);
}

void AVLTree::printInOrder(Node* chum, std::vector<std::string>& names) {
    if (!chum) {
        return;
    }

    printInOrder(chum->leftChild, names);
    names.push_back(chum->name);
    printInOrder(chum->rightChild, names);
    
    return;
}

void AVLTree::printPreOrder() {
    std::vector<std::string> names;
    printPreOrder(root, names);
    universalPrint(names);
}

void AVLTree::printPreOrder(Node* chum, std::vector<std::string>& names) {
    if (!chum) {
        return;
    }

    names.push_back(chum->name);
    printPreOrder(chum->leftChild, names);
    printPreOrder(chum->rightChild, names);

    return;
}

void AVLTree::printPostOrder() {
    std::vector<std::string> names;
    printPostOrder(root, names);
    universalPrint(names);
}

void AVLTree::printPostOrder(Node* chum, std::vector<std::string>& names) {
    if (!chum) {
        return;
    }

    printPostOrder(chum->leftChild, names);
    printPostOrder(chum->rightChild, names);
    names.push_back(chum->name);

    return;
}

int AVLTree::getHeight(Node* chum) {
    if (!chum) return 0;
    return chum->height;
}

void AVLTree::printLevelCount() {
    if (!root) {
        std::cout << 0 << std::endl;
        return;
    }
    
    std::cout << getHeight(root) << std::endl;
}

AVLTree::Node* AVLTree::balance(Node* chum) {
    int balanceFactor = getBalance(chum);

    if (balanceFactor > 1) {    
        if (getBalance(chum->leftChild) >= 0) {
            return rightRotate(chum);
        } else {
            return leftRightRotate(chum);
        }
    } else if (balanceFactor < -1) {
        if (getBalance(chum->rightChild) <= 0) {
            return leftRotate(chum);
        } else {
            return rightLeftRotate(chum);
        }
    }

    return chum;
}

AVLTree::Node* AVLTree::leftRotate(Node* chum) {
    Node* newDad = chum->rightChild;
    Node* temp = newDad->leftChild;

    newDad->leftChild = chum;
    chum->rightChild = temp;

    nodeUpdate(chum);
    nodeUpdate(newDad);

    return newDad;
}

AVLTree::Node* AVLTree::rightRotate(Node* chum) {
    Node* newMom = chum->leftChild;
    Node* temp = newMom->rightChild;

    newMom->rightChild = chum;
    chum->leftChild = temp;

    nodeUpdate(chum);
    nodeUpdate(newMom);

    return newMom;
}

AVLTree::Node* AVLTree::leftRightRotate(Node* chum) {
    chum->leftChild = leftRotate(chum->leftChild);
    return rightRotate(chum);
}

AVLTree::Node* AVLTree::rightLeftRotate(Node* chum) {
    chum->rightChild = rightRotate(chum->rightChild);
    return leftRotate(chum);
}