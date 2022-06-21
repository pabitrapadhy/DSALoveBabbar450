#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool IsASubset(vector<int> const& a1, vector<int> const& a2) {
    int lenOne{static_cast<int>(a1.size())};
    int lenTwo{static_cast<int>(a2.size())};

    if (lenTwo == 0) {
        return true; // blank subset is always a subset of everything
    }

    unordered_map<int, bool> mp{};
    for (int i = 0; i < lenOne; ++i) {
        mp[a1[i]];
    }

    auto it{mp.begin()};
    for (int i = 0; i < lenTwo; ++i) {
        it = mp.find(a2[i]);
        if (it == mp.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    // vector<int> a1{};
    // vector<int> a2{};

    // vector<int> a1{11,1,13,21,3,7};
    // vector<int> a2{11,3,7,1};

    // vector<int> a1{1,2,3,4,5,6};
    // vector<int> a2{1,2,4};

    vector<int> a1{10,5,2,23,19};
    vector<int> a2{19,5,3};

    cout << boolalpha << IsASubset(a1, a2);
}