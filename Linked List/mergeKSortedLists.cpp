#include <iostream>
#include <vector>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(){
            val = 0;
            next = NULL;
        }
        ListNode(int x){
            val = x;
            next = NULL;
        }
        ListNode(int x, ListNode *next){
            val = x;
            next = next;
        }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL && list2 == NULL) return NULL;
    if(list1 == NULL && list2 != NULL) return list2;
    if(list1 != NULL && list2 == NULL) return list1;

    ListNode* head = NULL;

    if(list1->val <= list2->val){
        head = list1;
        list1 = list1->next;
    }
    else{
        head = list2;
        list2 = list2->next;
    }

    ListNode* temp = head;

    while(list1 && list2){
        if(list1->val <= list2->val){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1 != NULL){
        temp->next = list1;
    }
    else {
        temp->next = list2;
    }
    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = 0;
    ListNode* head = NULL;
    ListNode* l1 = lists[k];
    ListNode* l2 = lists[k + 1];
    if(l1->val <= l2->val){
        head = l1;
        l1 = l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    ListNode* temp = head;

    while(l1 && l2){
        if(l1->val <= l2->val){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1 != NULL){
        temp->next = l1;
    }
    else{
        temp->next = l2;
    }
    k+=2;
    cout<<head->val<<" "<<temp->val<<endl;
    // ListNode* temp = head;
    while(k < lists.size()){
        cout<<head->val<<" "<<temp->val<<endl;
        ListNode* l1 = head;
        ListNode* l2 = lists[k];
        if(l1->val <= l2->val){
            cout<<"!\n";
            head = l1;
            l1 = l1->next;
        }
        else{
            cout<<"12!\n";

            head = l2;
            l2 = l2->next;
        }
        ListNode* temp = head;
        while(l1 && l2){
            cout<<"while!\n";

            if(l1->val <= l2->val){
                cout<<"if\n";
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                cout<<"else\n";
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1 != NULL){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }
        k = k + 1;
    }

    return head;
}

ListNode* mergeKLists2(vector<ListNode*>& lists) {
    if(lists.size() == 0) return NULL;
    if(lists.size() == 1) return lists[0];
    int k = 0;
    ListNode* head = mergeTwoLists(lists[k], lists[k + 1]);
    k += 2;
    while(k < lists.size()){
        head = mergeTwoLists(head, lists[k]);
        k++;
    }
    return head;
}

int main(){
    ListNode* n1 = new ListNode(2);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(7);
    n1->next->next->next = new ListNode(9);
    n1->next->next->next->next = new ListNode(9);

    ListNode* n2 = new ListNode(5);
    n2->next = new ListNode(6);
    n2->next->next = new ListNode(7);
    n2->next->next->next = new ListNode(8);
    n2->next->next->next->next = new ListNode(8);

    ListNode* n3 = new ListNode(1);
    n3->next = new ListNode(3);
    n3->next->next = new ListNode(5);
    n3->next->next->next = new ListNode(19);

    vector <ListNode*> v = {n1, n2, n3};

    ListNode* ans = mergeKLists2(v);
    while(ans != NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<endl;

    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* l3 = NULL;

    vector <ListNode*> v1 = {l1, l2, l3};

    ListNode* ans1 = mergeKLists2(v1);
    while(ans1 != NULL){
        cout<<ans1->val<<" ";
        ans1 = ans1->next;
    }
    cout<<endl;

    vector <ListNode*> v2;

    ListNode* ans2 = mergeKLists2(v2);
    while(ans2 != NULL){
        cout<<ans2->val<<" ";
        ans2 = ans2->next;
    }
    cout<<endl;


    return 0;
}