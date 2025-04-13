#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int maxPathDown(Node *node, int &maxi){
    if (node == nullptr) {
        return 0;
    }

    int left_sum = max(0, maxPathDown(node->left, maxi));
    int right_sum = max(0, maxPathDown(node->right, maxi));

    maxi = max(maxi, left_sum + right_sum + node->data);
    return max(left_sum, right_sum) + node->data;
}


int maxPathSum(Node *root){
    
    if(root == nullptr){
        return 0; 
    }
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main(){
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};

    cout << "Maximum path sum: " << maxPathSum(root) << endl; 

    return 0;
}