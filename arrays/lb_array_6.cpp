#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int FindDistinctElements(vector<int> const& A, vector<int> const& B) {
    unordered_map<int, bool> mp{};
    int n{static_cast<int>(A.size())};
    int m{static_cast<int>(B.size())};

    for (int i = 0; i < n; ++i) {
        if (mp.find(A[i]) == mp.end()) { // ignoring duplicate elements
            mp[A[i]];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        if (mp.find(B[i]) == mp.end()) { // ignoring duplicate elements
            mp[B[i]];
        }
    }
    
    return mp.size();
}

int FindDistinctElementsOptimal(vector<int> const& A, vector<int> const& B) {
    unordered_set<int> st{A.begin(), A.end()};
    st.insert(B.begin(), B.end());
    return st.size();
}

int main() {
    vector<int> A{1,2,3,4,5};
    vector<int> B{1,2};
    cout << FindDistinctElementsOptimal(A, B);
}