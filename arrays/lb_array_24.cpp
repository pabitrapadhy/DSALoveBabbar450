#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

vector<int> ElementFrequencyGreaterThanX(vector<int>& arr, int const K) {
    int len{static_cast<int>(arr.size())};

    if (K > len) {
        return {};
    } else {
        sort(arr.begin(), arr.end());

        vector<int> ans{};
        int count{1};
        int item{arr[0]};
        int X{len/K};
        
        for (int i = 1; i < len; ++i) {
            if (item == arr[i]) {
                ++count;
                
                if (count == X + 1) {
                    ans.push_back(item); // only add for once
                }
            } else {
                item = arr[i]; // new item found
                count = 1; // reset count
            }
        }
        return ans;
    }
}

vector<int> ElementFrequencyGreaterThanXOptimal(vector<int> const& arr, int const K) {
    int len{static_cast<int>(arr.size())};

    if (K > len) {
        return {};
    } else {
        unordered_map<int, int> mp{};
        vector<int> ans{};

        int count{};
        int X{len/K};

        for (int i = 0; i < len; ++i) {
            if (++mp[arr[i]] == X+1) {
                ans.push_back(arr[i]);
                ++count;
            }
        }
        return ans;
    }
}

int main() {
    vector<int> arr{3,1,2,2,1,2,3,3};
    // vector<int> arr{};
    // auto result{ElementFrequencyGreaterThanX(arr, 4)};
    auto result{ElementFrequencyGreaterThanXOptimal(arr, 4)};
    Print(result);
}