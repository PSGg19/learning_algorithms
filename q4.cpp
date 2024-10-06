#include <iostream>
#include <vector>
using namespace std;

void leftRotateByOne(vector<int>& arr) {
    int first = arr[0];
    for (int i = 1; i < arr.size(); ++i)
        arr[i - 1] = arr[i];
    arr[arr.size() - 1] = first;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    leftRotateByOne(arr);

    cout << "Array after left rotation by 1: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
