#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Node* create(vector<int> &nums, int i, int n, Node * root){
//     if(i >= n) return NULL;

//     if(root == NULL) root = new Node(nums[i]);

//     if(2 * i + 1 < n){
//         root->left = create(nums, 2 * i + 1, n, root->left);
//     }
//     if(2 * i + 2 < n){
//         root->right = create(nums, 2 * i + 2, n, root->right);
//     }
//     return root;
// }

// Node* buildTree(vector<int> nums){
//     Node *root = new Node(nums[0]);
//     return create(nums, 1, nums.size(), root);
// }