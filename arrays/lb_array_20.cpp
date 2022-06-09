#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

bool HasZeroSum(vector<int> const& arr) {
    bool flag{false};
    unordered_map<int, int> prefixSumMap{};

    int pSum{};
    for (int i = 0; i < arr.size(); ++i) {
        pSum += arr[i]; // prefix sum
        
        if (arr[i] == 0) { // 1. element is 0
            flag |= true;
        } else if (pSum == 0) { // 2. prefix sum is 0
            flag |= true;
        } else { // 3. prefix sum repeats
            auto it = prefixSumMap.find(pSum); // checks if prefix is present
            if (it != prefixSumMap.end()) {
                flag |= true;
            }
        }

        prefixSumMap[pSum] = i; // adds to the map
    }

    return flag;
}

int main() {
    // vector<int> arr{0,0,0};
    vector<int> arr{1,1,-2};
    cout << boolalpha << HasZeroSum(arr);
}