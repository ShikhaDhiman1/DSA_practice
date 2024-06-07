#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;

    node(int val){
        data = val;
        next = NULL;
        previous = NULL;
    }
};

int size(node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    // if(head == NULL){
    //     head = n;
    //     return;
    // }
    n->next = head;
    if(head != NULL){
        head->previous = n;
    }
    head = n;

    // return;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        // head = n;
        // return;
        insertAtHead(head, val);
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
    return;
}

void insertInbetween(node* &head, int val, int pos){
    node* n  = new node(val);
    int count = 1;
    node* temp = head;
    while(count < pos-1){
        count++;
        if(temp->next == NULL){
            temp->next = new node(0);
        }
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    n->previous = temp;
    return;
}

void deleteNode(node* &head, int pos){
    if(pos > size(head)){
        cout<<"Position Not Found!\n";
        return;
    }
    // if(head == NULL)
    node* temp = head;
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    temp->next->previous = temp;
    delete todelete;
    return;
}

void deleteAtHead(node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* todelete = head;
    // head->next->previous = NULL;
    head = head->next;
    delete todelete;
    return;
}

void deleteAtTail(node* &head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->previous->next = NULL;
    delete temp;
    return;
}

void display(node* &head){
    cout<<"\nDoubly Linked List is: \n";

    node* temp = head;

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

int main(){
    node* n = new node(2);
    insertAtTail(n, 3);
    insertAtTail(n, 4);
    insertAtTail(n, 5);
    insertAtTail(n, 6);
    display(n);
    cout<<endl;
    insertAtHead(n, 1);
    display(n);
    cout<<endl;
    insertAtHead(n, -2);
    insertAtHead(n, -1);
    insertAtHead(n, 0);
    insertInbetween(n, 10, 15);
    display(n);
    cout<<endl;
    cout<<"Size of doubly linked list is: "<<size(n)<<endl<<endl;

    deleteNode(n, 5);
    display(n);
    cout<<endl;
    deleteNode(n, 15);
    display(n);
    cout<<endl;

    deleteAtHead(n);
    display(n);
    cout<<endl;

    deleteAtTail(n);
    display(n);
    cout<<endl;
    return 0;
}