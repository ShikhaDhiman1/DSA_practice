#include <iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int val){
        data = val;
        next = NULL;
        random = NULL;
    }
};

Node* clone(Node* head){
    Node* temp = head;
    unordered_map<Node*, Node*> mp;
    mp[NULL] = NULL;

    while(temp != NULL){
        mp[temp] = new Node(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

Node* clone2(Node* head){
    Node* temp = head;

    while(temp != NULL){
        Node* nextNode = temp->next;
        temp->next = new Node(temp->data);
        temp->next->next = nextNode;
        temp = temp->next->next;
    }

    temp = head;
    while(temp != NULL){
        if(temp->random == NULL){
            temp->next->random = NULL;
        }else{
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    temp = head;
    Node* dummy = new Node(-1);
    Node* ans = dummy;

    while(temp != NULL){
        dummy->next = temp->next;
        dummy = dummy->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }

    return ans->next;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    Node* ans = clone(head);
    while (ans != nullptr) {
        cout<< ans->data;
        if (ans->random != nullptr) {
            cout << "->" << ans->random->data;
        } else {
            cout << "->nullptr";
        }
        cout <<"\n|"<< endl;
        cout <<"v"<< endl;
        ans = ans->next;  
    }
    cout<<"------------------------\n";
    Node* ans2 = clone2(head);
    while (ans2 != nullptr) {
        cout<< ans2->data;
        if (ans2->random != nullptr) {
            cout << "->" << ans2->random->data;
        } else {
            cout << "->nullptr";
        }
        cout <<"\n|"<< endl;
        cout <<"v"<< endl;
        ans2 = ans2->next;  
    }
    return 0;
}
