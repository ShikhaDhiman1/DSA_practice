#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order. Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
NOTE: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.*/
class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int val){
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

// BRUTE approach ======================================================================================
Node* flattenList(Node* root){
    priority_queue<int, vector<int>, greater<int>> pq;

    Node* temp = root;
    while(temp != NULL){
        Node* t2 = temp;
        while(t2 != NULL){
            pq.push(t2->data);
            t2->next = NULL;
            t2 = t2->bottom;
        }
        temp = temp->next;
    }   
    Node* ans = new Node(-1);
    Node* ansRoot = ans;
    while(!pq.empty()){
        ans->bottom = new Node(pq.top());
        pq.pop();
        ans = ans->bottom;
    }

    return ansRoot->bottom;
}

// ================================================================================
// OPTIMAL using RECURSION
Node* mergeLists(Node* list1, Node* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    Node* ans = new Node(-1);
    Node* temp = ans;
    while(list1 != NULL && list2 != NULL){
        if(list1->data <= list2->data){
            ans->bottom = list1;
            list1 = list1->bottom;
        }else{
            ans->bottom = list2;
            list2 = list2->bottom;
        }
        ans->next = NULL;
        ans = ans->bottom;
    }
    if(list1) ans->bottom = list1;
    if(list2) ans->bottom = list2;

    return temp->next;
}

Node* flattenList2(Node* root){
    if(root == NULL || root->next == NULL) return root;
    Node* mergedList = flattenList2(root->next);
    return mergeLists(root, mergedList);
}

int main(){
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);
    return 0;
}