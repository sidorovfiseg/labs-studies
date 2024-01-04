//
// Created by egor on 02.12.23.
//
//

#include <iostream>
#include "string"
#include <queue>
#include <sstream>
#include <map>


struct Node {
    int data;
    int rightParentCount;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    void destroyTree(Node * node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node* insertLeaf(int data) {
        Node* node = new Node();
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
        node->rightParentCount = 0;
        return  node;

    }

    Node* insert(Node* node, int data) {
        if (node == nullptr)
            return insertLeaf(data);
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->rightParentCount++;
            node->right = insert(node->right, data);
        }
        return node;
    }

    void bst(Node* node, int level, std::map<int, int>& rights) {
        if (node == nullptr) {
            return;
        }
        if (rights.find(level) == rights.end()) {
            rights[level] = node->data;
        }
        bst(node->right, level + 1, rights);
        bst(node->left, level + 1, rights);
    }

public:
    void printRight() {
        std::map<int, int> rights;
        bst(root, 0, rights);
        for(auto it = rights.begin(); it != rights.end(); it++) {
            std::cout << it->second << " ";
        }
    }

    BST() {
        root = nullptr;

    }

    ~BST() {
        destroyTree(root);
    }


    void insert(int data) {
        if (root == nullptr) {
            root = insertLeaf(data);
            return;
        }
        insert(root, data);
    }
};


int main() {
    BST* bst = new BST();
    int n;
    std::cin >> n;
    int data;
    for(int i = 0; i < n; i++) {
        std::cin >> data;
        bst->insert(data);
    }

    bst->printRight();

    delete bst;
    return 0;
}

