#include <iostream>
#include <vector>
using namespace std;

void printMaxSubarray(const vector<int>& arr) {
    int maxSum = arr[0], currentSum = arr[0];
    int start = 0, end = 0, tempStart = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > currentSum + arr[i]) {
            currentSum = arr[i];
            tempStart = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Maximum subarray sum: " << maxSum << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    printMaxSubarray(arr);
    return 0;
}
