#include <iostream>
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
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     ListNode* n1 = l1;
//     ListNode* n2 = l2;
//     cout<<"kskjvhk\n";
//     // int n1 = 0, n2 = 0;
//     while(n1 != NULL || n2 != NULL){
//         if(!(n1-> next)){
//             n1->next = new ListNode(0);
//         }
//         else if(!(n2-> next)){
//             n2->next = new ListNode(0);
//         }
//         cout<<n1->val<<" "<<n2->val<<endl;
//         n1 = n1->next;
//         n2 = n2->next;
//     }
//     ListNode* l3;
//     int carry = 0;
//     n1 = l1; n2 = l2;
//     if(!n1) cout<<"kemgnks\n";
//     while(n1 != NULL && n2 != NULL){
//         cout<<"skkfjhk\n";
//         int sum = (n1->val) + (n2->val);
//         int ones = sum/10;
//         cout<<l3->val<<endl;
//         l3->next = new ListNode(ones + carry);
//         carry = sum%10;
//         n1 = n1->next;
//         n2 = n2->next;
//     }
//     ListNode* head = l3;
//     l3 = l3->next;
//     delete head;

//     return l3;
// }

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* n1 = l1;
    ListNode* n2 = l2;

    int cnt1 = 0, cnt2 = 0;
    while(n1 != NULL){
        cnt1++;
        n1 = n1->next;
    }
    while(n2 != NULL){
        cnt2++;
        n2 = n2->next;
    }
    ListNode* maxL;
    ListNode* minL;
    if(cnt1 > cnt2){
        maxL = l1;
        minL = l2;
    }
    else{
        maxL = l2;
        minL = l1;
    }
    ListNode* l3 = new ListNode;
    ListNode* ans = l3;
    int carry = 0;
    while(maxL != NULL){
        if(minL == NULL){
            minL = new ListNode(0);
        }
        int sum = maxL->val + minL->val + carry;
        int tens = sum % 10;
        l3->next = new ListNode(tens);
        carry = sum / 10;
        sum = 0;
        l3 = l3->next;
        maxL = maxL->next;
        minL = minL->next;
        
    }
    if(carry != 0) l3->next = new ListNode(carry);
    ListNode* head = ans;
    ans = ans->next;
    delete head;

    return ans;

}

// 9 2 3 4 5
// 3 2 1
// 2 5 4 4 5

int main(){
    ListNode* n1 = new ListNode(2);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(9);
    // n1->next->next->next = new ListNode(9);
    // n1->next->next->next->next = new ListNode(9);
    // n1->next->next->next->next->next = new ListNode(9);
    // n1->next->next->next->next->next->next = new ListNode(9);

    ListNode* n2 = new ListNode(5);
    n2->next = new ListNode(6);
    n2->next->next = new ListNode(4);
    n2->next->next->next = new ListNode(9);
    
    ListNode* n3 = addTwoNumbers(n1, n2);

    while(n3 != NULL){
        cout<<n3->val<<" ";
        n3 = n3->next;
    }
    cout<<endl;
    return 0;
}