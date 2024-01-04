//
// Created by egor on 01.12.23.
//
#include <iostream>
#include "string"
#include <queue>
#include <sstream>


struct Node {
    int data;
    Node* left;
    Node* right;
};


class BST {
private:
    Node* root;
    std::queue<std::string> queue;

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
        return node;

    }

    Node* search(Node* node, int data) {
        if (node == nullptr)
            return node;
        if (data < node->data) {
            return search(node->left, data);
        } else if (data > node->data) {
            return search(node->right, data);
        } else
            return node;
    }

    void deleteLeaf(int data) {
        if (root->data == data) {
            delete root;
            root = nullptr;
            return;
        }
        Node* toDelete = root;
        Node* prev = toDelete;
        while (toDelete->data != data) {
            if (toDelete->data > data) {
                prev = toDelete;
                toDelete = toDelete->left;
            } else {
                prev = toDelete;
                toDelete = toDelete->right;
            }
        }

        if (prev->data < toDelete->data) {
            prev->right = nullptr;
        } else {
            prev->left = nullptr;
        }
        delete toDelete;
        toDelete = nullptr;
    }

    void deleteFirstCase(Node* node) {
        if (node->left) {
            Node* temp = node->left;
            node->data = node->left->data;
            node->left = temp->left;
            node->right = temp->right;
            delete temp;
            temp = nullptr;
        } else {
            Node* temp = node->right;
            node->data = node->right->data;
            node->right = temp->right;
            node->left = temp->left;
            delete temp;
            temp = nullptr;
        }
    }

    void deleteSecondCase(Node* node) {
        Node* inOrderNode = node->right;
        Node* prev = inOrderNode;
        while(inOrderNode->left) {
            prev = inOrderNode;
            inOrderNode = inOrderNode->left;
        }
        node->data = inOrderNode->data;
        if (prev == inOrderNode) {
            node->right = inOrderNode->right;
            delete inOrderNode;
            inOrderNode = nullptr;
        } else {
            delete inOrderNode;
            prev->left = nullptr;
        }
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr)
            return insertLeaf(data);

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

public:

    void printQueue() {
        while (!queue.empty()) {
            std::cout << queue.front() << std::endl;
            queue.pop();
        }

    }

    void exists(int data) {
        if (search(root, data)) {
            queue.emplace("true");
        } else {
            queue.emplace("false");
        }
    }

    BST() {
        root = nullptr;
    }

    ~BST() {
        destroyTree(root);
    }

    void deleteNode(int data) {

        Node* node = search(root, data);

        if (node) {
            if (node->left == nullptr && node->right == nullptr) {
                deleteLeaf(data);
            } else if(node->left != nullptr && node->right != nullptr) {
                deleteSecondCase(node);
            }  else {
                deleteFirstCase(node);
            }
        }

    }

    void next(int data) {
        if (root == nullptr) {
            queue.emplace("none");
            return;
        }
        Node* node = root;
        int min = INT32_MAX;
        while (node != nullptr) {
            if (node->data <= data) {
                node = node->right;
            } else {
                if (node->data > data) {
                    min = node->data;
                }
                node = node->left;
            }
        }
        min == INT32_MAX ? queue.emplace("none") : queue.emplace(std::to_string(min));
    }

    void prev(int data) {

        if (root == nullptr) {
            queue.emplace("none");
            return;
        }

        Node* node = root;
        int max = INT32_MIN;
        while (node != nullptr) {
            if (node->data >= data) {
                node = node->left;
            } else {
                if (node->data < data) {
                    max = node->data;
                }
                node = node->right;
            }
        }
        max == INT32_MIN ? queue.emplace("none") : queue.emplace(std::to_string(max));

    }

    void insert(int data) {
        if (root == nullptr) {
            root = insertLeaf(data);
            return;
        }
        insert(root, data);
    }
};

void executeCommand(const std::string& command, int data,  BST* bst) {
    if (command == "insert") {
        bst->insert(data);
    } else if (command == "delete") {
        bst->deleteNode(data);
    } else if (command == "exists") {
        bst->exists(data);
    } else if (command == "next") {
        bst->next(data);
    } else if (command == "prev") {
        bst->prev(data);
    } else
        return;
}


int main() {
    BST* bst = new BST();
    std::string input;
    std::string command;
    int value;
    while (std::getline(std::cin, input) && !input.empty()) {

        std::istringstream iss(input);
        iss >> command >> value;
        executeCommand(command, value, bst);

    }

    bst->printQueue();
    delete bst;
    return 0;
}
