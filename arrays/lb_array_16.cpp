#include<iostream>
#include<vector>

using namespace std;

int FindMaxProfit(vector<int> const& arr) {
    int len{static_cast<int>(arr.size())};
    if (len == 1) {
        return 0;
    }

    int purchasePrice{arr[0]};
    int profit{}, maxProfit{};

    for (int i = 1; i < len; ++i) {
        int sellPrice{arr[i]};
        if (sellPrice < purchasePrice) {
            purchasePrice = arr[i];
        }

        profit = sellPrice - purchasePrice;
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main() {
    vector<int> arr{7,1,5,3,6,4};
    vector<int> arr{7,3,5,6,2,4};
    cout << FindMaxProfit(arr);
}