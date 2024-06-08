#include <iostream>
#include "linkedList.h"
#include <vector>
using namespace std;

/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/

// BRUTE approach==========================================================================
Node* removeNthNode(Node* head, int n){
    Node* temp = head;
    int size = 0;

    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    if(size == n){
        Node* toDelete = head;
        head = head->next;
        toDelete = NULL;
        delete toDelete;
        return head;
    }
    int pos = size - n;
    temp = head;
    while(pos > 1){
        pos--;
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    if(temp->next != NULL) temp->next = temp->next->next;
    toDelete = NULL;
    delete toDelete;

    return head;
}

// OPTIMAL approach =======================================================
Node* removeNthNode2(Node* head, int n){
    Node* slow = head;
    Node* fast = head;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == NULL){
        Node* toDelete = head;
        head = head->next;
        toDelete = NULL;
        delete toDelete;
        return head;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    toDelete = NULL;
    delete toDelete;

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 5;

    Node* ans1 = removeNthNode(head, n);
    while(ans1 != NULL){
        cout<<ans1->data<<" ";
        ans1 = ans1->next;
    }
    cout<<"\n";
    
    Node* ans2 = removeNthNode2(head, n);

    while(ans2 != NULL){
        cout<<ans2->data<<" ";
        ans2 = ans2->next;
    }
    cout<<"\n";
    return 0;
}