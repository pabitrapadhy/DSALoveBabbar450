#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void Subsequence(string const& str, string prefix, int start, int const& N) {
    for (int i = start; i < N; ++i) {
        string subSeq{prefix+str[i]};
        cout << subSeq << " ";
        Subsequence(str, subSeq, i+1, N);
        cout << endl;
    }
}

int LongestConsecutiveSubsequence(vector<int>& arr) {
    int N{static_cast<int>(arr.size())};
    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 1;
    }

    sort(arr.begin(), arr.end());

    int max{1}, count{1};
    for (int i = 1; i < N; ++i) {
        if (arr[i-1] == arr[i]) {
            continue;
        } else if (arr[i-1] + 1 == arr[i]) {
            if (++count > max) {
                max = count;
            }
        } else {
            count = 1; // for next subsequence
        }
    }
    return max;
}

int LongestConsecutiveSubsequenceOptimal(vector<int> const& arr) {
    int len{static_cast<int>(arr.size())};

    if (len == 0) {
        return 0;
    } else if (len == 1) {
        return 1;
    }

    unordered_map<int, int> mp{}; // to find consecutive shorter/larger item

    for (int i = 0; i < len; ++i) { // fill the map
        mp[arr[i]]++;
    }

    int count{1}, max{1}; // default value
    for (int i = 0; i < len; ++i) {
        auto it{mp.find(arr[i]-1)}; // finding consecutive shorter item
        if (it != mp.end()) {
            continue;
        } else {
            int item{arr[i]+1}; // consequetive larger item
            it = mp.find(item);

            while (it != mp.end()) {
                ++count;
                item = item+1;
                it = mp.find(item);
            }

            if (count > max) {
                max = count;
            }

            count = 1; // reset for the next subsequence
        }
    }
    return max;
}

int main() {
    // string str{"1234"};
    // Subsequence(str, "", 0, str.size());

    // vector<int> arr{1,1,1,1,1};
    // vector<int> arr{};
    vector<int> arr{2,6,1,9,4,5,3};
    // cout << LongestConsecutiveSubsequence(arr); // O(NLogN)
    cout << LongestConsecutiveSubsequenceOptimal(arr);
}