#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int FindMinDifference(vector<int>& arr, int k) {
    auto len{arr.size()};
    if (len == 1) {
        return 0;
    }

    // sort the heights
    sort(arr.begin(), arr.end());

    int minH{arr[0]}, maxH{arr[len-1]};
    int ans{maxH - minH};

    // find if ans can be minimized
    int trueMin{minH};
    int trueMax{maxH};

    // We need to find the tipping point.
    // from where we need to stop doing +k, and start doing -k
    // Since we don't know from where, we'll try all possibilities
    // of segmenting the array into left and right segment.
    // Then find the min and max, after operation, to see if diff can be minimized.
    for (int i = 1; i < len; ++i) {
        // NOTE: i is the imaginary border of left and right segment
        // items to the left of imaginary border are left segment
        // items to the right of the imaginary border are right segment.

        int x{arr[i-1]}; // right most element of left segment
        int y{arr[i]}; // left most element of the right segment

        minH = min(trueMin + k, y - k); // at border, all items to the left can be done +k
        maxH = max(x + k, trueMax - k); // at border, all items to the right can be done -k

        if (minH < 0) {
            continue;
        }
        
        // update answer
        ans = min(ans, maxH - minH);
    }
    
    return ans;
}

int main() {
    vector<int> arr{1,5,8,10};
    int k{2};
    cout << FindMinDifference(arr, k);
}