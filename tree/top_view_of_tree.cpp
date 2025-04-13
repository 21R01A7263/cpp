#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{

    vector<int> result;
private:
    void traverseLeft(Node *node)
    {
        if (!node || !node->left)
        {
            return;
        }
        traverseLeft(node->left);
        result.push_back(node->left->data);
    }

    void traverseRight(Node *node)
    {
        Node *curr = node;
        while (curr != nullptr)
        {
            result.push_back(curr->data);
            curr = curr->right;
        }
    }

public:
    vector<int> getresult(Node *root)
    {
        
        if (!root)
        {
            return result;
        }
        traverseLeft(root);
        result.push_back(root->data);
        if (root->right)
        {
            traverseRight(root->right);
        }
        return result;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.getresult(root);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
