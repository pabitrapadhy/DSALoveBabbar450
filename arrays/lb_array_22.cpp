#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using LL = long long;

LL MaximumProductSubarray(vector<int> const& arr) {
    int len{static_cast<int>(arr.size())};
    if (len == 1) {
        return arr[0];
    }

    LL maxProd{arr[0]};
    LL mini{arr[0]}, maxi{arr[0]};

    for (int i = 1; i < len; ++i) {
        LL item{static_cast<LL>(arr[i])};
        if (item < 0) {
            swap(mini, maxi);
        }

        maxi = max(maxi*item, item); // calculating new maxi
        mini = min(mini*item, item); // calculating new mini

        if (maxi > maxProd) { // updating maxProd
            maxProd = maxi;
        }

        if (item == 0) { // for the next item
            maxi = 1;
            mini = 1;
        }
    }

    return maxProd;
}

int main() {
    // vector<int> arr{-1,2,4,-3,0,1,7,7};
    // vector<int> arr{6,-3,-10,0,2};
    // vector<int> arr{2,3,4,5,-1,0};
    vector<int> arr{-1,0};
    cout << MaximumProductSubarray(arr);
}