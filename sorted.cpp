#include <iostream>
#include <vector>
using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << (isSorted(arr) ? "Array is sorted." : "Array is not sorted.") << endl;
    return 0;
}
