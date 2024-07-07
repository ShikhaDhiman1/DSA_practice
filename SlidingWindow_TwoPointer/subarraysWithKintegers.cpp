#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int ans = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp;

    while (r < nums.size())
    {
        for (int i = l; i < r; i++)
        {
            cout << nums[i] << " ";
        }
        cout << " -> " << ans << "\n";
        mp[nums[r]]++;

        while (mp.size() > k)
        {
            cout<<nums[l]<<"\n";
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            if (mp.size() > k){
            cout<<"grate\n";
                ans++;
            }
            l++;
        }

        if (mp.size() == k)
            ans++;

        r++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,2,1,2,2,3};
    int k = 2;
    cout<<subarraysWithKDistinct(nums, k)<<"\n";
    return 0;
}