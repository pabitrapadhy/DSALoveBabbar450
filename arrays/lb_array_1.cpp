#include<iostream>
#include<string>

using namespace std;

void ReverseArray(string& s) {
    const auto length{s.size()};

    if (length > 1) {
        for (int i = 0; i < length/2; ++i) {
            swap(s[i], s[length - i - 1]);
        }
    }
}

int main() {
    string arr{"Kp21Am"};
    ReverseArray(arr);
    cout << arr << endl;
}