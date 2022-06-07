#include<iostream>
#include<vector>

using namespace std;

// METHOD 1: By modifying array //

// int FindDuplicateElement(vector<int>& arr) {
//     auto len{arr.size()};
    
//     for (int i = 0; i < len-1; ++i) {
//         while (i != arr[i]-1) {
//                 if (arr[arr[i]-1] == arr[i]) {
//                 return arr[i];
//             }
//             swap(arr[i], arr[arr[i]-1]);
//         }
//     }
//     return arr[len-1];
// }

// METHOD 2: Without modifying array //

// Floyd's algorithm: Rabbit Turtle method (by converting array to linked list)
int FindDuplicateElement(vector<int> const& arr) {
    int slow{0}; // starts from 0 index
    int fast{0}; // starts from 0 index

    do {
        slow = arr[slow]; // moves by 1 step
        fast = arr[arr[fast]]; // moves by 2 step
    } while (slow != fast);

    int slowTwo{0}; // another slow from index 0
    do {
        slow = arr[slow]; // moves by 1 step
        slowTwo = arr[slowTwo]; // moves by 1 step
    } while (slow != slowTwo);

    return slow; // intersection is duplicate
}

int main() {
    // vector<int> arr{1,3,4,2,2};
    // vector<int> arr{2,2,2,2,2};
    // vector<int> arr{2,1,3,3,4};
    vector<int> arr{1,2,3,4,1};
    cout << FindDuplicateElement(arr);
}