struct Node {
    int val;
    Node *left;
    Node *right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(int x);
    bool searchNode(int x);
    bool insertNode(int x);
    bool deleteNode(int x);
    void printTree();

    Node *root;
};