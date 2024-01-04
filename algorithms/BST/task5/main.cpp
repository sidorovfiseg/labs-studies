//
// Created by egor on 05.12.23.
//

#include "iostream"
#include "string"
#include "queue"

using namespace std;

struct Node {
    string data;
    int points;
    queue<int> students;
    Node* left;
    Node* right;
};


class BST {
private:
    Node* root;

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node* insertLeaf(const string& data, int studentNo) {
        Node* node = new Node();
        node->data = data;
        node->students.push(studentNo);
        node->points = 3;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    Node* insert(Node* node, const string& data, int studentNo) {
        if (node == nullptr)
            return insertLeaf(data, studentNo);

        if (data.compare(node->data) < 0) {
            node->left = insert(node->left, data, studentNo);
        } else if (data.compare(node->data) > 0) {
            node->right = insert(node->right, data, studentNo);
        } else if (data == node->data){
            if (node->points == 3)  {
                node->points = 1;
                node->students.push(studentNo);
            }
            else {
                node->points = 0;
            }
            return node;
        }
        return node;
    }

    int countMark(Node* node, int studentNo) {
        int k = 0;
        if (node != nullptr) {
            if (node->points == 3 && studentNo == node->students.front()) {
                k += 3;
                node->students.pop();
            }
            else if (node->points == 1 && studentNo == node->students.front()) {
                k += 1;
                node->students.pop();
            }
            k += countMark(node->left, studentNo);
            k += countMark(node->right, studentNo);
        }
        return k;
    }

public:
    void insert(const string& data, int studentNo) {
        if (root == nullptr) {
            root = insertLeaf(data, studentNo);
            return;
        }
        insert(root, data, studentNo);
    }

    int countMark(int studentNo) {
        return countMark(root, studentNo);
    }

};


int main() {
    BST* bst = new BST();
    int n;
    std::cin >> n;
    string data;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> data;
            bst->insert(data, i);
        }
    }

    for (int i = 0; i < 3; i++) {
        std::cout << bst->countMark(i) << " ";
    }

    return 0;
}