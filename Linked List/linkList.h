#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
    int size1(node* &head);
};

int node:: size1(node* &head){
    node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

int size(node* &head){
    node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val); // node that is to be inserted!
    node* temp = head;
    if(head == NULL){
        head = n;
        return;
    }

    else{
        while(temp->next != NULL){
            temp = temp-> next;
        }
        temp->next = n;
    }
    return;
}

void insertInBetween(node* head, int val, int pos){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    // int j = 0;
    // while(temp != NULL){
    //     j++;
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    // cout<<endl<<pos<<" "<<j<<endl;
    // if(pos > j+1){
    //     cout<<"\nNo such position exist!\n";
    //     return;
    // }
    // else if(pos <= j+1){
    //     cout<<"kjdbk"; 
    //     int i = 0;
    //     while(i != pos){
    //         i++;
    //         temp = temp->next;
    //     }
    //     node* n1 = temp->next;
    //     temp->next = n;
    //     n->next = n1;
    // }
     int i = 1;
        while(i < pos-1){
            i++;
            if(temp->next == NULL){
                temp->next = new node(0);
            }
            temp = temp->next;
        }
        node* n1 = temp->next;
        temp->next = n;
        if(n1==NULL){
            return;
        }
        else{
            n->next = n1;
        }
    return;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
    }
    else{
        // node* temp = head;
        n->next = head;
        head = n;
    }
}

void deleteNode(node* &head, int key){
    if(head->data == key){
        head = head->next;
        return;
    }
    node* temp2 = head;
    node* temp = head;
    node* temp1 = temp->next;
    while(temp1 != NULL){
        if(temp1->data == key){
            if(temp1->next == NULL){
                cout<<temp1->data<<" "<<temp->data<<endl;
                temp->next = NULL;
            }
            // node* todelete = temp->next;
            // delete todelete;
            temp->next = temp1->next;
        }
        temp1 = temp1->next;
        temp = temp->next;
    }
    //  while(temp->next != NULL){
    //     if(temp->next->data == key){
    //         temp->next = temp->next->next;
    //     }
    //     temp->next = temp->next->next;
        // temp = temp->next;
    // }
    return;
}

void deleteAtHead(node* &head){
    cout<<"Deleted node At Head! "<<endl;
    if(head->next == NULL){
        head = NULL;
        return;
    }
    node* todelete = head;
    head = head->next;
    delete todelete;
    return;
}

void deleteAtTail(node* &head){
    cout<<"Deleted node At tail! "<<endl;
    if(head->next == NULL){
        head = NULL;
        return;
    }
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}


string search(node* head, int key){
    int i = 1;
    node* temp = head;
    while(temp->data != key){
        temp = temp->next;
        i++;
        if(temp==NULL){
            return "Key not Found!!";
        }
    }
    return to_string(i);
}

void display(node* head){
    cout<<"Linked List is :\n";
    node* temp = head;
    while(temp != NULL){
        if(temp->next != NULL){
            cout<<temp-> data<<" --> ";
        }
        else{
            cout<<temp->data;
        }
        temp = temp->next;
    }
    cout<<endl;
    return;
}

node* reverseRecursive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}