#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = next;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    if(head == NULL){
        head = n;
        n->next = head;
    }
    else{
        while(temp->next != head){
            cout<<temp->data<<" == ";
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
    return;
}

void display(node* &head){
    node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<"-->";
    }
    cout <<endl;
    return;
}

int main(){
    node* n = new node(5);
    // display(n);
    insertAtTail(n, 9);
    insertAtTail(n, 1);
    insertAtTail(n, 19);
    insertAtTail(n, 6);
    display(n);
    cout<<endl;
    return 0;
}