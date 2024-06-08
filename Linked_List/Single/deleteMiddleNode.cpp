#include <iostream>
#include "linkedList.h"
using namespace std;

Node* deleteMiddle(Node* head){
    // Node* slow = head;
    // Node* fast = head;
    // Node* p = slow;

    // while(fast != NULL && fast->next != NULL){
    //     p = slow;
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }

    // p->next = slow->next;
    // slow = NULL;
    // delete slow;

    // return head;

    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    toDelete = NULL;
    delete toDelete;

    return head;
}

Node* deleteMiddle2(Node* head){
    Node* temp = head;
    int size = 0;

    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    temp = head;
    int n = size/2;
    while(n > 1){
        n--;
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    toDelete = NULL;
    delete toDelete;

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    Node* newHead = deleteMiddle(head);
    while(newHead != NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<"\n";
    
    Node* newHead2 = deleteMiddle2(head);

    while(newHead2 != NULL){
        cout<<newHead2->data<<" ";
        newHead2 = newHead2->next;
    }
    cout<<"\n";
    return 0;
}