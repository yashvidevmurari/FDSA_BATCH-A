#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {

    if (root == NULL)
     {
        return new Node(value);
    }

    if (value < root->data) 
    {
        root->left = insert(root->left, value);
    }

    else if (value > root->data) 
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root) 
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    int codes[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, codes[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}