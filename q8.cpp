#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> findUnion(const vector<int>& a, const vector<int>& b) {
    set<int> s(a.begin(), a.end());
    s.insert(b.begin(), b.end());
    return vector<int>(s.begin(), s.end());
}

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; ++i)
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; ++i)
        cin >> b[i];

    vector<int> unionArr = findUnion(a, b);

    cout << "Union of arrays: ";
    for (int num : unionArr)
        cout << num << " ";
    cout << endl;

    return 0;
}
