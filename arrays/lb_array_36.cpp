#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int FindMedian(vector<int> const& A, vector<int> const& B) {
    int n{static_cast<int>(A.size())};
    int m{static_cast<int>(B.size())};
    if (n > m) {
        return FindMedian(B, A);
    }

    int half{(n+m+1)/2}; // to pick the middle element in case of odd elements.
    int minPick{0}, maxPick{n}; // min and max no. of picks possible from A
    int cut1{}, cut2{}, l1{}, l2{}, r1{}, r2{};

    while (minPick <= maxPick) {
        cut1 = (minPick + maxPick)/2;
        cut2 = half-cut1;

        l1 = cut1 == 0 ? INT_MIN : A[cut1-1];
        l2 = cut2 == 0 ? INT_MIN : B[cut2-1];
        r1 = cut1 == n ? INT_MAX : A[cut1];
        r2 = cut2 == m ? INT_MAX : B[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((n+m)%2 == 0) { // even
                return (max(l1, l2) + min(r1, r2))/2;
            } else { // odd
                return max(l1, l2);
            }
        } else if (l1 <= r2) {
            minPick = cut1 + 1;
        } else {
            maxPick = cut1 - 1;
        }
    }
    return -1; // default value
}

int main() {
    // vector<int> A{2,3,5,8};
    // vector<int> B{10,12,14,16,18,20};

    vector<int> A{-5,3,6,12,15};
    vector<int> B{-12,-10,-6,-3,4,10};

    cout << FindMedian(A, B);
}