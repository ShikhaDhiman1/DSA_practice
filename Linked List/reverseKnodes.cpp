#include <iostream>
#include "linkList.h"
using namespace std;

node* reverseTillKNode(node* &head, int k){
    if(size(head) < k){
        cout<<"\nPlease enter a valid value for k!\n";
        return NULL;
    }
    if(head == NULL || head->next == NULL){
        return head;
    }
    int i = 0;
    node* prev = NULL;
    node* curr = head;
    node* nextNode = head->next;
    while(i != k){
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
        i++;
    }
    if(i < k){
        return prev;
    }
    node* temp = prev;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(curr != NULL){
        temp->next = curr;
    }
    else{
        temp->next = NULL;
    }
    return prev;
}

node* reverseKNode(node* &head, int k){
    // if(head == NULL || head->next != NULL){
    //     return head;
    // }
    int count = 0;
    node* prev = NULL;
    node* curr = head;
    // node* nextNode = head->next;
    node* nextNode;

    while(curr != NULL && count < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        // nextNode = nextNode->next;
        count++;
    }
    // cout<<prev->data<<" "<<curr->data<<endl;

    if(curr != NULL){
        head->next = reverseKNode(curr, k);
    }
    // OR
    // if(nextNode != NULL){
    //     head->next = reverseKNode(nextNode, k);
    // }
    return prev;
}

int main(){
    node* n = new node(13);
    insertAtHead(n, 8);
    insertAtTail(n, 12);
    insertInBetween(n, 10, 2);
    display(n);
    cout<<endl;
    node* nrev = reverseTillKNode(n, 3);
    display(nrev);
    cout<<endl;

    insertAtHead(n, 4);
    display(n);
    cout<<endl;
    node* nrev1 = reverseTillKNode(n, 2);
    display(nrev1);
    cout<<endl;

    node* n1 = new node(10);
    insertAtHead(n1, 18);
    insertAtTail(n1, 1);
    insertInBetween(n1, 11, 2);
    insertInBetween(n1, 9, 4);
    display(n1);
    cout<<endl;
    node* nrev2 = reverseTillKNode(n1, 3);
    display(nrev2);
    cout<<endl;

    node* n2 = new node(1);
    insertAtHead(n2, 8);
    insertAtTail(n2, 11);
    insertInBetween(n2, 15, 2);
    insertInBetween(n2, 6, 4);
    display(n2);
    cout<<endl;

    node* nrev3 = reverseKNode(n2, 2);
    cout<<"k-node\n";
    display(nrev3);
    cout<<endl;

    // node* n3 = new node(11);
    // display(reverseKNode(n3, 2));
    // cout<<endl;
    return 0;
}