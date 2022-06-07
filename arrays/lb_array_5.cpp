#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

void SortNegativeToLeft(vector<int>& arr) {
    auto k{0};
    auto length{arr.size()};

    for (int i = 0; i < length; ++i) {
        if (arr[i] < 0) {
            swap(arr[i], arr[k]);
            ++k;
        }
    }
}

int main() {
    vector<int> arr{-1,3,2,-5,2,-51,-9,21};
    SortNegativeToLeft(arr);
    Print(arr);
}