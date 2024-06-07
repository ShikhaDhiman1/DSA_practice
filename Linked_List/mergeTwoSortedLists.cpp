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

ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {

    if(list1 == NULL && list2 == NULL){
        return list1;
    }
    else if(list1 != NULL && list2 == NULL){
        return list1;
    }
    else if(list1 == NULL && list2 != NULL){
        return list2;
    }
    ListNode* head = NULL;
    // ListNode* ans = list->next;
    // ListNode* ans = list;

    // ListNode* temp1, temp2;

    if(list1->val >= list2->val){
        head = list1;
    }
    else head = list2;
    // else{
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    // }
    ListNode* list = head;
    cout<<"KAJSHFK\n";
    while(temp2 != NULL && temp1 != NULL){
        if(temp1->val <= temp2->val){
            while(temp1->val <= temp2->val){
                cout<<"Small-> "<<temp1->val<<" "<<temp2->val<<endl;
                // list = list->next;
                list = new ListNode(temp1->val);
                cout<<"temp1 -> "<<temp1->val<<endl;
                cout<<"list -> "<<list->val<<endl;
                temp1 = temp1->next;
                list = list->next;
                if(temp1 == NULL ) break;
            }
            list = new ListNode(temp2->val);
            cout<<"list -> "<<list->val<<endl;
            list = list->next;
            temp2 = temp2->next;
        }
        else{
            while(temp1->val > temp2->val ){
                cout<<"Large-> "<<temp1->val<<" "<<temp2->val<<endl;
                // list = list->next;
                list = new ListNode(temp2->val);
                cout<<"temp2 -> "<<temp2->val<<endl;
                cout<<"list -> "<<list->val<<endl;
                temp2 = temp2->next;
                list = list->next;
                if(temp2 == NULL ) break;
                
            }
            list = new ListNode(temp1->val);
            cout<<"list -> "<<list->val<<endl;
            list = list->next;
            // temp2 = temp2->next;
            temp1 = temp1->next;
        }
        cout<<"end---\n";
        // temp2 = temp2->next;
        // temp1 = temp1->next;
    }
    cout<<"mdfbkf\n";
    if(temp1){
        cout<<"!temp1\n";
        while(temp1 != NULL){
            list = new ListNode(temp1->val);
            cout<<"list -> "<<list->val<<endl;
            temp1 = temp1->next;
            list = list->next;
        }
        // list = temp1;
    }
    else if(temp2){
        cout<<"!temp2\n";
        while(temp2->next != NULL){
            list = new ListNode(temp2->val);
            cout<<"list -> "<<list->val<<endl;
            temp2 = temp2->next;
            list = list->next;
        }
        // list = temp2;
    }
    return head;
}

// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

//     // ListNode* ans = list1;

//     if(list1 == NULL && list2 == NULL){
//         return list1;
//     }
//     else if(list1 != NULL && list2 == NULL){
//         return list1;
//     }
//     else if(list1 == NULL && list2 != NULL){
//         return list2;
//     }
//     // ListNode* list = new ListNode(0);
//     // ListNode* ans = list->next;
//     ListNode* temp1 = list1;
//     ListNode* temp2 = list2;

//     list1 = NULL;
//     ListNode* ans = list1;
   
//     // cout<<"KAJSHFK\n";
//     while(temp2 != NULL && temp1 != NULL){
//         if(temp1->val <= temp2->val){
//             while(temp1->val <= temp2->val){
//                 cout<<"Small-> "<<temp1->val<<" "<<temp2->val<<endl;
//                 // list = list->next;
//                 list1 = new ListNode(temp1->val);
//                 // cout<<"temp1 -> "<<temp1->val<<endl;
//                 // cout<<"list -> "<<list->val<<endl;
//                 temp1 = temp1->next;
//                 list1 = list1->next;
//                 if(temp1 == NULL ) break;
//             }
//             list1 = new ListNode(temp2->val);
//             // cout<<"list -> "<<list->val<<endl;
//             list1 = list1->next;
//             temp2 = temp2->next;
//         }
//         else{
//             while(temp1->val > temp2->val ){
//                 // cout<<"Large-> "<<temp1->val<<" "<<temp2->val<<endl;
//                 // list = list->next;
//                 list1 = new ListNode(temp2->val);
//                 // cout<<"temp2 -> "<<temp2->val<<endl;
//                 // cout<<"list -> "<<list->val<<endl;
//                 temp2 = temp2->next;
//                 list1 = list1->next;
//                 if(temp2 == NULL ) break;
                
//             }
//             list1 = new ListNode(temp1->val);
//             // cout<<"list -> "<<list->val<<endl;
//             list1 = list1->next;
//             // temp2 = temp2->next;
//             temp1 = temp1->next;
//         }
//         // cout<<"end---\n";
//         // temp2 = temp2->next;
//         // temp1 = temp1->next;
//     // cout<<"mdfbkf\n";
//     }
//     if(temp1){
//         cout<<"!temp1\n";
//         while(temp1 != NULL){
//             list1 = new ListNode(temp1->val);
//             cout<<"list -> "<<list1->val<<endl;
//             temp1 = temp1->next;
//             list1 = list1->next;
//         }
//         // list = temp1;
//     }
//     else if(temp2){
//         cout<<"!temp2\n";
//         while(temp2->next != NULL){
//             list1 = new ListNode(temp2->val);
//             cout<<"list -> "<<list1->val<<endl;
//             temp2 = temp2->next;
//             list1 = list1->next;
//         }
//         // list = temp2;
//     }
//     return ans;
// }

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
        cout<<"list2: "<<list2->val<<endl;
        temp->next = list2;
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

    ListNode* ans = mergeTwoLists(n1, n2);

    while(ans != NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}