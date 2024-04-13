#include <iostream>
#include <queue>
using namespace std;

class stack{
    private:
    queue<int> q;
    queue<int> q1;
    public:
    void push(int x){
        q.push(x);
        return;
    }
    int pop(){
        while(q.size() != 1){
            q1.push(q.front());
            q.pop();
        }
        cout<<"Element popped is : "<<q.front()<<endl;
        q.pop();
        q.swap(q1);
    }
    void show(){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }
    int top(){
        while(q.size() != 1){
            q1.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q1.push(q.front());
        q.pop();
        queue<int> temp = q;
        q = q1;
        q1 = temp;
        return ans;
    }
    bool isEmpty(){
        return q.empty();
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    s.push(4);
    // s.show();
    s.pop();
    s.pop();
    cout<<endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}