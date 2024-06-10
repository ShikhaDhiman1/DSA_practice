#include <iostream>
#include "doublyLinkList.h"
using namespace std;

/*Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.*/

Node* removeDuplicates(Node* head){
    Node* temp = head;

    while(temp->next != NULL){
        if(temp->next->data == temp->data){
            Node* toDelete = temp;
            if(temp->prev == NULL){
                head = temp->next;
            }
            else{
                temp->prev->next = temp->next;
            }
            temp->next->prev = temp->prev;
            temp = temp->next;

            toDelete = NULL;
            delete(toDelete);
        }
        else temp = temp->next;
    }

    return head;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    Node* ans = removeDuplicates(head);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<"\n";

    return 0;
}