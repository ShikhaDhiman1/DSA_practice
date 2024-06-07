#include <iostream>
#include "linkedList.h"
using namespace std;

/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.*/

Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* middleNode2(Node* head){
    int size = 0;
    Node* temp = head;

    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    int mid = size/2;
    temp = head;
    while(mid){
        temp = temp->next;
        mid--;
    }
    return temp;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);

    // Node* midNode = middleNode(head);
    Node* midNode = middleNode2(head);
    cout<<midNode->data<<"\n";
    return 0;
}