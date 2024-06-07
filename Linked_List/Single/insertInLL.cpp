#include <iostream>
#include "linkedList.h"
using namespace std;

Node* insertAtBeginning(Node* head, int x){
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

Node* insertAtEnd(Node* head, int x){
    Node* newNode = new Node(x);
    if(head == NULL) return newNode;
    Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main(){
    Node* head = NULL;
    head = insertAtEnd(head, 2);
    head = insertAtBeginning(head, 7);
    head = insertAtEnd(head ,8);
    head = insertAtBeginning(head, 3);

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
    return 0;
}