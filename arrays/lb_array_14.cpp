#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using Intervals = vector<vector<int>>;

void PrintIntervals(Intervals const& arr) {
    for (auto const& interval : arr) {
        cout << "{" << interval[0] << "," << interval[1] << "},";
    }
    cout << endl;
}

bool IsOverlapping(vector<int> const& X, vector<int> const& Y) {
    return (Y[0] - X[1]) < 1;
}

void MergeIntervals(Intervals& arr, Intervals& ans) {
    auto len{arr.size()};
    if (len == 1) {
        ans = arr;
        return;
    }

    sort(arr.begin(), arr.end()); // sorted

    auto maxInterval{arr[0]}; // set 1st item to max interval

    for (auto it = next(arr.begin()); it != arr.end(); ++it) {
        auto interval{*it};
        if (IsOverlapping(maxInterval, interval)) {
            maxInterval[1] = max(maxInterval[1], interval[1]); // update range
        } else {
            ans.push_back(maxInterval);
            maxInterval = interval;
        }
    }

    ans.push_back(maxInterval);
}

int main() {
    // [[1,3],[2,6],[8,10],[15,18]]
    // Intervals arr{{1,3},{2,6},{8,10},{15,18}};
    Intervals arr{{1,4},{2,3}};
    Intervals ans{};
    PrintIntervals(arr);
    MergeIntervals(arr, ans); 
    PrintIntervals(ans);
}