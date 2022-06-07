#include<iostream>
#include<vector>

using namespace std;

struct MyCompare {
    virtual bool operator() (const int x, const int y) const = 0;
};

struct Greater : public MyCompare {
    bool operator() (const int x, const int y) const override {
        return x > y;
    }
};

struct Lesser : public MyCompare {
    bool operator() (const int x, const int y) const override {
        return x < y;
    }
};

int Partitioning(vector<int>& arr, int start, int end, MyCompare const& cmp) {
    int pivot{end};
    int hole{start};
    
    for (int i = 0; i < end; ++i) {
        if (cmp(arr[i], arr[pivot])) {
            swap(arr[i], arr[hole]);
            ++hole;
        }
    }
    swap(arr[hole], arr[pivot]);
    return hole;
}

int RandomizedPartitioning(vector<int>& arr, int start, int end, MyCompare const& cmp) {
    srand(time(0));
    int pIndex{start + rand() % end};
    swap(arr[pIndex], arr[end]);
    return Partitioning(arr, start, end, cmp);
}

int FindKthElement(vector<int>& arr, int start, int end, int k, MyCompare const& cmp) {
    if (start < end) {
        int pIndex{RandomizedPartitioning(arr, start, end, cmp)};
        if (pIndex == k-1) {
            return arr[pIndex];
        } else if (pIndex < k-1) {
            return FindKthElement(arr, pIndex+1, end, k, cmp);
        }
        return FindKthElement(arr, start, pIndex-1, k, cmp);
    }
    return -1;
}

int main() {
    vector<int> arr{4,3,5,1,2};
    Lesser ls{};
    Greater gs{};
    cout << FindKthElement(arr, 0, arr.size()-1, 2, gs); // largest/smallest by comparator
}