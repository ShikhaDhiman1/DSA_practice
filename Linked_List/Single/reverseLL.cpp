#include <iostream>
#include "linkedList.h"
using namespace std;

Node* reverseLinkedList(Node* head){
    if(head== NULL || head->next == NULL) return head;
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } 
    return prev;
}

Node* reverseLinkedList2(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLinkedList2(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* newHead = reverseLinkedList2(head);
    while(newHead != NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<endl;
    // head = new Node(1);
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);
    // Node* newHead2 = reverseLinkedList(head);
    // while(newHead2 != NULL){
    //     cout<<newHead2->data<<" ";
    //     newHead2 = newHead2->next;
    // }
    return 0;
}