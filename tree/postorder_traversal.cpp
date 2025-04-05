#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> postOrder(Node *root){
    vector<int> arr;
    if(root == nullptr){
        return arr;
    }

    vector<int> left = postOrder(root->left);
    arr.insert(arr.end(), left.begin(), left.end());
    vector<int> right = postOrder(root->right);
    arr.insert(arr.end(), right.begin(), right.end());
    arr.push_back(root->data);

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

    vector<int> result = postOrder(root);
    for(int it: result){
        cout<<it<<" ";
    }
    cout<<endl;
}