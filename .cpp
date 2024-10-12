1 Next Permutation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
int n = nums.size();
int i = n - 2;

while (i >= 0 && nums[i] >= nums[i + 1]) {
i--;
}

if (i >= 0) {
int j = n - 1;

while (nums[j] <= nums[i]) {
j--;
}

swap(nums[i], nums[j]);
}

reverse(nums.begin() + i + 1, nums.end());
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i)
cin >> nums[i];

nextPermutation(nums);

cout << "Next permutation: ";
for (int i = 0; i < n; ++i)
cout << nums[i] << " ";
cout << endl;

return 0;
}

2 Leaders in an Array
#include <iostream>
#include <vector>
using namespace std;

void findLeaders(const vector<int>& arr) {
int n = arr.size();
int maxFromRight = arr[n - 1];
cout << maxFromRight << " ";

for (int i = n - 2; i >= 0; --i) {
if (arr[i] > maxFromRight) {
cout << arr[i] << " ";
maxFromRight = arr[i];
}
}
}

int main() {
int n;
cout << "Enter size of array: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i)
cin >> arr[i];

cout << "Leaders in the array: ";
findLeaders(arr);
cout << endl;

return 0;
}

3 Longest Consecutive Sequence in an Array
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
unordered_set<int> s(nums.begin(), nums.end());
int longestStreak = 0;

for (int num : nums) {
if (s.find(num - 1) == s.end()) {
int currentNum = num;
int currentStreak = 1;

while (s.find(currentNum + 1) != s.end()) {
currentNum++;
currentStreak++;
}

longestStreak = max(longestStreak, currentStreak);
}
}

return longestStreak;
}

int main() {
int n;
cout << "Enter size of array: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i)
cin >> nums[i];

cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << endl;

return 0;
}
4 Set Matrix Zeros
#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
bool rowZero = false, colZero = false;

for (int i = 0; i < matrix.size(); ++i) {
if (matrix[i][0] == 0) {
colZero = true;
}
}

for (int j = 0; j < matrix[0].size(); ++j) {
if (matrix[0][j] == 0) {
rowZero = true;
}
}

for (int i = 1; i < matrix.size(); ++i) {
for (int j = 1; j < matrix[0].size(); ++j) {
if (matrix[i][j] == 0) {
matrix[i][0] = matrix[0][j] = 0;
}
}
}

for (int i = 1; i < matrix.size(); ++i) {
for (int j = 1; j < matrix[0].size(); ++j) {
if (matrix[i][0] == 0 || matrix[0][j] == 0) {
matrix[i][j] = 0;
}
}
}

if (rowZero) {
for (int j = 0; j < matrix[0].size(); ++j) {
matrix[0][j] = 0;
}
}

if (colZero) {
for (int i = 0; i < matrix.size(); ++i) {
matrix[i][0] = 0;
}
}
}

int main() {
int m, n;
cout << "Enter matrix dimensions: ";
cin >> m >> n;
vector<vector<int>> matrix(m, vector<int>(n));
cout << "Enter elements: ";
for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
cin >> matrix[i][j];
}
}

setZeroes(matrix);

cout << "Matrix after setting zeroes: \n";
for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
cout << matrix[i][j] << " ";
}
cout << endl;
}

return 0;
}

5 Rotate Matrix by 90 degrees
#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
int n = matrix.size();

// Transpose the matrix
for (int i = 0; i < n; ++i) {
for (int j = i; j < n; ++j) {
swap(matrix[i][j], matrix[j][i]);
}
}

// Reverse each row
for (int i = 0; i < n; ++i) {
reverse(matrix[i].begin(), matrix[i].end());
}
}

int main() {
int n;
cout << "Enter matrix dimensions: ";
cin >> n;
vector<vector<int>> matrix(n, vector<int>(n));
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
cin >> matrix[i][j];
}
}

rotateMatrix(matrix);

cout << "Matrix after 90 degree rotation: \n";
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
cout << matrix[i][j] << " ";
}
cout << endl;
}

return 0;
}

6 Print the matrix in spiral manner
#include <iostream>
#include <vector>
using namespace std;

void printSpiralOrder(const vector<vector<int>>& matrix) {
int top = 0, bottom = matrix.size() - 1;
int left = 0, right = matrix[0].size() - 1;

while (top <= bottom && left <= right) {
// Print top row
for (int i = left; i <= right; ++i) {
cout << matrix[top][i] << " ";
}
top++;

// Print right column
for (int i = top; i <= bottom; ++i) {
cout << matrix[i][right] << " ";
}
right--;

if (top <= bottom) {
// Print bottom row
for (int i = right; i >= left; --i) {
cout << matrix[bottom][i] << " ";
}
bottom--;
}

if (left <= right) {
// Print left column
for (int i = bottom; i >= top; --i) {
cout << matrix[i][left] << " ";
}
left++;
}
}
}

int main() {
int m, n;
cout << "Enter matrix dimensions: ";
cin >> m >> n;
vector<vector<int>> matrix(m, vector<int>(n));
cout << "Enter elements: ";
for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
cin >> matrix[i][j];
}
}

cout << "Matrix in spiral order: ";
printSpiralOrder(matrix);
cout << endl;

return 0;
}

7 Count subarrays with given sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithSum(const vector<int>& nums, int target) {
unordered_map<int, int> sumCount;
sumCount[0] = 1;
int currentSum = 0, result = 0;

for (int num : nums) {
currentSum += num;
if (sumCount.find(currentSum - target) != sumCount.end()) {
result += sumCount[currentSum - target];
}
sumCount[currentSum]++;
}

return result;
}

int main() {
int n, target;
cout << "Enter size of array: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) {
cin >> nums[i];
}
cout << "Enter target sum: ";
cin >> target;

cout << "Number of subarrays with given sum: " << subarraysWithSum(nums, target) << endl;

return 0;
}
8. Count Inversions in an Array
#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int right) {
if (left >= right) return 0;

int mid = left + (right - left) / 2;
int invCount = mergeAndCount(arr, left, mid);
invCount += mergeAndCount(arr, mid + 1, right);
invCount += merge(arr, left, mid, right);

return invCount;
}

int merge(vector<int>& arr, int left, int mid, int right) {
int invCount = 0;
int n1 = mid - left + 1;
int n2 = right - mid;

vector<int> leftArr(n1), rightArr(n2);
for (int i = 0; i < n1; ++i) leftArr[i] = arr[left + i];
for (int i = 0; i < n2; ++i) rightArr[i] = arr[mid + 1 + i];

int i = 0, j = 0, k = left;
while (i < n1 && j < n2) {
if (leftArr[i] <= rightArr[j]) {
arr[k++] = leftArr[i++];
} else {
arr[k++] = rightArr[j++];
invCount += (n1 - i);
}
}

while (i < n1) arr[k++] = leftArr[i++];
while (j < n2) arr[k++] = rightArr[j++];

return invCount;
}

int main() {
int n;
cout << "Enter size of array: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Number of inversions: " << mergeAndCount(arr, 0, n - 1) << endl;

return 0;
}

9. Search in Rotated Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int>& nums, int target) {
int left = 0, right = nums.size() - 1;

while (left <= right) {
int mid = left + (right - left) / 2;

if (nums[mid] == target) return mid;

if (nums[left] <= nums[mid]) {
if (nums[left] <= target && target < nums[mid]) {
right = mid - 1;
} else {
left = mid + 1;
}
} else {
if (nums[mid] < target && target <= nums[right]) {
left = mid + 1;
} else {
right = mid - 1;
}
}
}

return -1;
}

int main() {
int n, target;
cout << "Enter size of array: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];
cout << "Enter target: ";
cin >> target;

cout << "Index of target: " << search(nums, target) << endl;

return 0;
}

10. Find Peak Element
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int>& nums) {
int left = 0, right = nums.size() - 1;

while (left < right) {
int mid = left + (right - left) / 2;

if (nums[mid] < nums[mid + 1]) {
left = mid + 1;
} else {
right = mid;
}
}

return left;
}

int main() {
int n;
cout << "Enter size of array: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];

cout << "Peak element index: " << findPeakElement(nums) << endl;

return 0;
}

11. Merge Intervals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
if (intervals.empty()) return {};

sort(intervals.begin(), intervals.end());
vector<vector<int>> merged;

merged.push_back(intervals[0]);

for (int i = 1; i < intervals.size(); ++i) {
if (merged.back()[1] >= intervals[i][0]) {
merged.back()[1] = max(merged.back()[1], intervals[i][1]);
} else {
merged.push_back(intervals[i]);
}
}

return merged;
}

int main() {
int n;
cout << "Enter number of intervals: ";
cin >> n;
vector<vector<int>> intervals(n, vector<int>(2));
cout << "Enter intervals: ";
for (int i = 0; i < n; ++i) {
cin >> intervals[i][0] >> intervals[i][1];
}

vector<vector<int>> merged = mergeIntervals(intervals);

cout << "Merged intervals: \n";
for (const auto& interval : merged) {
cout << "[" << interval[0] << ", " << interval[1] << "] ";
}
cout << endl;

return 0;
}
12. Rotate Matrix by 90 Degrees
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
int n = matrix.size();

// Transpose the matrix
for (int i = 0; i < n; ++i) {
for (int j = i + 1; j < n; ++j) {
swap(matrix[i][j], matrix[j][i]);
}
}

// Reverse each row
for (int i = 0; i < n; ++i) {
reverse(matrix[i].begin(), matrix[i].end());
}
}

int main() {
int n;
cout << "Enter size of matrix: ";
cin >> n;
vector<vector<int>> matrix(n, vector<int>(n));
cout << "Enter elements of matrix: ";
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
cin >> matrix[i][j];
}
}

rotate(matrix);

cout << "Rotated matrix: \n";
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
cout << matrix[i][j] << " ";
}
cout << endl;
}

return 0;
}

13. Find the Majority Element
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
unordered_map<int, int> freq;
for (int num : nums) {
if (++freq[num] > nums.size() / 2) {
return num;
}
}
return -1;
}

int main() {
int n;
cout << "Enter size of array: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];

cout << "Majority element: " << majorityElement(nums) << endl;

return 0;
}

14. Subarray with Given Sum
#include <iostream>
#include <vector>
using namespace std;

bool subarraySum(const vector<int>& arr, int sum) {
int currentSum = 0;
unordered_map<int, int> prefixSum;

for (int i = 0; i < arr.size(); ++i) {
currentSum += arr[i];

if (currentSum == sum || prefixSum[currentSum - sum]) {
return true;
}

prefixSum[currentSum] = 1;
}

return false;
}

int main() {
int n, sum;
cout << "Enter size of array: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];
cout << "Enter target sum: ";
cin >> sum;

cout << "Subarray with given sum exists: " << (subarraySum(arr, sum) ? "Yes" : "No") << endl;

return 0;
}
15. Pascal's Triangle
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
vector<vector<int>> result(numRows);
for (int i = 0; i < numRows; ++i) {
result[i].resize(i + 1);
result[i][0] = result[i][i] = 1;  // First and last elements are 1

for (int j = 1; j < i; ++j) {
result[i][j] = result[i - 1][j - 1] + result[i - 1][j];  // Each element is the sum of the two above it
}
}
return result;
}

void printPascal(const vector<vector<int>>& triangle) {
for (const auto& row : triangle) {
for (int num : row) {
cout << num << " ";
}
cout << endl;
}
}

int main() {
int numRows;
cout << "Enter the number of rows: ";
cin >> numRows;

vector<vector<int>> triangle = generate(numRows);
printPascal(triangle);

return 0;
}

16. Majority Element (n/3 times)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
unordered_map<int, int> countMap;
int n = nums.size();
vector<int> result;

for (int num : nums) {
countMap[num]++;
}

for (auto& pair : countMap) {
if (pair.second > n / 3) {
result.push_back(pair.first);
}
}
return result;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];

vector<int> majority = majorityElement(nums);
cout << "Majority elements (n/3 times): ";
for (int num : majority) {
cout << num << " ";
}
cout << endl;

return 0;
}

17. 3-Sum Problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
vector<vector<int>> result;
sort(nums.begin(), nums.end());

for (int i = 0; i < nums.size(); ++i) {
if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates
int target = -nums[i];
int left = i + 1, right = nums.size() - 1;

while (left < right) {
if (nums[left] + nums[right] == target) {
result.push_back({nums[i], nums[left], nums[right]});
while (left < right && nums[left] == nums[left + 1]) ++left;  // Skip duplicates
while (left < right && nums[right] == nums[right - 1]) --right;  // Skip duplicates
++left;
--right;
}
else if (nums[left] + nums[right] < target) ++left;
else --right;
}
}
return result;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];

vector<vector<int>> result = threeSum(nums);
cout << "Triplets that sum to 0: ";
for (const auto& triplet : result) {
for (int num : triplet) {
cout << num << " ";
}
cout << endl;
}

return 0;
}

18. 4-Sum Problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
vector<vector<int>> result;
sort(nums.begin(), nums.end());

for (int i = 0; i < nums.size(); ++i) {
if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates
for (int j = i + 1; j < nums.size(); ++j) {
if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates
int left = j + 1, right = nums.size() - 1;

while (left < right) {
int sum = nums[i] + nums[j] + nums[left] + nums[right];
if (sum == target) {
result.push_back({nums[i], nums[j], nums[left], nums[right]});
while (left < right && nums[left] == nums[left + 1]) ++left;  // Skip duplicates
while (left < right && nums[right] == nums[right - 1]) --right;  // Skip duplicates
++left;
--right;
}
else if (sum < target) ++left;
else --right;
}
}
}
return result;
}

int main() {
int n, target;
cout << "Enter number of elements: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];
cout << "Enter target sum: ";
cin >> target;

vector<vector<int>> result = fourSum(nums, target);
cout << "Quadruplets that sum to target: ";
for (const auto& quadruplet : result) {
for (int num : quadruplet) {
cout << num << " ";
}
cout << endl;
}

return 0;
}

19. Largest Subarray with 0 Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLen(const vector<int>& arr) {
unordered_map<int, int> sumIndexMap;
int sum = 0, maxLength = 0;

for (int i = 0; i < arr.size(); ++i) {
sum += arr[i];

if (sum == 0) {
maxLength = i + 1;
}
else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
maxLength = max(maxLength, i - sumIndexMap[sum]);
}
else {
sumIndexMap[sum] = i;
}
}
return maxLength;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Length of largest subarray with sum 0: " << maxLen(arr) << endl;

return 0;
}
20. Count number of subarrays with given xor K
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysWithXorK(const vector<int>& arr, int K) {
unordered_map<int, int> xorCountMap;
int xorSum = 0, count = 0;

for (int num : arr) {
xorSum ^= num;

if (xorSum == K) {
count++;
}

if (xorCountMap.find(xorSum ^ K) != xorCountMap.end()) {
count += xorCountMap[xorSum ^ K];
}

xorCountMap[xorSum]++;
}

return count;
}

int main() {
int n, K;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];
cout << "Enter value of K: ";
cin >> K;

cout << "Count of subarrays with given XOR " << K << ": " << countSubarraysWithXorK(arr, K) << endl;

return 0;
}

21. Merge Overlapping Subintervals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
if (intervals.empty()) return {};

sort(intervals.begin(), intervals.end());
vector<vector<int>> merged;

merged.push_back(intervals[0]);

for (int i = 1; i < intervals.size(); ++i) {
if (merged.back()[1] >= intervals[i][0]) {
merged.back()[1] = max(merged.back()[1], intervals[i][1]);
} else {
merged.push_back(intervals[i]);
}
}

return merged;
}

int main() {
int n;
cout << "Enter number of intervals: ";
cin >> n;
vector<vector<int>> intervals(n, vector<int>(2));
cout << "Enter intervals (start and end): ";
for (int i = 0; i < n; ++i) {
cin >> intervals[i][0] >> intervals[i][1];
}

vector<vector<int>> merged = mergeIntervals(intervals);
cout << "Merged intervals: ";
for (const auto& interval : merged) {
cout << "[" << interval[0] << ", " << interval[1] << "] ";
}
cout << endl;

return 0;
}

22. Merge two sorted arrays without extra space
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArraysWithoutExtraSpace(vector<int>& arr1, vector<int>& arr2) {
int n = arr1.size(), m = arr2.size();
int i = n - 1, j = 0;

while (i >= 0 && j < m) {
if (arr1[i] > arr2[j]) {
swap(arr1[i], arr2[j]);
}
i--;
j++;
}

sort(arr1.begin(), arr1.end());
sort(arr2.begin(), arr2.end());
}

int main() {
int n, m;
cout << "Enter number of elements in first array: ";
cin >> n;
vector<int> arr1(n);
cout << "Enter elements of first array: ";
for (int i = 0; i < n; ++i) cin >> arr1[i];

cout << "Enter number of elements in second array: ";
cin >> m;
vector<int> arr2(m);
cout << "Enter elements of second array: ";
for (int i = 0; i < m; ++i) cin >> arr2[i];

mergeArraysWithoutExtraSpace(arr1, arr2);

cout << "Merged arrays: ";
for (int num : arr1) cout << num << " ";
for (int num : arr2) cout << num << " ";
cout << endl;

return 0;
}

23. Find the repeating and missing number
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findRepeatingAndMissingNumber(const vector<int>& nums) {
int n = nums.size();
int sum = 0, sumSquares = 0;
int expectedSum = (n * (n + 1)) / 2;
int expectedSumSquares = (n * (n + 1) * (2 * n + 1)) / 6;

for (int num : nums) {
sum += num;
sumSquares += num * num;
}

int diff = expectedSum - sum;
int diffSquares = expectedSumSquares - sumSquares;

int missingNumber = (diff + (diffSquares / diff)) / 2;
int repeatingNumber = missingNumber - diff;

return {repeatingNumber, missingNumber};
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];

pair<int, int> result = findRepeatingAndMissingNumber(nums);
cout << "Repeating number: " << result.first << ", Missing number: " << result.second << endl;

return 0;
}

24. Count Inversions
#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int right) {
if (left >= right) return 0;

int mid = left + (right - left) / 2;
int invCount = mergeAndCount(arr, left, mid) + mergeAndCount(arr, mid + 1, right);

invCount += merge(arr, left, mid, right);

return invCount;
}

int merge(vector<int>& arr, int left, int mid, int right) {
int invCount = 0;
int n1 = mid - left + 1;
int n2 = right - mid;
vector<int> L(n1), R(n2);

for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

int i = 0, j = 0, k = left;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
invCount += (n1 - i);
j++;
}
k++;
}

while (i < n1) {
arr[k] = L[i];
i++;
k++;
}

while (j < n2) {
arr[k] = R[j];
j++;
k++;
}

return invCount;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Number of inversions: " << mergeAndCount(arr, 0, n - 1) << endl;

return 0;
}
25. Reverse Pairs
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int right) {
if (left >= right) return 0;

int mid = left + (right - left) / 2;
int invCount = mergeAndCount(arr, left, mid) + mergeAndCount(arr, mid + 1, right);

invCount += merge(arr, left, mid, right);

return invCount;
}

int merge(vector<int>& arr, int left, int mid, int right) {
int invCount = 0;
int n1 = mid - left + 1;
int n2 = right - mid;
vector<int> L(n1), R(n2);

for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

int i = 0, j = 0, k = left;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
invCount += (n1 - i);
j++;
}
k++;
}

while (i < n1) {
arr[k] = L[i];
i++;
k++;
}

while (j < n2) {
arr[k] = R[j];
j++;
k++;
}

return invCount;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Number of inversions: " << mergeAndCount(arr, 0, n - 1) << endl;

return 0;
}

26. Maximum Product Subarray
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(const vector<int>& nums) {
int n = nums.size();
int maxProduct = nums[0], minProduct = nums[0], result = nums[0];

for (int i = 1; i < n; ++i) {
if (nums[i] < 0) swap(maxProduct, minProduct);

maxProduct = max(nums[i], maxProduct * nums[i]);
minProduct = min(nums[i], minProduct * nums[i]);

result = max(result, maxProduct);
}

return result;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> nums(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> nums[i];

cout << "Maximum product subarray: " << maxProduct(nums) << endl;

return 0;
}
27 Binary Search to find X in sorted array
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) return mid;
if (arr[mid] < x) low = mid + 1;
else high = mid - 1;
}
return -1;  // X not found
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to search: ";
cin >> x;

int result = binarySearch(arr, x);
if (result != -1) cout << "Element found at index " << result << endl;
else cout << "Element not found" << endl;

return 0;
}

28 Implement Lower Bound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(const vector<int>& arr, int x) {
int low = 0, high = arr.size();
while (low < high) {
int mid = low + (high - low) / 2;
if (arr[mid] < x) low = mid + 1;
else high = mid;
}
return low;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to find lower bound: ";
cin >> x;

int index = lowerBound(arr, x);
cout << "Lower bound index: " << index << endl;

return 0;
}

29 Implement Upper Bound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upperBound(const vector<int>& arr, int x) {
int low = 0, high = arr.size();
while (low < high) {
int mid = low + (high - low) / 2;
if (arr[mid] <= x) low = mid + 1;
else high = mid;
}
return low;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to find upper bound: ";
cin >> x;

int index = upperBound(arr, x);
cout << "Upper bound index: " << index << endl;

return 0;
}

30 Search Insert Position
#include <iostream>
#include <vector>
using namespace std;

int searchInsertPosition(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) return mid;
if (arr[mid] < x) low = mid + 1;
else high = mid - 1;
}
return low;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to insert: ";
cin >> x;

int result = searchInsertPosition(arr, x);
cout << "Insert position: " << result << endl;

return 0;
}

31 Floor/Ceil in Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int floorCeil(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1;
int floorVal = -1, ceilVal = -1;

while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) {
floorVal = arr[mid];
ceilVal = arr[mid];
break;
}
else if (arr[mid] < x) {
floorVal = arr[mid];
low = mid + 1;
}
else {
ceilVal = arr[mid];
high = mid - 1;
}
}

cout << "Floor: " << floorVal << ", Ceil: " << ceilVal << endl;
return 0;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to find floor and ceil: ";
cin >> x;

floorCeil(arr, x);

return 0;
}
32 Find the first or last occurrence of a given number in a sorted array
#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1, first = -1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) {
first = mid;
high = mid - 1;
} else if (arr[mid] < x) low = mid + 1;
else high = mid - 1;
}
return first;
}

int findLastOccurrence(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1, last = -1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) {
last = mid;
low = mid + 1;
} else if (arr[mid] < x) low = mid + 1;
else high = mid - 1;
}
return last;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to find first and last occurrence: ";
cin >> x;

int first = findFirstOccurrence(arr, x);
int last = findLastOccurrence(arr, x);

cout << "First occurrence: " << first << ", Last occurrence: " << last << endl;
return 0;
}

33 Count occurrences of a number in a sorted array with duplicates
#include <iostream>
#include <vector>
using namespace std;

int countOccurrences(const vector<int>& arr, int x) {
int first = findFirstOccurrence(arr, x);
if (first == -1) return 0;
int last = findLastOccurrence(arr, x);
return last - first + 1;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to count occurrences: ";
cin >> x;

int result = countOccurrences(arr, x);
cout << "Occurrences: " << result << endl;

return 0;
}

34 Search in Rotated Sorted Array I
#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) return mid;

if (arr[low] <= arr[mid]) {
if (arr[low] <= x && x < arr[mid]) high = mid - 1;
else low = mid + 1;
} else {
if (arr[mid] < x && x <= arr[high]) low = mid + 1;
else high = mid - 1;
}
}
return -1;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to search: ";
cin >> x;

int result = searchInRotatedArray(arr, x);
if (result != -1) cout << "Element found at index " << result << endl;
else cout << "Element not found" << endl;

return 0;
}

35 Search in Rotated Sorted Array II
#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArrayII(const vector<int>& arr, int x) {
int low = 0, high = arr.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == x) return mid;

if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
low++;
high--;
} else if (arr[low] <= arr[mid]) {
if (arr[low] <= x && x < arr[mid]) high = mid - 1;
else low = mid + 1;
} else {
if (arr[mid] < x && x <= arr[high]) low = mid + 1;
else high = mid - 1;
}
}
return -1;
}

int main() {
int n, x;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Enter element to search: ";
cin >> x;

int result = searchInRotatedArrayII(arr, x);
if (result != -1) cout << "Element found at index " << result << endl;
else cout << "Element not found" << endl;

return 0;
}
36 Find minimum in Rotated Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int findMinInRotatedArray(const vector<int>& arr) {
int low = 0, high = arr.size() - 1;
while (low < high) {
int mid = low + (high - low) / 2;
if (arr[mid] > arr[high]) low = mid + 1;
else high = mid;
}
return arr[low];
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Minimum element in rotated array: " << findMinInRotatedArray(arr) << endl;

return 0;
}

37 Find out how many times has an array been rotated
#include <iostream>
#include <vector>
using namespace std;

int findRotationCount(const vector<int>& arr) {
int low = 0, high = arr.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] <= arr[high]) high = mid - 1;
else low = mid + 1;
}
return low;
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Array has been rotated " << findRotationCount(arr) << " times." << endl;

return 0;
}

38 Single element in a Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int findSingleElement(const vector<int>& arr) {
int low = 0, high = arr.size() - 1;
while (low < high) {
int mid = low + (high - low) / 2;
if (mid % 2 == 0) {
if (arr[mid] == arr[mid + 1]) low = mid + 2;
else high = mid;
} else {
if (arr[mid] == arr[mid - 1]) low = mid + 1;
else high = mid - 1;
}
}
return arr[low];
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Single element: " << findSingleElement(arr) << endl;

return 0;
}

39 Find peak element
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int>& arr) {
int low = 0, high = arr.size() - 1;
while (low < high) {
int mid = low + (high - low) / 2;
if (arr[mid] < arr[mid + 1]) low = mid + 1;
else high = mid;
}
return arr[low];
}

int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter elements: ";
for (int i = 0; i < n; ++i) cin >> arr[i];

cout << "Peak element: " << findPeakElement(arr) << endl;

return 0;
}