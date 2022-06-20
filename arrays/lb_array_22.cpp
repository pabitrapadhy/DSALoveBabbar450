#include<iostream>
#include<deque>

using namespace std;

template<typename T>
void Print(T const& arr) {
    for (auto const& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

template<typename T>
void AppendCarryDigits(T& arr, int carry, int& digitCount) {
    if (carry == 0) {
        return;
    }

    int p{carry%10};
    AppendCarryDigits(arr, carry/10, digitCount);
    arr.push_back(p);
    ++digitCount;
}

template<typename T>
void RotateByOne(T& arr) {
    int len{static_cast<int>(arr.size())};
    if (len == 1) {
        return;
    }

    int carry{arr[len-1]};
    for (int j = len-1; j > 0; --j) {
        arr[j] = arr[j-1];
    }
    arr[0] = carry;
}

template<typename T>
T FindFactorial(int N) {
    T ans{1};
    if (N < 2) {
        return ans;
    }

    for (int i = 2; i <= N; ++i) {
        int x{}, carry{};
        int k{static_cast<int>(ans.size())};

        for (int j = 0; j < k; ++j) {    
            x = (i * ans[k-1-j]) + carry;
            ans[k-1-j] = x%10;
            carry = x/10;

            Print(ans);
        }

        if (carry > 0) {
            int carryDigits{};
            AppendCarryDigits(ans, carry, carryDigits);

            for (int i = 0; i < carryDigits; ++i) {
                RotateByOne(ans);
            }
        }
    }
    return ans;
}

int main() {
    int N{1000};
    auto result{FindFactorial<deque<int>>(N)};
    Print(result);
}