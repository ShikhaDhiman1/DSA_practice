#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int size(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    // if(head == NULL){
    //     head = n;
    //     return;
    // }
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;

    // return;
}

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        // head = n;
        // return;
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return;
}

void insertInbetween(Node* &head, int val, int pos){
    Node* n  = new Node(val);
    int count = 1;
    Node* temp = head;
    while(count < pos-1){
        count++;
        if(temp->next == NULL){
            temp->next = new Node(0);
        }
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
    return;
}

void deleteNode(Node* &head, int pos){
    if(pos > size(head)){
        cout<<"Position Not Found!\n";
        return;
    }
    // if(head == NULL)
    Node* temp = head;
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete todelete;
    return;
}

void deleteAtHead(Node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* todelete = head;
    // head->next->prev = NULL;
    head = head->next;
    delete todelete;
    return;
}

void deleteAtTail(Node* &head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
    return;
}

void display(Node* &head){
    cout<<"\nDoubly Linked List is: \n";

    Node* temp = head;

    while(temp != NULL){
        if(temp->next != NULL){
            cout<<temp->data<<" <--> ";
        }
        else{
            cout<<temp->data;
        }
        temp = temp->next;
    }
    cout<<endl;
    return;
}