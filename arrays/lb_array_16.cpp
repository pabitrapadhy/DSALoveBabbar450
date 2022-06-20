#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void Merge(vector<int>& arr, int first, int mid, int last, int& invCount) {
    const int lenLeft{mid-first+1};
    const int lenRight{last-mid};

    vector<int> left{}, right{};
    for (int l = first; l <= mid; ++l) {
        left.push_back(arr[l]);
    }
    for (int r = mid+1; r <= last; ++r) {
        right.push_back(arr[r]);
    }

    int i{0}, j{0}, k{first};
    while (i < lenLeft && j < lenRight) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++k;
            ++i;
        } else {
            invCount += lenLeft-i;

            arr[k] = right[j];
            ++k;
            ++j;
        }
    }
    
    while (i < lenLeft) {
        arr[k] = left[i];
        ++k;
        ++i;
    }
    while (j < lenRight) {
        arr[k] = right[j];
        ++k;
        ++j;
    }
}

void GetInversionCount(vector<int>& arr, int first, int last, int& invCount) {
    if (first < last) {
        int mid{first + (last-first)/2};
        GetInversionCount(arr, first, mid, invCount);
        GetInversionCount(arr, mid+1, last, invCount);
        Merge(arr, first, mid, last, invCount);
    }
}

void GetInversion(vector<int>& arr) {
    int invCount{};
    int len{static_cast<int>(arr.size())};

    for (int i = 0; i < len-1; ++i) {
        for (int j = i+1; j < len; ++j) {
            if (arr[i] > arr[j]) {
                ++invCount;
            }
        }
    }

    cout << "invCount: " << invCount << endl;
}

int main() {
    int invCount{};
    // vector<int> arr{5,2,1,3,4};
    // vector<int> arr{2,4,1,3,5};
    // vector<int> arr{6,5,4,3,2,1};
    vector<int> arr{468,335,1,170,225,479,359,463,465,206,146,282,328,462,492,496,443,328,437,392,105,403,154,293,383,422,217,219,396,448,227,272,39,370,413,168,300,36,395,204,312,323};
    // vector<int> arr{10,6,4,2,1,3,5,7,9};

    vector<int> brr{arr};

    GetInversionCount(arr, 0, arr.size()-1, invCount);
    Print(arr);
    cout << "invCount: " << invCount << endl;

    GetInversion(brr);
}