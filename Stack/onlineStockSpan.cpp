#include <iostream>
#include <stack>
using namespace std;

class StockSpanner{
    public:
    stack<pair<int, int>> st;
    StockSpanner(){}

    int next(int price){
        if(st.empty()){
            st.push({price, 1});
            return 1;
        }

        int count = 1;
        while(!st.empty() && st.top().first <= price){
            count += st.top().second;
            st.pop();
        }
        st.push({price, count});

        return count;
    }
};

int main(){
    StockSpanner sp;
    cout<<sp.next(100)<<"\n";
    cout<<sp.next(60)<<"\n";
    cout<<sp.next(70)<<"\n";
    cout<<sp.next(85)<<"\n";
    cout<<sp.next(80)<<"\n";

    return 0;
}