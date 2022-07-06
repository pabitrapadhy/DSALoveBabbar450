#include<iostream>
#include<vector>

using namespace std;

int MinMergeForPalindrome(vector<int>& arr) {
    int len{static_cast<int>(arr.size())};
    if (len == 1) {
        return 0;
    }

    int count{};
    int i{}, j{len-1};
    
    while (i <= j) {
        if (arr[i] == arr[j]) {
            ++i;
            --j;
        } else if (arr[i] < arr[j]) {
            arr[i+1] += arr[i];
            ++i;
            ++count;
        } else {
            arr[j-1] += arr[j];
            --j;
            ++count;
        }
    }
    return count;
}

int main() {
    // vector<int> arr{11,14,12,1,13,13,11};
    // vector<int> arr{1,4,5,1};
    // vector<int> arr{6,5,6,5,5,5};
    vector<int> arr{11,2,11};
    cout << MinMergeForPalindrome(arr);
}