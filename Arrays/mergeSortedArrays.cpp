#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void mergeArrays(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size();
    int n = nums2.size();

    int gap = ceil((float)(m + n)/2); // gap = (m + n)/2 + (m + n)%2

    while(gap > 0){
        int left = 0;
        int right = gap;
        while(right < n + m){
            if(right < m){
                if(nums1[left] > nums1[right]){
                    swap(nums1[left], nums1[right]);
                }
            }else{
                if(left < m){
                    if(nums1[left] > nums2[right - m]){
                        swap(nums1[left], nums2[right - m]);
                    }
                }else{
                    if(nums2[left - m] > nums2[right - m]){
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = ceil((float)gap/2); // gap = gap/2 + gap%2;
    }
    for(auto x : nums2){
        nums1.push_back(x);
    }
}

void mergeArrays2(vector<int> &nums1, int m, vector<int> &nums2, int n){
    vector<int> temp;
    int i = 0, j = 0;

    while(i < m && j < n){
        if(nums1[i] <= nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        }
        else{
            temp.push_back(nums2[j]);
            j++;
        }
    }
    while(i < m){
        temp.push_back(nums1[i]);
        i++;
    }
    while(j < n){
        temp.push_back(nums2[j]);
        j++;
    }
    
    for(int x = 0; x < (n + m); x++){
        nums1[x] = temp[x];
    }
}

void mergeArrays3(vector<int> &nums1, int m, vector<int> &nums2, int n){ 
    int i = 0, j = 0;
    if(n == 0) return;
    
    while(i < m){
        if(nums1[i] > nums2[j]){
            swap(nums1[i], nums2[j]);
            sort(nums2.begin(), nums2.end());
        }
        i++;
    }
    while(j < n){
        nums1[j + m] = nums2[j];
        j++;
    }
}

void mergeArrays4(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = m-1, j = 0;
    while(i >= 0 && j < n){
        if(nums1[i] > nums2[j]){
            swap(nums1[i], nums2[j]);
        }
        i--;
        j++;
    }
    sort(nums1.begin(), nums1.begin()+m);
    sort(nums2.begin(), nums2.end());

    for(int i = m; i < n+m; i++){
        nums1[i] = nums2[i - m];
    }
}

int main(){
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 6, 8, 9};

    mergeArrays(nums1, nums2);

    for(auto x : nums1){
        cout<<x<<" ";
    }
    cout<<"\n";

    nums1 = {1, 3, 5, 7, 0, 0, 0, 0, 0};
    nums2 = {0, 2, 6, 8, 9};
    mergeArrays2(nums1, 4, nums2, nums2.size());
    for(auto x : nums1){
        cout<<x<<" ";
    }
    cout<<"\n";

    nums1 = {1, 3, 5, 7, 0, 0, 0, 0, 0};
    nums2 = {0, 2, 6, 8, 9};
    mergeArrays3(nums1, 4, nums2, nums2.size());
    for(auto x : nums1){
        cout<<x<<" ";
    }
    cout<<"\n";

    nums1 = {1, 3, 5, 7, 0, 0, 0, 0, 0};
    nums2 = {0, 2, 6, 8, 9};
    mergeArrays4(nums1, 4, nums2, nums2.size());
    for(auto x : nums1){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}