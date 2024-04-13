#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

void insert(TreeNode* &root, int val){
    TreeNode* n = new TreeNode(val);
    if(root == NULL){
        root = n;
        return;
    }
    if(val < root->val){
        insert(root->left, val);
        // cout<<root->left->val<<" ";
    }
    else if(val > root->val){
        insert(root->right, val);
        // cout<<root->right->val<<" ";
    }
    return;
}

void insertNode(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    v.push_back(root->val);
    // cout<<root->val<<" ";
    if(root->right != NULL){
        insertNode(root->right, v);
    }
    if(root->left != NULL){
        insertNode(root->left, v);
    }
    return;
}

int inOrder(TreeNode* root, int &count, int k){
    if(root == NULL) return -1;
    int left = inOrder(root->left, count, k);
    if(left != -1){
        return left;
    }
    count++;
    if(count == k){
        return root->val;
    }
    int right = inOrder(root->right, count, k);
}

// int predecessor(TreeNode* root, int num){
//     if(root == NULL){
//         return -1;
//     }
//     int ans = root->val;
//     predecessor(root->left, num);
//     if(num == root->val){
//         return ans;
//     }
//     predecessor(root->left, num);
// }

// int inOrderPred(TreeNode* root, int num){
//     int count = 0;
//     return predecessor(root, num);
// }

int minVal(TreeNode* root){
    while(root != NULL){
        // cout<<root
        root = root->left;
    }
    return root->val;
}

int maxVal(TreeNode* root){
    while(root != NULL){
        root = root->right;
    }
    return root->val;
}

// InOrder Predecessor
void inOrderTraverse(TreeNode* root, int num, vector<int> &v, bool pred){
    if(root == NULL){
        return;
    }
    inOrderTraverse(root->left, num, v, pred);
    if(root->val < num && pred && root != NULL){
        v.push_back(root->val);
    }
    else if(root->val > num && (!pred) && root != NULL){
        v.push_back(root->val);
    }
    inOrderTraverse(root->right, num, v, pred);
    // return left;
}

int pred(TreeNode* root, int num){
    vector<int> v;
    inOrderTraverse(root, num, v, true);
    return v[v.size() - 1];
}

int succ(TreeNode* root, int num){
    vector<int> v;
    inOrderTraverse(root, num, v, false);
    if(v[0]) return v[0];
    else return num;
    // return v[0];
}

// Kth Smallest------------------------------------------

int kthSmallestInOrder(TreeNode* root, int k){
    int count = 0;
    return inOrder(root, count, k);
}

int kthSmallest(TreeNode* root, int k){
    vector<int> v;
    insertNode(root, v);
    for(auto i: v){
        cout<<i<<" ";
    }
    sort(v.begin(), v.end());
    return v[k-1];
}

int main(){
    TreeNode* n = new TreeNode(5);
    insert(n, 3);
    insert(n, 4);
    insert(n, 2);
    insert(n, 6);
    cout<<"\n-------------------------------\n";

    cout<<"\n3rd smallest element in the BST is : "<<kthSmallest(n, 3)<<endl;
    cout<<"\n3rd smallest element in the BST is : "<<kthSmallestInOrder(n, 5)<<endl;

    cout<<"\n-------------------------------\n";
    cout<<"Inorder predecesor of 4 is : "<<pred(n, 6)<<endl;
    cout<<"Inorder successor of 4 is : "<<succ(n, 6)<<endl<<endl;

return 0;
}