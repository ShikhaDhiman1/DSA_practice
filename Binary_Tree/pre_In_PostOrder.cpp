#include <iostream>
#include <vector>
#include <stack>
// #include "binaryTree.h"
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> allTraversals(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    vector<int> preOrder, inOrder, postOrder;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left) st.push({it.first->left, 1});
        }
        else if(it.second == 2){
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right) st.push({it.first->right, 1});
        }
        else if(it.second == 3){
            postOrder.push_back(it.first->data);
        }
    }
    ans.push_back(preOrder);
    ans.push_back(inOrder);
    ans.push_back(postOrder);

    return ans;
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

    vector<vector<int>> traversals = allTraversals(root);

    for(auto vec : traversals){
        cout<<"[";
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
    cout<<"\n";

    // vector<int> nums = {3,9,20,NULL,NULL,15,7};
    // Node* root = buildTree(nums);

    // vector<vector<int>> traversals = allTraversals(root);

    // for(auto vec : traversals){
    //     cout<<"[";
    //     for(auto x : vec){
    //         cout<<x<<" ";
    //     }
    //     cout<<"]\n";
    // }
    // cout<<"\n";

    return 0;
}