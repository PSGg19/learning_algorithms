#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int index = 1;
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i] != arr[i - 1])
            arr[index++] = arr[i];
    return index;
}

int main() {
    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int newSize = removeDuplicates(arr);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
