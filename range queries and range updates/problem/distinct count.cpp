

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int q;
    cin >> q;

    vector<vector<int>> freq(n + 1, vector<int>(27, 0));


    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            freq[i][j] = freq[i - 1][j];
        }
        freq[i][s[i - 1] - 'a']++;
    }


    while (q--) {
        int l, r;
        cin >> l >> r;



      // l--;
       // r--;

        int dCount = 0;

        for (int j = 0; j < 26; j++) {
            if ((freq[r][j] - freq[l-1][j]) > 0) {
                dCount++;
            }
        }

        cout << dCount << endl;
    }


}
