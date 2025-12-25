#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
// this is not efficient for inserting in trees
//  this is hardcoded
//  **efficiently insertion is only done by level order traversal ***(BFS)***
Node *insert()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    return root;
}

// inorder : left root right
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder traversal : root left right
void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// postorder : left right root
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = insert();
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "preorder: ";

    preorder(root);
    cout << endl;
    cout << "postorder: ";
    postorder(root);
    cout << endl;
    return 0;
}
