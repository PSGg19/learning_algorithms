#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    nextPermutation(arr);

    cout << "Next permutation: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
