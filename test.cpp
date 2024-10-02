#include <iostream>
#include <vector>
using namespace std;

// Function to compute the prefix sum array
vector<int> computePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n + 1, 0);

    // Calculating prefix sum array where prefixSum[i] = sum of elements from arr[0] to arr[i-1]
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    return prefixSum;
}

// Function to get sum of elements in range [L, R] using prefix sum
int getRangeSum(const vector<int>& prefixSum, int L, int R) {
    return prefixSum[R + 1] - prefixSum[L];
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

    // Compute prefix sum array
    vector<int> prefixSum = computePrefixSum(arr);

    // Answering queries
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int L, R;
        cout << "Enter range (L, R): ";
        cin >> L >> R;
        cout << "Sum of elements in range [" << L << ", " << R << "] is: " << getRangeSum(prefixSum, L, R) << endl;
    }

    return 0;
}
