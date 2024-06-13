#include <iostream>
#include "linkedList.h"
#include <vector>
using namespace std;

Node* rotate(Node* head, int k){
    // if(head == NULL || head->next == NULL) return head;
    // Node* temp = head;
    // int size = 0;

    // while(temp != NULL){
    //     size++;
    //     temp = temp->next;
    // }
    // k = k % size;
    // if(k == 0) return head;
    
    // int x = size - k;
    // temp = head;
    // while(x > 1){
    //     temp = temp->next;
    //     x--;
    // }
    // Node* p = temp->next;
    // Node* ans = p;
    // temp->next = NULL;

    // while(p->next != NULL) p = p->next;
    // p->next = head;
    // return ans;

    // OR==========================================================================
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    int size = 0;

    while(temp->next != NULL){
        size++;
        temp = temp->next;
    }
    size++;
    temp->next = head;
    k = k % size;
    if(k == 0) return head;
    int x = size - k;
    temp = head;
    while(x > 1){
        temp = temp->next;
        x--;
    }
    Node* ans = temp->next;
    temp->next = NULL;

    return ans;
}

Node* rotate2(Node* head, int k){
    if(head == NULL || head->next == NULL) return head;
    while(k--){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node* dummy = temp->next;
        temp->next = NULL;
        dummy->next = head;
        head = dummy;
    }

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* ans = rotate(head, 2);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<"\n";

    Node* ans2 = rotate2(head, 2);
    while(ans2 != NULL){
        cout<<ans2->data<<" ";
        ans2 = ans2->next;
    }
    cout<<"\n";
    return 0;
}