#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(4);
    pq.push(1);
    pq.push(9);
    pq.push(5);
    pq.push(7);
    pq.push(6);
    pq.push(2);

    // cout<<pq.top()<<"\n";
    // pq.pop();
    // cout<<pq.top()<<"\n";
    
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}