#include <iostream>
#include "linkedList.h"
#include <unordered_map>
using namespace std;

/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.*/

Node *startingNode(Node *head)
{
    unordered_map<Node *, int> mp;

    Node *temp = head;
    while (temp != NULL)
    {
        if (mp[temp] == 0)
            mp[temp]++;
        else
            return temp;

        temp = temp->next;
    }
    return NULL;
}

Node *startingNode2(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}
int main()
{
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

    Node *loopNode = startingNode(head);
    cout << loopNode->data << "\n";

    Node *loopNode2 = startingNode2(head);
    cout << loopNode2->data << "\n";

    return 0;
}