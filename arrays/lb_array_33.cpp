#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int FindGoodValueCount(vector<int> const& arr, int len, int k) {
    int gvc{};
    for (int i = 0; i < len; ++i) {
        if (arr[i] <= k) {
            ++gvc;
        }
    }
    return gvc;
}

int FindBadValueCountForWindow(vector<int> const& arr, int len, int k, int start, int end) {
    int bvc{};
    for (int i = start; i <= end; ++i) {
        if (arr[i] > k) {
            ++bvc;
        }
    }
    return bvc;
}

int MinSwapsAndKTogether(vector<int>& arr, int k) {
    int len{static_cast<int>(arr.size())};
    
    // calculate gvc for entire array to find window size
    int gvc{FindGoodValueCount(arr, len, k)};
    if (gvc == len || gvc == 0) {
        return 0;
    }

    // calculate bvc for the window
    int start{0}, end{gvc-1};
    int bvc{FindBadValueCountForWindow(arr, len, k, start, end)};
    int minbvc{bvc};

    // run till the window reaches the end
    while (end < len) {
        end += 1; // recruit new element to window
        if (end < len) { // bounds check
            if (arr[end] > k) {
                ++bvc;
            }

            if (arr[start] > k) {
                --bvc;
            }
            start += 1; // remove old element from window

            minbvc = min(bvc, minbvc); // update min bad value count
        }
    }

    return minbvc;
}

int main() {
    // vector<int> arr{7,2,5,9,4,11,10,6,3,1,5};
    // cout << MinSwapsAndKTogether(arr, 5);
    // vector<int> arr{10,12,20,20,5,19,19,12,1,20,1};
    // cout << MinSwapsAndKTogether(arr, 1);
    vector<int> arr{8,13,7,6,4,8,5,15,11,13,18};
    cout << MinSwapsAndKTogether(arr, 9);
}