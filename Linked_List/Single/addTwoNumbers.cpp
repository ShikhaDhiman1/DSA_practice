#include <iostream>
#include "linkedList.h"
using namespace std;

/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and 
each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

Node* addTwoNumbers2(Node* l1, Node* l2){
    // Node* temp1 = l1;
    // Node* temp2 = l2;
    // Node* ans = new Node(-1);
    // Node* temp = ans;
    // int carry = 0;
    // while(temp1 != NULL && temp2 != NULL){
    //     int n = temp1->val + temp2->val + carry;
    //     int digit = n % 10;
    //     carry = n / 10;
        
    //     temp->next = new Node(digit);
    //     temp = temp->next;
        
    //     temp1 = temp1->next;
    //     temp2 = temp2->next;
    // }
    // while(temp1 != NULL){
    //     int n = temp1->val + carry;
    //     int digit = n % 10;
    //     carry = n / 10;
        
    //     temp->next = new Node(digit);
    //     temp = temp->next;
        
    //     temp1 = temp1->next;
    // } 
    // while(temp2 != NULL){
    //     int n = temp2->val + carry;
    //     int digit = n % 10;
    //     carry = n / 10;
        
    //     temp->next = new Node(digit);
    //     temp = temp->next;
        
    //     temp2 = temp2->next;
    // }
    // return ans->next;

    Node* temp1 = l1;
    Node* temp2 = l2;
    Node* ans = new Node(-1);
    Node* temp = ans;
    int carry = 0;

    while((temp1 != NULL || temp2 != NULL) || carry){
        int n = 0;
        
        if(temp1 != NULL){
            n += temp1->data;
            temp1 = temp1->next;
        }
        if(temp2 != NULL){
            n += temp2->data;
            temp2 = temp2->next;
        }
        n += carry;
        carry = n / 10;
        
        temp->next = new Node(n % 10);
        temp = temp->next;
    }
    
    return ans->next;
}

int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    Node* head2 = new Node(9);
    head2->next = new Node(2);
    head2->next->next = new Node(8);

    Node* sum = addTwoNumbers2(head1, head2);
    while(sum != NULL){
        cout<<sum->data;
        sum = sum->next;
    }
    cout<<"\n";
    return 0;
}