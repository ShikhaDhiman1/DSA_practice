#include<iostream>
#include <sstream>
#include <queue>
using namespace std;

class Solution {
public:
    long long int toInt(string str){
        long long int num;
        stringstream mystream;
        mystream << str;
        mystream >> num;
        return num;
    }
    string toString(long long int num){
        string toStr;
        stringstream mystream;
        mystream << num;
        toStr = mystream.str();
        return toStr;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        // priority_queue<long long int> pq;
        priority_queue<string> pq;
        vector<string> :: iterator it;
        for(it = nums.begin(); it != nums.end(); it++){
            // pq.push(stoll(*it, NULL, 10));
            // pq.push(toInt(*it));
            pq.push(*it);
        }

        if(k == 1){
            return pq.top();
        }

        for(int i = 0; i < k-1; i ++){
            pq.pop();
        }

        // return to_string(pq.top());
        return (pq.top());
    }
};

// class Solution {
// public:
//     long long int toInt(string str){
//         long long int num;
//         stringstream mystream;
//         mystream << str;
//         mystream >> num;
//         return num;
//     }
//     string toString(long long int num){
//         string toStr;
//         stringstream mystream;
//         mystream << num;
//         toStr = mystream.str();
//         return toStr;
//     }
//     string kthLargestNumber(vector<string>& nums, int k) {
//         priority_queue<long long int> pq;
//         vector<string> :: iterator it;
//         for(it = nums.begin(); it != nums.end(); it++){
//             // pq.push(stoll(*it, NULL, 10));
//             pq.push(toInt(*it));
//         }

//         if(k == 1){
//             return toString(pq.top());
//         }

//         for(int i = 0; i < k-1; i ++){
//             pq.pop();
//         }

//         // return to_string(pq.top());
//         return toString(pq.top());
//     }
// };

int main(){
    Solution s;
    vector<string> nums;
    nums.push_back("1233455676878");
    nums.push_back("1233455678");
    nums.push_back("123345576878");
    nums.push_back("123345567688");
    nums.push_back("12334556760");
    nums.push_back("12334556768789");

    priority_queue<string> pq;
    pq.push("1233455676878");
    pq.push("1233455678");
    pq.push("123345576878");
    pq.push("123345567688");
    pq.push("12334556760");
    pq.push("12334556768789");
    cout<<pq.top()<<endl;
    return 0;
}