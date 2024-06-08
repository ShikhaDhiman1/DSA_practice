#include <iostream>
#include "linkedList.h"
#include <map>
using namespace std;

Node* intersectPoint(Node* head1, Node* head2){
    map<Node*, int> mp;
    Node* temp1 = head1;
    while(temp1 != NULL){
        mp[temp1]++;
        temp1 = temp1->next;
    }

    Node* temp2 = head2;

    while(temp2 != NULL){
        if(mp.find(temp1) != mp.end()) return temp2;
        temp2 = temp2->next;
    }

    return NULL;
}

int listLen(Node* head){
    int size = 0;
    Node* temp = head;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
Node* intersectPoint2(Node* head1, Node* head2){
    int n1 = listLen(head1);
    int n2 = listLen(head2);

    if(n2 > n1) return intersectPoint2(head2, head1);
    int diff = n1 - n2;

    Node* temp1 = head1;
    while(diff--){
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp1 != NULL){
        if(temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

int main(){
    return 0;
}