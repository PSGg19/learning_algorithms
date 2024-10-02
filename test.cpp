#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to implement Kadane's Algorithm
int kadane(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        currentSum += nums[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        // If current sum becomes negative, reset it
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxSubarraySum = kadane(arr);
    cout << "Maximum Subarray Sum is: " << maxSubarraySum << endl;

    return 0;
}
