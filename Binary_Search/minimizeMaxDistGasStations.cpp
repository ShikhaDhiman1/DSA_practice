#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the
X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
Find the minimum value of ‘dist’.
Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216.
Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.*/

long double minimizeMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howManyBetween(n - 1, 0);

    for (int gStations = 1; gStations <= k; gStations++)
    {
        long double maxSection = -1;
        int maxIndex = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double totalDist = arr[i + 1] - arr[i];
            long double sectionLength = totalDist / ((long double)howManyBetween[i] + 1);

            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxIndex = i;
            }
        }
        howManyBetween[maxIndex]++;
    }

    long double maxDist = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double totalDistance = arr[i + 1] - arr[i];
        long double sectionLength = totalDistance / ((long double)howManyBetween[i] + 1);
        maxDist = max(maxDist, sectionLength);
    }

    return maxDist;
}

long double minimizeMaxDistance2(vector<int> &arr, int k){
    priority_queue<pair<long double, int>> pq;
    vector<int> howManyBetween(arr.size()-1, 0);

    for(int i = 0; i < arr.size()-1; i++){
        pq.push({arr[i + 1] - arr[i], i});
    }

    for(int gStations = 1; gStations <= k; gStations++){
        auto tp = pq.top();
        pq.pop();
        int sectionIndex = tp.second;

        // insert gas station
        howManyBetween[sectionIndex]++;

        long double initialSectionLen = arr[sectionIndex + 1] - arr[sectionIndex];
        long double newSectionLen = initialSectionLen/((long double)(howManyBetween[sectionIndex] + 1));

        // modify section length at section index after inserting new gas satation
        pq.push({newSectionLen, sectionIndex});
    }

    return pq.top().first;
}

int numberOfStationsRequired(vector<int> &arr, long double dist){
    int count = 0;

    for(int i = 0; i < arr.size() - 1; i++){
        int numberInBetween = (arr[i + 1] - arr[i])/dist;
        if((arr[i + 1] - arr[i]) == (numberInBetween * dist)){
            numberInBetween--;
        }
        count += numberInBetween;
    }
    return count;
}

long double minimizeMaxDistance3(vector<int> &arr, int k){
    long double low = 0;
    long double high = 0;

    for(int i = 0; i < arr.size() - 1; i++){
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high)/(2.0);

        int count = numberOfStationsRequired(arr, mid);

        if(count > k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << minimizeMaxDistance(arr, k) << "\n";
    cout << minimizeMaxDistance2(arr, k) << "\n";
    cout << minimizeMaxDistance3(arr, k) << "\n";
    return 0;
}