#include <iostream>
#include <queue>
using namespace std;

int main(){
    // MAX-heap:->
    cout<<"\n.....This is a Max-Heap..... \n";
    priority_queue<int> maxheap;
    maxheap.push(7);
    maxheap.push(1);
    maxheap.push(17);
    maxheap.push(19);
    maxheap.push(2);
    maxheap.push(5);
    maxheap.push(3);

    cout<<"\nTop element of max-heap is : "<<maxheap.top();
    cout<<"\nPopping top element from heap...\n";
    maxheap.pop();
    cout<<"\nTop element of max-heap is : "<<maxheap.top();

    cout<<endl;
    
    //MIN-heap:->
    cout<<"\n.....This is a Min-Heap..... \n";
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(7);
    minheap.push(1);
    minheap.push(17);
    minheap.push(19);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"\nTop element of min-heap is : "<<minheap.top();
    cout<<"\nPopping top element from heap...\n";
    minheap.pop();
    cout<<"\nTop element of min-heap is : "<<minheap.top();

    cout<<endl<<endl;

    return 0;
}