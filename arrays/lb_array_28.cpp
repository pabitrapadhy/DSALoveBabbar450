#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool HasTripletSumOptimal(vector<int>& arr, int k) {
    int len{static_cast<int>(arr.size())};
    if (len < 3) {
        return false;
    }

    // sort the array
    sort(arr.begin(), arr.end());

    int p{}, q{}, sum{};
    for (int i = 0; i < len-2; ++i) {
        p = i+1;
        q = len-1;

        while (p < q) {
            sum = arr[i] + arr[p] + arr[q];

            if (sum > k) {
                q = q-1;
            } else if (sum < k) {
                p = p+1;
            } else {
                return true;
            }
        }
    }

    return false;
}

bool HasTripletSum(vector<int> const& arr, int k) {
    int len{static_cast<int>(arr.size())};
    if (len < 3) {
        return false;
    }

    // frequency map
    unordered_map<int, int> mp{};
    for (int i = 0; i < len; ++i) {
        ++mp[arr[i]];
    }

    int sum{}, diff{}, fCount{};
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            sum = arr[i] + arr[j];
            diff = k - sum;
            fCount = 0; // reset fCount

            if (diff >= 0) {
                if (arr[i] == diff) {
                    ++fCount;
                }
                if (arr[j] == diff) {
                    ++fCount;
                }

                // find the 3rd item in frequency map
                if (mp.find(diff) != mp.end()) {
                    if (mp[diff] > fCount) {
                        return true;
                    }
                } 
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr{1,4,45,6,10,8};
    // vector<int> arr{0,0,0};
    cout << boolalpha << HasTripletSumOptimal(arr, 13);
}