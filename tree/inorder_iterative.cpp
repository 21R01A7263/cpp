#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

vector<int> inOrder(Node *root){
    vector<int> inorder;
    if(root == nullptr){
        return inorder;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node *current = st.top();
        st.pop();
        if(current->right){
            st.push(current->right);
        }
        inorder.push_back(current->data);
        if(current->left){
            st.push(current->left);
        }
    }
    return inorder;
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

    vector<int> result = inOrder(root);
    for(int it: result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}