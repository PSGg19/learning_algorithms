#include <iostream>
#include <vector>
using namespace std;

int findSecondLargest(const vector<int>& arr) {
    int largest = INT_MIN, second = INT_MIN;
    for (int num : arr) {
        if (num > largest) {
            second = largest;
            largest = num;
        } else if (num > second && num != largest) {
            second = num;
        }
    }
    return (second == INT_MIN) ? -1 : second;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int second = findSecondLargest(arr);
    if (second == -1)
        cout << "No second largest element.\n";
    else
        cout << "Second largest element is: " << second << endl;

    return 0;
}
