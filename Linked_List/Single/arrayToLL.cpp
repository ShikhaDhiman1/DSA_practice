#include <iostream>
#include <vector>
#include "linkedList.h"
using namespace std;

Node* createLLfromArrays(vector<int> &arr){
    Node* temp = new Node(arr[0]);
    Node *list = temp;

    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return list;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = createLLfromArrays(arr);
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
    return 0;
}