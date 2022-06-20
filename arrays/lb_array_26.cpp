#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* LEGENDS:
pibt = profit if bought today
mpibat = profit if bought today or sometime after today
pist = profit is sold today
mpistt = max profit if sold anytime till today including.
*/

int StockBuyAndSellAtmostTwice(vector<int> const& arr) {
    int len{static_cast<int>(arr.size())};
    if (len == 0) {
        return 0;
    }
    
    // 1. max profit from left
    int pist{}, mpistt{};
    int mini{arr[0]};
    vector<int> profitLeft{};
    profitLeft.push_back(0);

    for (int i = 1; i < len; ++i) {
        mini = min(mini, arr[i]);
        pist = arr[i]-mini;
        mpistt = max(pist, mpistt);
        profitLeft.push_back(mpistt);
    }

    // 2. max profit from right
    int pibt{}, mpibat{};
    int maxi{arr[len-1]};
    vector<int> profitRight{};
    profitRight.push_back(0);

    for (int i = len-2; i >= 0; --i) {
        maxi = max(maxi, arr[i]);
        pibt = maxi-arr[i];
        mpibat = max(pibt, mpibat);
        profitRight.push_back(mpibat);
    }

    // reverse the profitRight
    reverse(profitRight.begin(), profitRight.end());

    // 3. cumulative max profit for both transactions
    int maxProfit{}, sum{};
    for (int i = 0; i < len; ++i) {
        sum = profitLeft[i] + profitRight[i];
        maxProfit = max(maxProfit, sum);
    }

    return maxProfit;
}

int main() {
    // vector<int> arr{10,22,5,75,65,80}; // correct
    // vector<int> arr{2,30,15,10,8,25,80}; // correct
    // vector<int> arr{90,80,70,60,50}; // correct
    vector<int> arr{100,30,15,10,8,25,80}; // correct

    cout << StockBuyAndSellAtmostTwice(arr);
}