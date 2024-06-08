#include <iostream>
#include "linkedList.h"
#include <unordered_map>
using namespace std;

/*Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if 
the loop is present then return the count of nodes in a loop or else return 0. 
C is the position of the node to which the last node is connected. If it is 0 then no loop.*/

int loopLength(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            fast = fast->next;
            int count = 1;
            while(slow != fast){
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
}

int loopLength2(Node* head){
    unordered_map<Node*, int> mp; // <node, time>
    Node* temp = head;
    int time = 0;

    while(temp != NULL){
        if(mp.find(temp) == mp.end()){
            time++;
            mp[temp] = time;
        }
        else{
            return (time - mp[temp] + 1);
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node *head = node1;

    cout<<loopLength(head)<<"\n";
    cout<<loopLength2(head)<<"\n";
    return 0;
}