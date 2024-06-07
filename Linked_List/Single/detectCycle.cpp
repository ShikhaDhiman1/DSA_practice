#include <iostream>
#include <unordered_map>
#include "linkedList.h"
using namespace std;

bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

bool hasCycle2(Node* head){
    unordered_map<Node*, int> mp;

    Node* temp = head;

    while(temp != NULL){
        if(mp[temp] == 0) mp[temp]++;
        else return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    return 0;
}