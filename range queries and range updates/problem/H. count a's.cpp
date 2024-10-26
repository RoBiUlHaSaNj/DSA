#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();

    // Step 1: Create the prefix sum array for 'a' occurrences
    vector<int> countA(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        countA[i] = countA[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
    }

    // Optional: Print countA for debugging
    // This will show the prefix sum array for 'a'
    cout << "Prefix sum array for 'a': ";
    for (int i = 0; i <= n; ++i) {
        cout << countA[i] << " ";
    }
    cout << endl;

    // Step 2: Process each query
    while (q--) {
        int l, r;
        cin >> l >> r;
        int result = countA[r] - countA[l - 1];
        cout << result << "\n";
    }

    return 0;
}
