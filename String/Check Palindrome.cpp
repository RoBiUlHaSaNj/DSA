#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            return false; 
        }
    }
    return true;
}

int main() {
    string input;

    cin >> input;

    if (isPalindrome(input)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
