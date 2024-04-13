// USES hare and turtle algorithm
// OR Floyd's algorithm
#include <iostream>
#include "linkList.h"
using namespace std;

void makeCycle(node* &head, int pos){
    // node* fast = head;
    // node* slow = head;
    node* temp = head;
    node* join;
    int count = 1;
    while( temp->next != NULL){
        if(count == pos){
            join = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = join;
    return;
}

bool detectCycle(node* &head){
    node* fast = head;
    node* slow = head;
    // bool isCycle = false;
    while(fast->next != NULL && fast != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            // isCycle = true;
            // break;
            return true;
        }
    }
    // if(isCycle) cout<<"Detected!\n";
    // else cout<<"Not Detected\n";
    return false;
}

void removeCycle(node* &head){
    node* fast = head;
    node* slow = head;

    while(fast->next != NULL && fast != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            fast = head;
            break;
        }
    }
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    return;
}

int main(){
    node* n = new node(4);
    insertAtTail(n, 14);
    insertAtTail(n, 24);
    insertAtTail(n, 34);
    insertAtTail(n, 44);
    insertAtTail(n, 54);
    insertAtTail(n, 64);
    insertAtTail(n, 74);
    makeCycle(n, 4);
    // display(n);
    display(n);
    cout<<endl;
    removeCycle(n);
    display(n);
    cout<<endl;

    node* n1 = new node(4);
    insertAtTail(n1, 10);
    insertAtTail(n1, 24);
    insertAtTail(n1, 34);
    insertAtTail(n1, 44);
    insertAtTail(n1, 54);
    


    if(detectCycle(n)) cout<<"Cycle Detected!\n";
    else cout<<"No Cycle present!\n";
    display(n1);
    
    if(detectCycle(n1)){
        cout<<"Cycle Detected!\n";
    }
    else if(!detectCycle(n1)){cout<<"No Cycle present!\n";}
    cout<<endl;
    
    return 0;
}