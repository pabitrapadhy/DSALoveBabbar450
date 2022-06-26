#include<iostream>
#include<vector>

using namespace std;

int SmallestSubarrayWithSum(vector<int> const& arr, int x) {
    int len{static_cast<int>(arr.size())};

    int sum{};
    int minLen{len};

    for (int i = 0; i < len; ++i) {
        sum = 0; // reset
        for (int j = i; j < len; ++j) {
            sum += arr[j];
            if (sum > x) {
                minLen = min(minLen, j-i+1);
                break;
            }
        }
    }
    return minLen;
}

int SmallestSubarrayWithSumOptimal(vector<int> const& arr, int x) {
    int len{static_cast<int>(arr.size())};

    int minSize{len};
    int left{0};
    int sum{arr[0]};

    for (int i = 1; i < len; ++i) {
        sum += arr[i];
        if (sum > x) {
            while (sum - arr[left] > x) {
                sum -= arr[left];
                ++left;
            }
            minSize = min(minSize, i-left+1);
        }
    }
    return minSize;
}

int main() {
    // int x{51};
    // vector<int> arr{1,4,45,6,0,19};

    // int x{9};
    // vector<int> arr{1,10,5,2,7};

    int x{12};
    vector<int> arr{1,2,3,7,5};

    // cout << SmallestSubarrayWithSum(arr, x);
    cout << SmallestSubarrayWithSumOptimal(arr, x);
}