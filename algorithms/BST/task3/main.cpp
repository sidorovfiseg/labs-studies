#include <iostream>

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

    Node* search(Node* node, int data) {
        if (node == nullptr)
            return node;
        if (data < node->data) {
            return search(node->left, data);
        } else if (data > node->data) {
            node->rightParentCount--;
            return search(node->right, data);
        } else
            return node;
    }

    bool checkIfExists(Node* node, int data) {
        if (node == nullptr)
            return true;
        if (data < node->data) {
            return checkIfExists(node->left, data);
        } else if (data > node->data) {
            return checkIfExists(node->right, data);
        } else {
            return false;
        }
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
    }

    void deleteFirstCase(Node* node) {
        if (node->left) {
            Node* temp = node->left;
            node->data = temp->data;
            node->rightParentCount = temp->rightParentCount;
            node->left = temp->left;
            node->right = temp->right;
            delete temp;
        } else {
            Node* temp = node->right;
            node->data = temp->data;
            node->rightParentCount = temp->rightParentCount;
            node->left = temp->left;
            node->right = temp->right;
            delete temp;
        }
    }

    void deleteSecondCase(Node* node) {
        Node* inOrderNode = node->right;
        Node* prev = inOrderNode;
        node->rightParentCount = inOrderNode->rightParentCount;
        while(inOrderNode->left) {
            prev = inOrderNode;
            inOrderNode = inOrderNode->left;
        }
        node->data = inOrderNode->data;
        if (prev == inOrderNode) {
            node->right = inOrderNode->right;
            delete inOrderNode;
        } else {
            prev->left = nullptr;
            delete inOrderNode;
        }
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

    void findKMax(Node* node, int k) {
        if (node == nullptr)
            return;

        if (k - 1 == node->rightParentCount) {
            std::cout << node->data << std::endl;
            return;
        } else if (k - 1 < node->rightParentCount) {
            findKMax(node->right, k);
        } else {
            findKMax(node->left, k - node->rightParentCount - 1);
        }

    }

public:
    void printKMax(int k) {
        if (k > 0)
            findKMax(root, k);
    }

    BST() {
        root = nullptr;

    }

    ~BST() {
        destroyTree(root);
    }

    void deleteNode(int data) {
        if (!checkIfExists(root, data)) {
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
    }

    void insert(int data) {
        if (root == nullptr) {
            root = insertLeaf(data);
            return;
        }
        if (checkIfExists(root, data)) {
            insert(root, data);
        }

    }
};

void executeCommand(int command, int & data,  BST* bst) {
    if (command == 1) {
        bst->insert(data);
    } else if (command == -1) {
        bst->deleteNode(data);
    } else if (command == 0) {
        bst->printKMax(data);
    }
}


int main() {

    BST* bst = new BST();
    int n;
    std::cin >> n;
    int command;
    int data;
    for (int i = 0; i < n; i++) {
        std::cin >> command >> data;
        executeCommand(command, data, bst);
    }

    delete bst;
    return 0;

}

