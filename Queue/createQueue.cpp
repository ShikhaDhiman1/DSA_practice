#include <iostream>
using namespace std;

#define n 10

class queue{
    private:
        int *arr;
        int front;
        int back;
    public:
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }
        void enqueue(int x);
        void dequeue();
        int peek();
        bool isEmpty();
        void display();
};

void queue :: enqueue(int x){
    if(back == n-1){
        cout<<"\nQueue Overflow!!!\n";
        return;
    }
    back++;
    arr[back] = x;
    if(front == -1){
        front = 0; //OR front++;
    }
    return;
}

void queue::dequeue(){
    if(front > back || front == -1){
        cout<<"\nQueue Underflow!!!\n";
        return;
    }
    cout<<"\nElement popped is: ";
    cout<<arr[front]<<endl;
    front++;
}

int queue::peek(){
    if(isEmpty()){
        cout<<"\nNo Element in queue!\n Queue is Empty!\n";
        return -1;
    }
    return arr[front];
}

bool queue::isEmpty(){
    return (front > back || front == -1);
}


int main(){
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);

    cout<<"\nElement at front is : "<<q1.peek()<<endl;
    q1.dequeue();
    cout<<"\nElement at front is : "<<q1.peek()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    
    cout<<"\nElement at front is : "<<q1.peek()<<endl;
    if(q1.isEmpty()) cout<<"\nQueue is Empty...\n";
    else cout<<"\nQueue is not Empty...\n";
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    if(q1.isEmpty()) cout<<"\nQueue is Empty...\n";
    else cout<<"\nQueue is not Empty...\n";

    cout<<endl;
    return 0;
}