#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

void RotateArrayByOne(vector<int>& arr) {
    auto length{arr.size()};
    if (length == 1) {
        return;
    }

    int stored{arr[length-1]};
    for (int i = length-1; i > 0; --i) {
        arr[i] = arr[i-1];
    }
    arr[0] = stored;
}

int main() {
   vector<int> arr{1,2,3,4,5};
   RotateArrayByOne(arr);
   Print(arr);
}