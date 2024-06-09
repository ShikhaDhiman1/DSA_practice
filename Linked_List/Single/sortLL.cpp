#include <iostream>
#include "linkedList.h"
#include <vector>
#include <queue>
using namespace std;

Node* sortList(Node* head){
    priority_queue<int, vector<int>, greater<int>> pq;

    Node* temp = head;

    while(temp != NULL){
        pq.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(!pq.empty()){
        temp->data = pq.top();
        pq.pop();
        temp = temp->next;
    }

    return head;
}
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeLists(Node* list1, Node* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    Node* temp = new Node(-1);
    Node* ans = temp;

    while(list1 && list2){
        if(list1->data <= list2->data){
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    if(list2) temp->next = list2;

    return ans->next;
}
Node* sortListMergeSort(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddle(head);

    Node* right = middle->next;
    middle->next = NULL;
    Node* left = head;

    return mergeLists(left, right);
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* newHead = sortList(head);
    while(newHead != NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<"\n";

    Node* newHead2 = sortListMergeSort(head);
    while(newHead2 != NULL){
        cout<<newHead2->data<<" ";
        newHead2 = newHead2->next;
    }
    cout<<"\n";

    return 0;
}