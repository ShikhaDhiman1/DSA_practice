#include <iostream>
#include "linkedList.h"
using namespace std;

Node* sort0s1s2s(Node* head){
    if(head == NULL || head->next == NULL) return head;
    int count0 = 0, count1 = 0, count2 = 0;
    Node* temp = head;
    
    while(temp != NULL){
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else if(temp->data == 2) count2++;
        
        temp = temp->next;
    }
    
    temp = head;
    while(count0--){
        temp->data = 0;
        temp = temp->next;
    }
    while(count1--){
        temp->data = 1;
        temp = temp->next;
    }
    while(count2--){
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}

Node* sort0s1s2sOptimal(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* zero = new Node(-1);
    Node* zeroHead = zero;

    Node* one = new Node(-1);
    Node* oneHead = one;

    Node* two = new Node(-1);
    Node* twoHead = two;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else if(temp->data == 2){
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    return zeroHead->next;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);

    Node* newHead = sort0s1s2s(head);
    while(newHead != NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<"\n";

    Node* newHead2 = sort0s1s2sOptimal(head);
    while(newHead2 != NULL){
        cout<<newHead2->data<<" ";
        newHead2 = newHead2->next;
    }
    cout<<"\n";
    return 0;
}