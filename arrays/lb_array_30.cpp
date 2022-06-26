#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int FindMinDifference(vector<int>& arr, int M) {
    int N{static_cast<int>(arr.size())};
    
    // sort
    sort(arr.begin(), arr.end());

    int minDiff{arr[N-1]}; // need to be a bigger +ve value, after sort
    int diff{}, start{}, finish{};
    int p1{0}, p2{M-1};

    while(p2 < N) {
        diff = arr[p2] - arr[p1];
        
        if (diff < minDiff) {
            minDiff = diff;
            start = p1;
            finish = p2;
        }
        ++p1, ++p2;
    }

    return minDiff;
}

int main() {
    // int M{5};
    // vector<int> arr{3,4,1,9,56,7,9,12};

    int M{3};
    vector<int> arr{7,3,2,4,9,12,56};

    cout << FindMinDifference(arr, M);
}