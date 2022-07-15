#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int FindSwapIndex(vector<int> const& arr, int k, int start, int end) {
    for (int i = start; i >= end; --i) {
        if (arr[i] > k) { // item bigger than k is the next bigger item to swap
            return i;
        }
    }
    return start;
}

void FindNextPermutation(vector<int>& arr) {
    int len{static_cast<int>(arr.size())};
    if (len < 2) {
        return;
    }

    int i{len-2};
    int j{len-1};

    while (i >= 0) {
        if (arr[i] < arr[j]) { // boundary wall between i and j
            int swapIdx{FindSwapIndex(arr, arr[i], len-1, j)};
            swap(arr[i], arr[swapIdx]);
            reverse(next(arr.begin(), j), arr.end()); // after swapping, reverse from boundary to end.
            return;
        } else {
            --i;
            --j;
        }
    }

    reverse(arr.begin(), arr.end());
}

int main() {
    // vector<int> arr{3,2,1};
    // vector<int> arr{1,4,3,2};
    // vector<int> arr{2,1};
    vector<int> arr{1,3,2};
    FindNextPermutation(arr);
    Print(arr);
}