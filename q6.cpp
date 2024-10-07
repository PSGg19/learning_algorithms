#include <iostream>
#include <vector>
using namespace std;

void moveZerosToEnd(vector<int>& arr) {
    int nonZeroIndex = 0;
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != 0)
            swap(arr[i], arr[nonZeroIndex++]);
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (with zeros): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    moveZerosToEnd(arr);

    cout << "Array after moving zeros to end: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
