#include <iostream>
#include "doublyLinkList.h"
using namespace std;

/*You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.*/

void deleteAllOccurOfX(Node** head, int x) { // passing reference to head
    // Write your code here
    Node* temp = *head;
    
    while(temp != NULL){
        if(temp->data == x){
            if(temp == *head) *head = temp->next; // or *head = (*head)->next;
            Node* toDelete = temp;
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            toDelete = NULL;
            delete toDelete;
        }
        else temp = temp->next;
    }
}

int main(){
    Node* head = new Node(2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 7);
    insertAtTail(head, 2);

    deleteAllOccurOfX(&head, 2);
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
    return 0;
}