#include <iostream>
#include "doublyLinkList.h"
#include <vector>
#include <unordered_map>
using namespace std;

/*Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.*/

vector<pair<int, int>> pairSum(Node* head, int target){
    unordered_map<int, int> mp;
    vector<pair<int, int>> ans;
    Node* temp = head;
    while(temp != NULL){
        if(mp.find(target - (temp->data)) != mp.end()){
            ans.push_back({target - (temp->data), temp->data});
        }
        mp[temp->data]++;

        temp = temp->next;
    }

    return ans;
}

// OPTIMAL
vector<pair<int, int>> pairSum2(Node* head, int target){
    vector<pair<int, int>> ans;
    Node* left = head;
    Node* right = NULL;

    while(left->next != NULL){
        left = left->next;
    }
    right = left;
    left = head;

    while(left->data < right->data){
        int sum = left->data + right->data;
        if(sum == target){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < target) left = left->next;
        else right = right->prev;
    }

    return ans;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 7);
    insertAtTail(head, 9);

    vector<pair<int, int>> ans = pairSum(head, 5);
    for(auto vec : ans){
        cout<<"{"<<vec.first<<", "<<vec.second<<"}\n";
    }
    cout<<"\n";

    vector<pair<int, int>> ans2 = pairSum2(head, 5);
    for(auto vec : ans){
        cout<<"{"<<vec.first<<", "<<vec.second<<"}\n";
    }
    cout<<"\n";
    return 0;
}