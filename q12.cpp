#include <iostream>
#include <vector>
using namespace std;

int longestSubarraySumK(const vector<int>& arr, int k) {
    int i = 0, j = 0, sum = 0, maxLen = 0;
    while (j < arr.size()) {
        sum += arr[j];
        while (sum > k)
            sum -= arr[i++];
        if (sum == k)
            maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements (positive integers): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter target sum K: ";
    cin >> k;

    cout << "Longest subarray length with sum " << k << " is: " << longestSubarraySumK(arr, k) << endl;
    return 0;
}
