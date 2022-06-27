#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

void SortZeroOneTwo(vector<int>& arr, vector<int> const& types) {
    auto start{0};
    auto end{arr.size()};

    for (int k = 0; k < types.size(); ++k) {
        int hole{start};
        for (int i = start; i < end; ++i) {
            if (arr[i] <= types[k]) {
                swap(arr[i], arr[hole]);
                ++hole;
            }
        }
        start = hole;
    }
}

void DNFSort(vector<int>& arr) {
    int len{static_cast<int>(arr.size())};
    
    int low{}, mid{};
    int high{len-1};

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[mid], arr[low]);
                ++low;
                ++mid;
                break;
            case 1:
                ++mid;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                --high;
                break;
        }
    }
}

int main() {
    // int low{10}, mid{14}, high{22};
    // vector<int> types{low, mid};

    // vector<int> arr{high, low, mid, high, low, mid}; // i/p
    
    // SortZeroOneTwo(arr, types);

    vector<int> arr{0,0,1,2,0,1,1,1,2,0};
    DNFSort(arr);
    Print(arr);
}