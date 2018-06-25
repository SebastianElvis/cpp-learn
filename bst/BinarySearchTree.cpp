#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void initNode(Node* &n, int x) { // pass the reference of a pointer
    n = new Node{};
    n->val = x;
    n->left = nullptr;
    n->right = nullptr;
}

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::BinarySearchTree(int x) 
{
    initNode(root, x);
}

bool BinarySearchTree::insertNode(int x)
{
    if (root == nullptr) {
        initNode(root, x);
    } else if (root->val == x) {
        return false;
    } else {
        if (x > root->val) {
            if (root->right == nullptr) {
                initNode(root->right, x);
            } else {
                Node *tmp = root;
                root = root->right;
                insertNode(x);
                root = tmp;
            }
        } else if (x < root->val) {
            if (root->left == nullptr) {
                initNode(root->left, x);
            } else {
                Node *tmp = root;
                root = root->left;
                insertNode(x);
                root = tmp;
            }
        }
    }
    return true;
}

bool BinarySearchTree::deleteNode(int x)
{

}

bool BinarySearchTree::searchNode(int x)
{
    bool flag = false;
    if (root == nullptr) flag = false;
    else if (x == root->val) flag = true;
    else if (x > root->val) {
        Node *tmp = root;
        root = root->right;
        flag = searchNode(x);
        root = tmp;
    } else if (x < root->val) {
        Node *tmp = root;
        root = root->left;
        flag = searchNode(x);
        root = tmp;
    }
    return flag;
}

void BinarySearchTree::printTree()
{

}

int main() {
    BinarySearchTree bst;
    bst.insertNode(1);
    bst.insertNode(2);
    bst.insertNode(3);
    for(int i=0;i<6;i++) {
        cout << bst.searchNode(i) << endl;
    }
}