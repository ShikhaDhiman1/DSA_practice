#include <iostream>
#include <queue>
using namespace std;

int ksmallest(priority_queue<int, vector<int>, greater<int>> heap, int k){
    if(k > heap.size()){
        cout<<"\nValue Out Of Bound!\n";
        return -1;
    }
    for(int i = 0; i < k-1; i++){
        heap.pop();
    }
    return heap.top();
}

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        vector<int> :: iterator it;
        for(it = nums.begin(); it != nums.end(); it++){
            pq.push(*it);
        }
        for(int i = 0; i < k-1; i++){
            pq.pop();
        }

        return pq.top();
    }

int main(){
    priority_queue<int, vector<int>, greater<int>> heap;
    heap.push(12);
    heap.push(9);
    heap.push(2);
    heap.push(6);
    heap.push(11);
    heap.push(10);
    heap.push(5);
    heap.push(3);

    int k;
    cout<<"Enter the value of 'k' : ";
    cin>>k;
    cout<<endl;
    cout<<k<<"th smallest element in the heap is : "<<ksmallest(heap, k);
    cout<<endl;
    cout<<endl<<endl;
    return 0;
}