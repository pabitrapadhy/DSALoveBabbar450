#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int>& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void Insert(vector<int>& arr, int item) {
    auto hole{0};
    auto len{arr.size()};

    for (int i = 1; i < len; ++i) {
        if (arr[i] > item) {
            arr[hole] = item;
            return;
        }
        arr[i-1] = arr[i];
        ++hole;
    }
    
    arr[len-1] = item;
}

void MergeSortedArrays(vector<int>& A, vector<int>& B) {
    auto item{A[0]};
    auto lenA{A.size()};

    for (int i = 0; i < lenA; ++i) {
        if (A[i] > B[0]) {
            item = A[i];
            A[i] = B[0];
            Insert(B, item);
        }
    }
}

int main() {
    vector<int> A{1,3,3,7};
    vector<int> B{0,2,3,8,9};

    MergeSortedArrays(A, B);
    Print(A);
    Print(B);
}