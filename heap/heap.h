#include <vector>

struct Node {
    int val;
    Node* father;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// min heap
// root smallest
class Heap {
private:
    Node* root;
    Node* tail;
    void update(); // update when push
    void heapify(); // update when pop
public:
    Heap(std::vector<int> ints);
    ~Heap();
    void push(int val); // insert a new value
    int top(); // get the heap root
    int pop();
};

