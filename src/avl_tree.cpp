#pragma once
#include <iostream>
#include <string>
#include "avl_tree.hpp"
#include "messages.cpp"

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
        std::cout << msg::UNNSUCCESS << std::endl;
        return;
    }

    //nodeUpdate(chum);
    //return nodeBalance(chum);
}

