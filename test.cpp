#include <iostream>
#include <vector>
using namespace std;

int findLargest(const vector<int>& arr) {
    int largest = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Largest element is: " << findLargest(arr) << endl;
    return 0;
}
