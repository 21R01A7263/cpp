#include<iostream>
#include<vector>
#include<queue>
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

vector<vector<int>> levelOrder(Node *root){
    vector<vector<int>> result;
    if(root==nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node *current = q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
            level.push_back(current->data);
        }
        result.push_back(level);
    }
    return result;    
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

    vector<vector<int>> result = levelOrder(root);
    for(auto level : result){
        for(int it: level){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}