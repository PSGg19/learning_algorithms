#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes(const vector<int>& arr) {
    int count = 0, maxCount = 0;
    for (int num : arr) {
        if (num == 1)
            count++;
        else
            count = 0;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main() {
    int n;
    cout << "Enter size of binary array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter binary elements (0 or 1): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Maximum consecutive 1s: " << maxConsecutiveOnes(arr) << endl;
    return 0;
}
