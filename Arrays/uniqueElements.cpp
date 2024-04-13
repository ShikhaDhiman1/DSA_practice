#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

void unique(int *arr, int n){
    for(int i = 0; i < n; i++){
        
    }
    return;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s;
    for(int i = 0; i < nums1.size(); i++){
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[i] == nums2[j]){
                s.insert(nums1[i]);
            }
        }
    }
    vector <int> ans;
    for(auto i: s){
        ans.push_back(i);
    }
    return ans;
}

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    set<int> s;
    vector<int>::iterator it;
    vector<int>::iterator itr;
    for(it = nums1.begin();it != nums1.end(); it++){
        for(itr = nums2.begin();itr != nums2.end(); itr++){
            if(*(it) == *(itr)){
                s.insert(*(it));
                nums2.erase(itr);
            }
        }
    }
    vector <int> ans;
    for(auto i: s){
        ans.push_back(i);
    }
    return ans;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector <int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(int i = 0; i < nums1.size(); i++){
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[i]< nums2[j]){
                i++;
            }
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
    }
    return ans;
}
// vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
//     while(!nums1.empty()){
        
//     }
// }

int main(){
    vector<int> v;
    v.push_back(4);
    v.push_back(9);
    v.push_back(5);
    // v.push_back(3);
    // v.push_back(4);

    vector<int> v1;
    v1.push_back(9);
    v1.push_back(4);
    v1.push_back(9);
    v1.push_back(4);
    // v1.push_back(4);
    vector<int> ans = intersect(v, v1);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}