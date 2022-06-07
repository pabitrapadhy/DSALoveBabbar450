#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int CountPairsWithGivenSum(vector<int> const& arr, int k) {
    int numPairs{};
    int len{static_cast<int>(arr.size())};
    unordered_map<int, int> freqMap{};

    for (int i = 0; i < len; ++i) {
        freqMap[arr[i]]++;
    }

    int count{};
    for (int i = 0; i < len; ++i) {
        auto it = freqMap.find(k-arr[i]);
        if (it != freqMap.end()) {
            count += it->second; // add the frequency count

            if (k-arr[i] == arr[i]) { // pair with itself (e.g. 1,1,1,1)
                --count; // removing once because frequency for reverse self-loop was not included.
            }
        }
    }

    numPairs = count/2; // removing duplicate pairs (i.e. only upper triangular matrix considered)
    return numPairs;
}

int main() {
    // int k{6};
    // vector<int> arr{1,5,7,1}; // 2

    int k{2};
    vector<int> arr{1,1,1,1}; // 6

    cout << CountPairsWithGivenSum(arr, k);
}