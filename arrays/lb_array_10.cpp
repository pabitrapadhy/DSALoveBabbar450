#include<iostream>
#include<vector>

using namespace std;

int FindMinJumps(vector<int> const& arr) {
    const auto len{arr.size()};
    int numJumps{0};

    // NOTE:
    // -----
    // Biggest item in the lot is not the biggest jump.
    // It is also important to know if the biggest item is towards the end of our lot.
    // then we can jump farthest.
    // To identify this, we always add item+index, 
    // because that sum will identify the item giving farthest jump.
    for (int i = 0; i < len-1; ) {
        int item{arr[i]};
        if (item == 0) {
            return -1; // zero item case
        } else if (i+item >= len-1) { // NOTE: i+item to identify farthest jump
            ++numJumps;
            return numJumps; // reaching/overshooting last element with next jump
        } else {
            int max{0};
            int jumpIdx{i};

            // find the item that gives farthest jump to reach end quickly
            for (int j = i+1; j <= i+item; ++j) {
                if (arr[j]+j >= max) { // NOTE: arr[j]+j to identify farthest jump
                    max = arr[j]+j;
                    jumpIdx = j;
                }
            }

            ++numJumps; // increment jump
            i = jumpIdx; // found a jump
        }
    }
    return numJumps;
}

int main() {
    // vector<int> arr{2,1,4,3,5,4};
    // vector<int> arr{1,3,5,8,9,2,6,7,6,8,9};
    // vector<int> arr{1,4,3,2,6,7};
    // vector<int> arr{2,1,3,2,2,0,1};
    vector<int> arr{9,10,1,2,3,4,8,0,0,0,0,0,0,0,1};
    cout << FindMinJumps(arr);
}