#include "heap.h"
#include <iostream>
#include <vector>

// not working yet...

// update when push
// node mgmt (root/tail) is by push()
void Heap::update() 
{
    Node* ref = tail;
    while(ref->father != nullptr 
    && ref->val < ref->father->val) {
        // exchange value
        int tmp = ref->val;
        ref->val = ref->father->val;
        ref->father->val = tmp;
        // change ref
        ref = ref->father;
    }
}

// update when pop
// node mgmt (root/tail) is by pop()
void Heap::heapify() 
{
    Node* ref = root;
    while( (ref->left != nullptr || ref->right != nullptr)
    && (ref->val > ref->left->val || ref->val > ref->right->val) ) {
        if( ref->right == nullptr || ref->left->val < ref->right->val ) {
            int tmp = ref->val;
            ref->val = ref->left->val;
            ref->left->val = tmp;
            ref = ref->left;
        } else {
            int tmp = ref->val;
            ref->val = ref->right->val;
            ref->right->val = tmp;
            ref = ref->right;
        }
    }
}

int Heap::pop()
{
    if(root == tail) {
        std::cout << "Heap empty!!!!" << std::endl;
        return -99999;
    }

    int popped_value = root->val;

    root->val = tail->val;
    
    // find new tail
    Node* oldtail = tail;
    if(tail->father->right == oldtail) {
        tail = tail->father->left;
    } else {
        // complex
        while( tail != root
        && tail->father->left == tail) {
            tail = tail->father;
        }
        tail = tail->father->left;
        while(tail->right != nullptr) {
            tail = tail->right;
        }
    }
    delete oldtail;

    heapify();

    return popped_value;
}

void Heap::push(int val)
{
    Node* node = new Node(val);
    // std::cout << "In push --- " << "node val = " << node->val << std::endl;
    if (root == nullptr) {
        root = node;
    } else if (root == tail) {
        root->left = node;
        node->father = root;
    } else if (tail->father->right == tail) { // right leaf
        // complex
        while(tail->father != nullptr && tail->father->right == tail) {
            tail = tail->father;

        }
        if(tail == root) {
            while(tail->left != nullptr) {
                tail = tail->left;
            }
        } else {
            tail = tail->father->right;
            while(tail->left != nullptr) {
                tail = tail->left;
            }
        }
        tail->left = node;
        node->father = tail;
    } else {
        tail->father->right = node;
        node->father = tail->father;
    }

    tail = node;

    update();
}

int Heap::top()
{
    return root->val;
}

Heap::Heap(std::vector<int> ints)
{
    root = nullptr;
    tail = nullptr;
    for(auto it=ints.begin();it!=ints.end();it++) {
        int val = *it;
        std:: cout << val << " ";
        push(val);
    }
}

Heap::~Heap()
{

}

void heapsort(std::vector<int> &ints)
{
    Heap h(ints);
    ints.clear();
    while(true) {
        int popped_value = h.pop();
        if (popped_value != -99999) {
            ints.push_back(popped_value);
        } else {
            break;
        }
    }
}





int main() {
    std::vector<int> x = {1,2,5,8,4};
    heapsort(x);
    
    for(auto it=x.begin();it!=x.end();it++) {
        std::cout << *it << " " << std::endl;
    }
}