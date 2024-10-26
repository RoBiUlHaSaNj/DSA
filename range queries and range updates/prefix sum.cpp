
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);


    for (long long &x : a) {
        cin >> x;
    }


    vector<long long> p(N + 1);

   // partial_sum(a.begin(), a.end(), p.begin() + 1);//inbuild 

    for (int i = 0; i < N; ++i) p[i + 1] = p[i] + a[i];


    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;


        cout << p[r] - p[l - 1] << "\n";
    }

    return 0;
}
