#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildTree(node* &root){
    int val;
    cout<<"Enter the data: ";
    cin>>val;

    node* n = new node(val);

    if(val == -1){
        return NULL;
    }
    if(root->left == NULL){
        // cout<<"Enter the left child of "<<val<<" : ";
        // root -> left = buildTree(root->left);
        root->left = n;
    }
    else{
        // cout<<"Enter the right child of "<<val<<" : ";
        // root -> right = buildTree(root->right);
        root->right = n;
    }
    // root = n;
    buildTree(n);
    return n;
}

void display(node* &root){
    node* temp = root;
    if(temp->left == NULL || temp->right == NULL) return;
    cout<<" "<<temp->data<<endl;
    cout<<"/   \\"<<endl;
    cout<<temp->left->data<<"  "<<temp->right->data<<endl;
    display(temp->left);
    display(temp->right);
    // return;
}

int main(){
    node* n;
    buildTree(n);

    display(n);

    return 0;
}