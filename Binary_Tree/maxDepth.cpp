#include <iostream>
#include "binaryTree.h"
using namespace std;

int maxDepth(Node* root){
    if(root == NULL) return 0;
        
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    
    return 1 + max(l, r);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    cout<<maxDepth(root)<<"\n";
    return 0;
}