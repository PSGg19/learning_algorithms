#include <iostream>
#include <vector>
using namespace std;

int findSingleNumber(const vector<int>& arr) {
    int result = 0;
    for (int num : arr)
        result ^= num;
    return result;
}

int main() {
    int n;
    cout << "Enter number of elements (odd count): ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (all elements twice, one appears once): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Unique number is: " << findSingleNumber(arr) << endl;
    return 0;
}
