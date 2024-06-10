#include <iostream>
#include "doublyLinkList.h"
#include <cmath>
using namespace std;

// BRUTE approach
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    long int n = 0;
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        n = n * 10 + temp->data;
        len++;
        temp = temp->next;
    }
    n += 1;
    if ((n / pow(10, len)) == 1)
    {
        len += 1;
    }
    temp = head;
    while (temp != NULL)
    {
        int digit = n / (pow(10, len - 1));
        n = n - digit * (pow(10, len - 1));\
        len--;
        temp->data = digit;
        temp = temp->next;
    }
    if (len){
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node(n);
    }
    return head;
}

int main()
{
    Node *head = new Node(9);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    insertAtTail(head, 9);

    Node *ans = addOne(head);
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << "\n";
    return 0;
}