#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const vector<int>& arr, int n) {
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int num : arr)
        sum += num;
    return total - sum;
}

int main() {
    int n;
    cout << "Enter value of N (1 to N): ";
    cin >> n;
    vector<int> arr(n - 1);
    cout << "Enter " << n - 1 << " elements: ";
    for (int i = 0; i < n - 1; ++i)
        cin >> arr[i];

    cout << "Missing number is: " << findMissingNumber(arr, n) << endl;
    return 0;
}
