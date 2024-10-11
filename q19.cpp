#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rearrangeAlternating(vector<int>& arr) {
    vector<int> positive, negative;
    for (int num : arr) {
        if (num >= 0) positive.push_back(num);
        else negative.push_back(num);
    }

    int i = 0, j = 0, k = 0;
    while (i < positive.size() && j < negative.size()) {
        arr[k++] = positive[i++];
        arr[k++] = negative[j++];
    }

    // Adding remaining elements
    while (i < positive.size()) arr[k++] = positive[i++];
    while (j < negative.size()) arr[k++] = negative[j++];
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    rearrangeAlternating(arr);

    cout << "Rearranged array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
