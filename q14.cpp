#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two elements that sum up to the target
bool twoSum(const vector<int>& arr, int target) {
    unordered_map<int, int> map;
    for (int num : arr) {
        int complement = target - num;
        if (map.find(complement) != map.end()) {
            cout << "Pair found: " << num << ", " << complement << endl;
            return true;
        }
        map[num] = 1;
    }
    return false;
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter target sum: ";
    cin >> target;

    if (!twoSum(arr, target))
        cout << "No pair found with the given sum." << endl;

    return 0;
}
