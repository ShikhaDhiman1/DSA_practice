#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bSearch(vector<int> &arr, int start, int end, int key)
{
    if (start > end)
        return false;
    int mid = (start + end) / 2;
    int k = arr[mid];
    if (k == key)
        return true;
    else if (key > k)
    {
        bSearch(arr, mid + 1, end, key);
    }
    else
    {
        bSearch(arr, start, mid - 1, key);
    }
    // return false;
}
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i++)
    {
        if (!bSearch(nums, 0, nums.size() - 1, i))
            return i;
    }
    return -1;

    // APPROACH 2-------------------->>>>>>>>>>>>>>>>>>>>
    // unordered_map<int, int> mp;
    // for(int i = 0; i < nums.size(); i++){
    //     mp[nums[i]]++;
    // }
    // for(int i = 0; i <= nums.size(); i++){
    //     if(!mp[i]) return i;
    // }
    // return -1;
    
    int n = nums.size();

    // Approach 3--------------------->>>>>>>>>>>>>>>>
    // int sum = n*(n+1)/2;
    // for(int j = 0; j < n; j++){
    //     sum -= nums[j];
    // }
    // return sum;

    // Approach 4------------------>>>>>>>>>>>>>>>>>>>>>>
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = res ^ i;
    for (int i = 0; i < n; i++)
    {
        res = res ^ nums[i];
    }

    return res;
}

int main()
{
    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(arr);
    return 0;
}