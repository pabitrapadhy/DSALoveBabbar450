#include<iostream>
#include<vector>

using namespace std;

using VecInt = vector<int>;
using VecIntCR = vector<int> const&;
using IIPair = pair<int, int>;
using IIPairCR = pair<int, int> const&;

void Print(VecIntCR result) {
    for (auto const& item : result) {
        cout << item << " ";
    }
    cout << endl;
}

IIPairCR FindMin(IIPairCR x, IIPairCR y, IIPairCR z) {
    IIPairCR k{x < y ? x : y};
    return z < k ? z : k;
}

VecInt FindCommonElements(VecIntCR A, VecIntCR B, VecIntCR C) {
    VecInt result{};

    int lenA{static_cast<int>(A.size())};
    int lenB{static_cast<int>(B.size())};
    int lenC{static_cast<int>(C.size())};

    int p{}, q{}, r{};

    while (p < lenA && q < lenB && r < lenC) {
        if (A[p] == B[q] && B[q] == C[r]) {
            if (result.empty() || result[result.size()-1] != A[p]) {
                result.push_back(A[p]);
            }
            ++p, ++q, ++r;
        } else {
            IIPair x{A[p], p};
            IIPair y{B[q], q};
            IIPair z{C[r], r};

            IIPairCR minPair{FindMin(x, y, z)};
            const int& minItem{minPair.first};
            
            if (minItem == A[p]) {
                ++p;
            } else if (minItem == B[q]) {
                ++q;
            } else {
                ++r;
            }
        }
    }

    return result;
}

int main() {
    // VecInt A{3,4,5,6,7,8};
    // VecInt B{3,5,9};
    // VecInt C{3,5,9,11,14};

    // VecInt A{1,5,10,20,40,80};
    // VecInt B{6,7,20,80,100};
    // VecInt C{3,4,15,20,30,70,80,120};

    VecInt A{1,1,1,1};
    VecInt B{1,1,1,1};
    VecInt C{1,1,1,1};

    VecIntCR result{FindCommonElements(A, B, C)};
    Print(result);
}