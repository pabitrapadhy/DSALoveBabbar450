#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int PartitionByValue(vector<int>& arr, int start, int end, int value) {
    int hole{start};

    for (int i = start; i <= end; ++i) {
        if (arr[i] < value) {
            swap(arr[i], arr[hole]);
            ++hole;
        }
    }

    return hole;
}

void ThreeWayPartitioning(vector<int>& arr, int a, int b) {
    int len{static_cast<int>(arr.size())};

    int start{0}, end{len-1};
    int aStarts{PartitionByValue(arr, start, end, a)};
    int bStarts{PartitionByValue(arr, aStarts, end, b)};
}

int main() {
    // vector<int> arr{7,9,5,1,4,6,3,2};
    // ThreeWayPartitioning(arr, 4, 7);
    
    // vector<int> arr{76,8,75,22,59,96,30,38,36};
    // ThreeWayPartitioning(arr, 44, 62);

    // vector<int> arr{3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98};
    // ThreeWayPartitioning(arr, 22, 53);

    vector<int> arr{2,8,100,6,1,10,50,13,12,75};
    ThreeWayPartitioning(arr, 6, 13);

    Print(arr);
}