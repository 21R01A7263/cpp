#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isIdentical(Node *root1, Node *root2){
    if(root1 == nullptr || root2 == nullptr){
        return root1 == root2;
    }
    return (root1->data == root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}