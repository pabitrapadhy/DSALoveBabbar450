#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

// NOTE: even index -ve, odd index +ve

// Method 1: Brute Force: O(N) time and O(N) space
void AlternateSignBruteWithOrder(vector<int>& arr) {
    vector<int> posArray{}, negArray{}, result{};
    int len{static_cast<int>(arr.size())};

    for (int i = 0; i < len; ++i) {
        arr[i] >= 0 ? posArray.push_back(arr[i]) : negArray.push_back(arr[i]);
    }

    int i{}, j{}, k{};
    int lenPos{static_cast<int>(posArray.size())};
    int lenNeg{static_cast<int>(negArray.size())};

    while (i < lenPos && j < lenNeg) {
        if (k%2 == 0 && j < lenNeg) {
            result.push_back(negArray[j]);
            ++j; ++k;
        } else if (k%2 == 1 && i < lenPos) {
            result.push_back(posArray[i]);
            ++i; ++k;
        }
    }

    while (i < lenPos) {
        result.push_back(posArray[i]);
        ++i;
    }
    while (j < lenNeg) {
        result.push_back(negArray[j]);
        ++j;
    }

    arr = result;
}

// Method 2: O(N^2) time and O(1) space. Space optimal
template<typename T>
struct MyComparator {
    virtual bool operator() (T const& x, T const& y) const = 0;
};

template<typename T>
struct Lesser : public MyComparator<T> {
    bool operator() (T const& x, T const& y) const override {
        return x < y;
    }
};

template<typename T>
struct Greater : public MyComparator<T> {
    bool operator() (T const& x, T const& y) const override {
        return x > y;
    }
};

void Rotate(vector<int>& arr, int i, int j) {
    int val{arr[j]};

    for (int k = j; k > i; --k) {
        arr[k] = arr[k-1];
    }
    arr[i] = val;
}

template<typename T>
void Rearrange(vector<int>& arr, int& i, MyComparator<T>& comp) {
    int j{i};
    int len{static_cast<int>(arr.size())};

    while (j < len && comp(arr[j], 0)) { // using comparator
        ++j;
    }

    if (j == len) {
        i = j; // breaks the for loop after return
    } else {
        Rotate(arr, i, j); // rotate right once
    }
}

void AlternateSignOptimalSpaceWithOrder(vector<int>& arr) {
    int len{static_cast<int>(arr.size())};

    Lesser<int> lscmp{};
    Greater<int> grcmp{};

    for (int i = 0; i < len; ++i) {
        if (i%2 == 0 && arr[i] > 0) {
            Rearrange(arr, i, grcmp);
        } else if (i%2 == 1 && arr[i] < 0) {
            Rearrange(arr, i, lscmp);
        }
    }
}

// Method 3: Rearrnging without order. O(N) time and O(1) space
void AlternateSignWithoutOrder(vector<int>& arr) {
    int len{static_cast<int>(arr.size())};
    int p{};

    // arrange all negative to left and all positive to right.
    for (int i = 0; i < len; ++i) {
        if (arr[i] < 0) {
            swap(arr[i], arr[p]);
            ++p;
        }
    }

    for (int i = 0; i < p && p < len; ++i) {
        if (i%2 == 0) {
            continue;
        } else {
            swap(arr[i], arr[p]);
            ++p;
        }
    }
}

int main() {
    vector<int> arr{-5,4,3,-2,1,9,7,-4};
    AlternateSignBruteWithOrder(arr);
    Print(arr);

    arr.assign({-5,4,3,-2,1,9,7,-4});
    AlternateSignOptimalSpaceWithOrder(arr);
    Print(arr);

    // vector<int> arr{-2,-3,1,2,3,4,-5,2};
    // AlternateSignWithoutOrder(arr);
    // Print(arr);
}