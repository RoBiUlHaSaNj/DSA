#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; 

    while (t--) {
        string s;
        cin >> s; 

        // Preprocessing: Create a prefix frequency array
        vector<vector<int>> pre(26, vector<int>(s.size() + 1, 0));
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                pre[j][i + 1] = pre[j][i]; 
            }
            pre[s[i] - 'A'][i + 1]++; 
        }

        int t;
        cin >> t; 

        cout << "Results for string: " << s << endl;
        while (t--) {
            int l, r;
            cin >> l >> r; 
            l--; r--;     

            int evenCount = 0; 

            for (int i = 0; i < 26; i++) {
                int count = pre[i][r + 1] - pre[i][l];
                if (count > 0 && count % 2 == 0) {
                    evenCount++;
                    cout << char('A' + i) << " " << count << endl;
                }
            }

            cout << "Total even frequency count: " << evenCount << endl;
        }
        cout << endl; 
    }

    return 0;
}
