#include <iostream>
#include <vector>
using namespace std;

void rotateLeftByD(vector<int>& arr, int d) {
    d %= arr.size();  // Handle d > n
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n, d;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter number of positions to rotate (D): ";
    cin >> d;

    rotateLeftByD(arr, d);

    cout << "Array after rotating left by " << d << " places: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
