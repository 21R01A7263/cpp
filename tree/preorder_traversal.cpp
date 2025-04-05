#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left=nullptr;
        right=nullptr;
    }
};

vector<int> preOrder(Node *root){
    vector<int> arr;
    if(root == nullptr){
        return arr;
    }
    arr.push_back(root->data);
    vector<int> left = preOrder(root->left);
    vector<int> right = preOrder(root->right);
    arr.insert(arr.end(), left.begin(), left.end());
    arr.insert(arr.end(), right.begin(), right.end());
    return arr;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);

    vector<int> result = preOrder(root);
    for(int it: result){
        cout<<it<<" ";
    }
}