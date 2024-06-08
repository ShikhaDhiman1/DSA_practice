#include <iostream>
#include "linkedList.h"
#include <vector>
using namespace std;

// BRUTE approach=======================================================
Node* segregate(Node* head){
    vector<int> arr;
    Node* temp = head;

    while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    temp = head;
    for(auto x : arr){
        temp->data = x;
        temp = temp->next;
    }

    return head;
}
// OPTIMAL approach=========================================================
Node* segregate2(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* newHead = segregate(head);
    while(newHead != NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<"\n";
    
    Node* newHead2 = segregate2(head);

    while(newHead2 != NULL){
        cout<<newHead2->data<<" ";
        newHead2 = newHead2->next;
    }
    cout<<"\n";
    return 0;
}