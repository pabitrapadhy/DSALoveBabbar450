#include<iostream>
#include<vector>

using namespace std;

int FindMinJumps(vector<int> const& arr) {
    const auto len{arr.size()};
    int numJumps{0};

    for (int i = 0; i < len-1; ) {
        int item{arr[i]};
        if (item == 0) {
            return -1; // zero item case
        } else if (i+item >= len-1) {
            ++numJumps;
            return numJumps; // reaching/overshooting last element with next jump
        } else {
            int max{0};
            int jumpIdx{i};

            // find the biggest item of the lot to jump longest
            for (int j = i+1; j <= i+item; ++j) {
                if (arr[j]+j >= max) {
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