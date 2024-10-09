#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarraySumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixMap;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (sum == k)
            maxLen = i + 1;
        if (prefixMap.find(sum - k) != prefixMap.end())
            maxLen = max(maxLen, i - prefixMap[sum - k]);
        if (prefixMap.find(sum) == prefixMap.end())
            prefixMap[sum] = i;
    }
    return maxLen;
}

int main() {
    int n, k;
    //cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (can be negative/positive): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter target sum K: ";
    cin >> k;

    cout << "Longest subarray length with sum " << k << " is: " << longestSubarraySumK(arr, k) << endl;
    return 0;
}
