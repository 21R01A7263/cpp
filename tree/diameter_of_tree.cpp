#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node *root, int &diameter){
    if(root == nullptr){
        return 0;
    }

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfTree(Node *root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main(){
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};

    cout << "Diameter of the tree: " << diameterOfTree(root) << endl;

    return 0;
}