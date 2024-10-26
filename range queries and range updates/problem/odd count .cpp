
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

       
        vector<vector<int>> prefixFreq(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; ++i) {
          
            for (int j = 0; j < 26; ++j) {
                prefixFreq[i][j] = prefixFreq[i - 1][j];
            }
           
            prefixFreq[i][s[i - 1] - 'a']++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            int oddCount = 0;
            for (int j = 0; j < 26; ++j) {
                int freqInRange = prefixFreq[r][j] - prefixFreq[l - 1][j];
                if (freqInRange % 2 == 1) { 
                    oddCount++;
                }
            }
            cout << oddCount << "\n";
        }
    }

    return 0;
}
