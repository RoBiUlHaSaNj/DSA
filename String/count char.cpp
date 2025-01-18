#include<bits/stdc++.h>
using namespace std;

int main() {
    string input = "regff";
    map<char, int> frequency;
   sort(input.begin(),input.end());
    // Count the frequency of each character
    for (char ch : input) {
        frequency[ch]++;
    }

    // Display the result
    for (auto &pair : frequency) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
