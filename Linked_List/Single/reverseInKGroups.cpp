#include <iostream>
#include "linkedList.h"
#include <vector>
using namespace std;

Node* reverseKGroups(Node* head, int k){
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    for(int i = 0; i < arr.size(); i+= k){
        int x = i + k;
        if(x <= arr.size()){
            for(int j = i; j < (x + i)/2; j++){
                swap(arr[j], arr[(x + i) - j - 1]);
            }
        }
    }
    temp = head;
    for(auto x : arr){
        temp->data = x;
        temp = temp->next;
    }
    return head;
}
Node* getKthNode(Node* temp, int k){
    int count = 1;
    while(count <= k && temp->next != NULL){
        count++;
        temp = temp->next;
    }
    if(count == k) return temp;
    return NULL;
}

Node* reverseList(Node* head){
    if(head== NULL || head->next == NULL) return head;
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
Node* reverseKGroups2(Node* head, int k){
    Node* temp = head;
    Node* prevNode = NULL;

    while(temp != NULL){
        Node* kthNode = getKthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseList(temp);

        if(temp == head){
            head = kthNode;
        }
        else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* ans = reverseKGroups(head, 2);
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << "\n";

    Node* ans2 = reverseKGroups2(head, 2);
    while (ans2 != NULL)
    {
        cout << ans2->data << " ";
        ans2 = ans2->next;
    }
    cout << "\n";
    return 0;
}