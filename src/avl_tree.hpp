#pragma once
#include <string>

class AVLTree {
    private:
        struct Node {
            std::string name;
            int id;
            int height;
            Node* leftChild;
            Node* rightChild;
            Node(std::string n, int i) : name(n), id(i), height(1), leftChild(nullptr), rightChild(nullptr) {}
        };

        Node* root;

        // Helper functions (others)
        int getHeight(Node* chum) {return chum->height;}
        int getBalance(Node* chum) {return getHeight(chum->leftChild) - getHeight(chum->rightChild);}
        void nodeUpdate(Node* chum) {chum->height = 1 + std::max(getHeight(chum->leftChild), getHeight(chum->rightChild));}

        // Helper functions (insert)
        Node* insert(Node* chum, std::string name, int id);

        // Helper functions (rotations)
        Node* balance(Node* chum); // Checks balance factor and performs rotations
        Node* rightRotate(Node* chum);
        Node* leftRotate(Node* chum);
        Node* leftRightRotate(Node* chum);
        Node* rightLeftRotate(Node* chum);
        
    public: 
        AVLTree() : root(nullptr) {}
        ~AVLTree() { /* do recursive deletion */ } // Destructor to free memory
        void insert(std::string name, int id);
        void remove(int id);
        Node* search(int id); // Travel recursively through the tree
        Node* search(std::string name); // Travel recursively through the tree
        void printInOrder(); 
        void printPreOrder();
        void printPostOrder();
        void printLevelCount();
        void removeInOrderN(int n);
};