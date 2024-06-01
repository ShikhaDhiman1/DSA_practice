#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
    1. Each student gets at least one book.
    2. Each book should be allocated to only one student.
    3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.

*/
int studentsWithPages(vector<int> &arr, int pages){  // T.C. = O(n)
    int students = 1;
    int totalPages = 0;

    for(int i = 0; i < arr.size(); i++){
        if(totalPages + arr[i] <= pages){
            totalPages += arr[i];
        }
        else{
            students++;
            totalPages = arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int students){
    int n = arr.size();

    if(n < students) return -1;

    int low = *max_element(arr.begin(), arr.end()); // max
    if(n == students) return low; 

    int high = accumulate(arr.begin(), arr.end(), 0); // sum
    if(students == 1) return high;

    // BRUTE approach
    // for(int pages = low; pages <= high; pages++){      // T.C. = O(sum - max + 1) ,i.e., O(high - low + 1);
    //     if(studentsWithPages(arr, pages) == students){
    //         return pages;
    //     }
    // }
    // return -1;

    // OPTIMAL using BINARY search
    while(low <= high){
        int mid = (low + high)/2;

        if(studentsWithPages(arr, mid) <= students){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {12, 34, 67, 90};
    int students = 2;
    cout<<findPages(arr, students)<<"\n";
    return 0;
}