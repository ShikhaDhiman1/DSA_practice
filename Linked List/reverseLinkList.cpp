#include <iostream>
#include "linkList.h"
using namespace std;

// class node{
//     public:
//     int data;
//     node* next;
//     node(int d){
//         data = d;
//         next = NULL;
//     }
// };

node* reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    // node* nextNode = head->next ;
    node* nextNode;
    while(curr != NULL){
        if(curr == NULL){
            head = prev;
        }
        else{
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            // nextNode = nextNode->next;
        }
    }
    
    return prev;
}

// node* reverseRecursive(node* &head){
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     node* newHead = reverseRecursive(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newHead;
// }

void display2(node* &head){
    node* temp = head;
    while(temp != NULL){
        if(temp->next == NULL){
            cout<<temp->data;
        }
        else{
            cout<<temp->data<<" --> ";
        }
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main(){
    node* n = new node(1);
    insertAtTail(n, 2);
    insertAtTail(n, 3);
    insertAtTail(n, 4);
    insertAtTail(n, 5);
    display2(n);

    // node* nreverse = reverseRecursive(n);
    // display(nreverse);
    // cout<<endl;

    node* nrev = reverse(n);
    display2(nrev);
    cout<<endl;
    return 0;
}