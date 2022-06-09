#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& item : arr) {
        cout << item << " ";
    }
    cout << endl;
}

void RearrangeAlternateSignWithOrder(vector<int>& arr) {
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

void RearrangeAlternateSignWithoutOrder(vector<int>& arr) {
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
    // vector<int> arr{-5,4,3,-2,1,9,7,-4};
    // RearrangeAlternateSignWithOrder(arr);

    vector<int> arr{-2,-3,1,2,3,4,-5,2};
    RearrangeAlternateSignWithoutOrder(arr);
    Print(arr);
}