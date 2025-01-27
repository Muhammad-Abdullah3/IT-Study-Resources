#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void createTree1() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
    }

    void createTree2() {
        root = new Node(10);
        root->left = new Node(20);
        root->right = new Node(30);
        root->left->left = new Node(40);
        root->left->right = new Node(50);
        root->right->left = new Node(60);
        root->right->right = new Node(70);
    }

    void inOrderTraversal(Node* node, vector<int>& result) {
        if (node == nullptr) return;

        inOrderTraversal(node->left, result);
        result.push_back(node->data);
        inOrderTraversal(node->right, result);
    }

    void displayInOrder() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        vector<int> result;
        inOrderTraversal(root, result);

        cout << "Inorder Traversal: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    void preOrderTraversal(Node* node, vector<int>& result) {
        if (node == nullptr) return;

        result.push_back(node->data);
        preOrderTraversal(node->left, result);
        preOrderTraversal(node->right, result);
    }

    void displayPreOrder() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        vector<int> result;
        preOrderTraversal(root, result);

        cout << "Preorder Traversal: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    void postOrderTraversal(Node* node, vector<int>& result) {
        if (node == nullptr) return;

        postOrderTraversal(node->left, result);
        postOrderTraversal(node->right, result);
        result.push_back(node->data);
    }

    void displayPostOrder() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        vector<int> result;
        postOrderTraversal(root, result);

        cout << "Postorder Traversal: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree1, tree2;

    tree1.createTree1();
    tree1.displayInOrder();
    tree2.createTree2();
    tree2.displayPreOrder();
    tree2.displayPostOrder();

    return 0;
}
