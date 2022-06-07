#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int FindNumUnion(vector<int> const& m, vector<int> const& n) {
    unordered_map<int, char> mp{};
    auto lenM{m.size()};
    auto lenN{n.size()};

    for (int i = 0; i < lenM; ++i) {
        mp[m[i]];
    }

    int dCount{0};
    for (int i = 0; i < lenN; ++i) {
        if (mp.find(n[i]) != mp.end()) {
            ++dCount;
        }
    }
    return lenM + lenN - dCount;
}

int FindNumIntersection(vector<int> const& m, vector<int> const& n) {
    unordered_map<int, char> mp{};
    auto lenM{m.size()};
    auto lenN{n.size()};

    for (int i = 0; i < lenM; ++i) {
        mp[m[i]];
    }

    int dCount{0};
    for (int i = 0; i < lenN; ++i) {
        if (mp.find(n[i]) != mp.end()) {
            ++dCount;
        }
    }
    return dCount;
}

int main() {
   vector<int> m{1,2,3,4,5};
   vector<int> n{1,3,7};
   cout << FindNumUnion(m, n) << endl;
   cout << FindNumIntersection(m, n) << endl;
}