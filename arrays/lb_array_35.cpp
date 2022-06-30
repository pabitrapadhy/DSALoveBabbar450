#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print(vector<int> const& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int GetMedian(vector<int> const& arr) {
    int len{static_cast<int>(arr.size())};
    return len%2 ? arr[len/2] : (arr[len/2] + arr[len/2 -1])/2;
}

int MedianSortedArraySameSize(vector<int> A, vector<int> B, int n) {
    Print(A);
    Print(B);

    if (n == 0) {
        return -1;
    } else if (n == 1) {
        return (A[0]+B[0])/2;
    } else if (n == 2) {
        return (max(A[0], B[0]) + min(A[1], B[1]))/2;
    }

    int m1{GetMedian(A)};
    int m2{GetMedian(B)};

    if (m1 == m2) {
        return m1;
    } else if (m1 > m2) {
        if (n%2) { // odd
            return MedianSortedArraySameSize(
                vector<int>{A.begin(), A.begin()+(n/2 +1)},
                vector<int>{B.begin()+(n/2), B.end()},
                n/2 + 1);
        } else { // even
            return MedianSortedArraySameSize(
                vector<int>{A.begin(), A.begin()+(n/2 +1)},
                vector<int>{B.begin()+(n/2 -1), B.end()},
                n/2 + 1);
        }
    } else {
        if (n%2) { // odd
            return MedianSortedArraySameSize(
                vector<int>{A.begin()+(n/2), A.end()},
                vector<int>{B.begin(), B.begin()+(n/2 +1)},
                n/2 + 1);
        } else { // even
            return MedianSortedArraySameSize(
                vector<int>{A.begin()+(n/2 -1), A.end()},
                vector<int>{B.begin(), B.begin()+(n/2 +1)},
                n/2 + 1);
        }
    }
}

int main() {
    // vector<int> A{5,9,11,15};
    // vector<int> B{1,2,3,4};

    // vector<int> A{3,10,24,40,50};
    // vector<int> B{2,11,12,21,41};

    vector<int> A{3,11,12,21,40,60};
    vector<int> B{1,7,15,20,45,50};

    // vector<int> A{2,11,21,40,60,65,73,91};
    // vector<int> B{4,5,9,19,25,45,55,61};

    cout << MedianSortedArraySameSize(A, B, A.size());
}