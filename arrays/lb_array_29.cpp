#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long RainWaterTrapping(vector<int> const& arr) {
    int len{static_cast<int>(arr.size())};
    if (len < 3) { // atleast 3 buildings are required to trap any water
        return 0;
    }

    int maxLeft{}, maxRight{};
    vector<int> left{}, right{}, heights{};

    // max element to left of arr[i]
    for (int i = 0; i < len; ++i) {
        left.push_back(maxLeft);
        maxLeft = max(maxLeft, arr[i]);
    }
    // max element to right of arr[i]
    for (int i = len-1; i >= 0; --i) {
        right.push_back(maxRight);
        maxRight = max(maxRight, arr[i]);
    }

    // reverse right vector
    reverse(right.begin(), right.end());

    // minimum boundary (height) to trap rain water
    for (int i = 0; i < len; ++i) {
        heights.push_back(min(left[i], right[i]));
    }

    long long sum{};
    for (int i = 0; i < len; ++i) {
        sum += max(0, heights[i]-arr[i]); // diff <= 0 cannot trap any water
    }

    return sum;
}

int main() {
    vector<int> arr{4,7,3,2,0,1,9,4,6};
    cout << RainWaterTrapping(arr);
}