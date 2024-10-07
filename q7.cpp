#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] == key)
            return i;
    return -1;
}

int main() {
    int n, key;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;

    int index = linearSearch(arr, key);
    if (index == -1)
        cout << "Element not found.\n";
    else
        cout << "Element found at index: " << index << endl;

    return 0;
}
