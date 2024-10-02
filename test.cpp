#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to find the maximum in each sliding window of size k
vector<int> slidingWindowMax(const vector<int>& arr, int k) {
    deque<int> dq;  // Deque to store indexes of elements in the window
    vector<int> result;

    for (int i = 0; i < arr.size(); ++i) {
        // Remove elements from the front if they are out of this window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove elements from the back while they are smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add the current element index at the back of the deque
        dq.push_back(i);

        // If the window has reached size k, add the front element of deque to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the size of sliding window (k): ";
    cin >> k;

    vector<int> result = slidingWindowMax(arr, k);

    cout << "Maximum values in each sliding window of size " << k << ":\n";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
