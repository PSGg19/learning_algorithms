#include <iostream>
#include <vector>
using namespace std;

int stockBuySell(const vector<int>& prices) {
    int n = prices.size();
    int profit = 0;
    for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter stock prices for each day: ";
    for (int i = 0; i < n; ++i)
        cin >> prices[i];

    cout << "Maximum profit: " << stockBuySell(prices) << endl;
    return 0;
}
