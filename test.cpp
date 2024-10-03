#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find if there exists a pair with a given sum using Two Pointer Technique
bool hasPairWithSum(const vector<int>& arr, int target) {
    int left = 0;           // Initialize the left pointer
    int right = arr.size() - 1; // Initialize the right pointer

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        // If the current sum is equal to the target, return true
        if (currentSum == target) {
            return true;
        }
        // If current sum is less than the target, move the left pointer rightward
        else if (currentSum < target) {
            left++;
        }
        // If current sum is greater than the target, move the right pointer leftward
        else {
            right--;
        }
    }

    return false; // No pair found
}

int main() {
    int n, target;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    if (hasPairWithSum(arr, target)) {
        cout << "Yes, there is a pair with the given sum.\n";
    } else {
        cout << "No, there is no pair with the given sum.\n";
    }

    return 0;
}
