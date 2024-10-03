#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    // Sort intervals based on the starting point of each interval
    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;

    for (auto& interval : intervals) {
        // If the merged vector is empty or there's no overlap
        if (merged.empty() || merged.back().second < interval.first) {
            merged.push_back(interval);
        } else {
            // Merge overlapping intervals
            merged.back().second = max(merged.back().second, interval.second);
        }
    }

    return merged;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<pair<int, int>> intervals(n);
    cout << "Enter " << n << " intervals (start and end):\n";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<pair<int, int>> merged = mergeIntervals(intervals);

    cout << "Merged intervals:\n";
    for (auto& interval : merged) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;

    return 0;
}
