
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> v(n); 

    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
    }

    int q;
    cin >> q; 

    vector<int> diff(n + 1, 0); 

  
    while (q--) {
        int l, r, val;
        cin >> l >> r >> val; 

        diff[l - 1] += val; 
        if (r < n) {
            diff[r] -= val; 
        }
    }


    for (int i = 0; i < n; i++) {
        if (i > 0) diff[i] += diff[i - 1]; 
        v[i] += diff[i]; 
    }

   
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}//than  range qaurry 
