#include <iostream>
#include <vector>
using namespace std;

int majorityElement(const vector<int>& arr) {
    int count = 0, candidate = -1;
    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (candidate == num) {
            count++;
        } else {
            count--;
        }
    }

    // Verifying if candidate is really the majority element
    count = 0;
    for (int num : arr) {
        if (num == candidate)
            count++;
    }
    return (count > arr.size() / 2) ? candidate : -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int result = majorityElement(arr);
    if (result == -1)
        cout << "No majority element found." << endl;
    else
        cout << "Majority element is: " << result << endl;

    return 0;
}
