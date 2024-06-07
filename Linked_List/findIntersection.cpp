#include <iostream>
#include "linkList.h"
using namespace std;

void intersect(node* &head1, node* &head2, int pos){
    node* temp2 = head2;
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp2 = temp2->next;
    }
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp2;
    return;
}

node* findIntersect(node* head1, node* head2){
    int l1 = size(head1);
    int l2 = size(head2);
    node* temp1;
    node* temp2;
    node* res;
    int diff;
    if(l1 > l2){
        diff = l1-l2;
        temp1 = head1;
        temp2 = head2;
    }
    else{
        diff = l2-l1;
        temp1 = head2;
        temp2 = head1;
    }
    // int count = 1;
    while(diff){
        temp1 = temp1->next;
        if(temp1 == NULL){
            cout<<"No Intersection!\n";
            // return temp2;
            return NULL;
        }
        diff--;
    }
    while(temp1->next != NULL && temp2->next != NULL){
        if(temp1->next == temp2->next){
                return temp1->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout<<"No Intersection!\n";
    return NULL;
}

int main(){
    node* n1 = new node(1);
    insertAtTail(n1, 2);
    insertAtTail(n1, 3);
    insertAtTail(n1, 4);
    insertAtTail(n1, 5);
    display(n1);
    cout<<endl;

    node* n2 = new node(10);
    insertAtTail(n2, 20);
    insertAtTail(n2, 30);
    insertAtTail(n2, 40);
    display(n2);
    cout<<endl;

    intersect(n1, n2, 2);
    display(n1);
    cout<<endl;

    node* common = findIntersect(n1, n2);
    display(common);
    cout<<endl;

    node* n3 = new node(11);
    insertAtTail(n3, 21);
    insertAtTail(n3, 31);
    insertAtTail(n3, 41);
    display(n3);
    cout<<endl;

    display(findIntersect(n1, n3));
    cout<<endl;
    // display(n1);
    // cout<<endl;
    return 0;
}