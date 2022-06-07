#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

bool HasAllNegativeElements(vector<int> const& arr, int& mss, int& start, int& last) {
    int max{INT_MIN};
    auto len{arr.size()};
    for (int i = 0; i < len; ++i) {
        if (arr[i] > 0) {
            mss = max;
            return false;
        } else if (arr[i] > max) {
            max = arr[i];
            start = i;
            last = i;
        }
    }
    mss = max;
    return true;
}

bool HasAllPositiveElements(vector<int> const& arr, int& mss) {
    int sum{0};
    auto len{arr.size()};
    for (int i = 0; i < len; ++i) {
        if (arr[i] < 0) {
            mss = sum;
            return false;
        }
        sum += arr[i];
    }
    mss = sum;
    return true;
}

int MaximumSumSubarray(vector<int> const& arr) {
    // base checks
    auto len{arr.size()};
    int mss{0};
    int start{0};
    int last{0};

    if (HasAllNegativeElements(arr, mss, start, last)) {
        cout << "start: " << start << " end: " << last << endl;
        return mss;
    } else if (HasAllPositiveElements(arr, mss)) {
        cout << "start: " << 0 << " end: " << len-1 << endl;
        return mss;
    } else {
        int max{INT_MIN};
        int sum{0};
        start = 0;
        last = 0;

        for (int i = 0; i < len; ++i) {
            if (sum < 0) { // check for sum reset
                sum = 0;
                start = i;
            }

            sum += arr[i]; // add element to sum

            if (sum > max) { // check for max
                max = sum;
                last = i;
            }
        }
        cout << "start: " << start << " end: " << last << endl;
        return max;
    }
}

int main() {
//    vector<int> arr{-2,-3,4,-1,-2,1,5,-3};
//    vector<int> arr{-1,2,2,-1,-1,-2,1};
    vector<int> arr{-2,-3,-1,-4,-5};
    cout << MaximumSumSubarray(arr);
}