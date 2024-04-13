#include <iostream>
#include <bits/stdc++.h>
// #include "doublyLinkList.h"
#include "linkList.h"
using namespace std;

void append(node* &head, int k){
    if(k >= size(head)){
        cout<<"\nPlease Enter the value of k < size of the linked List!\n";
        return;
    }
    node* temp = head;
    node* temp1 = head;
    int count = 1;
    while(count < k){
        count++;
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    node* start = head;
    while(start->next != NULL){
        start = start->next;
    }
    start->next = temp1;
    return;
}

int main(){
    node* n = new node(1);
    insertAtTail(n, 2);
    insertAtTail(n, 3);
    insertAtTail(n, 4);
    insertAtTail(n, 5);
    insertAtTail(n, 6);
    display(n);
    cout<<endl;

    append(n, 6);
    display(n);
    cout<<endl;

    insertAtHead(n, 8);
    insertInBetween(n, 9, 4);
    display(n);
    cout<<endl;

    append(n, 4);
    display(n);
    cout<<endl;

    return 0;
}