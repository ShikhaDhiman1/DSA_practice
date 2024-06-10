#include <iostream>
#include "doublyLinkList.h"
#include <cmath>
#include <vector>
using namespace std;

// BRUTE approach
Node* addOne(Node *head)
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
        n = n - digit * (pow(10, len - 1));
        len--;
        temp->data = digit;
        temp = temp->next;
    }
    if (len)
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(n);
    }
    return head;
}

Node* addOne2(Node *head)
{
    vector<int> vec;
    Node *temp = head;

    while (temp != NULL)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }

    int carry = 1;
    int n = vec.size() - 1;
    while (n >= 0)
    {
        vec[n] += carry;
        if (vec[n] >= 10)
        {
            carry = 1;
            vec[n] = 0;
        }
        else
        {
            carry = 0;
            break;
        }
        n--;
    }
    temp = head;
    for (auto x : vec)
    {
        temp->data = x;
        temp = temp->next;
    }

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

Node* reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

Node* addOne3(Node *head)
{
    head = reverseList(head);
    Node *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    head = reverseList(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}

int main()
{
    Node *head = new Node(9);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    insertAtTail(head, 9);

    Node *ans = addOne3(head);
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << "\n";
    return 0;
}