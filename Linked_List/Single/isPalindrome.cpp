#include <iostream>
#include <stack>
#include "linkedList.h"
using namespace std;

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node* midNode(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node* head){
    Node* middle = midNode(head);
    Node* revList = reverseList(middle);
    middle->next = NULL;
    
    while(revList->next != NULL){
        if(revList->data != head->data) return false;
        head = head->next;
        revList = revList->next;
    }
    return true;
}

bool isPalindrome2(Node* head){
    stack<int> st;
    Node* temp = head;
    
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
     temp = head;
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);

    cout<<isPalindrome(head)<<"\n";
    cout<<isPalindrome2(head)<<"\n";
    return 0;
}