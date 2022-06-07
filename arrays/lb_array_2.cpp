#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T>
struct MinMaxPair {
    T min{};
    T max{};
};

template<typename T>
void GetMinAndMax(string const& arr, MinMaxPair<T>& mmp) {
    auto length{arr.size()};
    if (!length) {
        cerr << "error" << endl;
        return;
    }

    mmp.min = arr[0];
    mmp.max = arr[0];

    if (length == 1) {
        return;
    }

    for (int i = 1; i < length; ++i) {
        if (arr[i] > mmp.max) {
            mmp.max = arr[i];
        }

        if (arr[i] < mmp.min) {
            mmp.min = arr[i];
        }
    }
}

int main() {
    // vector<int> arr{80, 27, 15, 2, 2, 15, 120};
    // vector<int> arr{};
    // vector<char> arr{'K','p','2','1','A','m'};
    string arr{"Kp21Am"};

    MinMaxPair<char> mmp{};

    GetMinAndMax(arr, mmp);
    cout << "min: " << mmp.min << " max: " << mmp.max << endl;
}