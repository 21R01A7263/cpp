#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int dfsHeight(Node *root) {
    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1) return -1;    
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1) return -1;    
    return max(leftHeight, rightHeight) + 1;
}

bool balanced(Node *root){
    return dfsHeight(root) != -1;
}

int main(){
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    
    if (balanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    
    return 0;
}