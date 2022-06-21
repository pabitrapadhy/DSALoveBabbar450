#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool HasAllNegativeElements(vector<int> const& arr, int len) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] > 0) {
            return false;
        }
    }
    return true;
}

int FindMaxElement(vector<int> const& arr, int len) {
    int maximum{arr[0]};
    for (int i = 1; i < len; ++i) {
        maximum = max(arr[i], maximum);
    }
    return maximum;
}

long long MaximumSumSubarray(vector<int> arr) {
    int len{static_cast<int>(arr.size())};

    if (HasAllNegativeElements(arr, len)) {
        return FindMaxElement(arr, len);
    } else {
        int start{0}, last{0};
        long long mss{arr[0]};
        long long sum{arr[0]};

        for (int i = 1; i < len; ++i) {
            if (sum < 0) { // check for sum reset
                sum = 0;
                start = i;
            }

            sum += arr[i]; // add element to sum

            if (sum > mss) { // check for max
                mss = sum;
                last = i;
            }
        }
        return mss;
    }
}

int main() {
    // vector<int> arr{-1,-2,-3,-4};
    vector<int> arr{1,2,3,-2,5};

    cout << MaximumSumSubarray(arr);
}