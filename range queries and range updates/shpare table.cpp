#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;       // Maximum size of the array
const int LOG = 17;         // log2(MAXN) + 1 for the maximum power of 2

int table[MAXN][LOG];       // Sparse table
int logTable[MAXN + 1];     // Precomputed logs for quick range length calculation
int n;                      // Size of the array

// Build the sparse table for Range Minimum Query (RMQ)
void buildSparseTable(const vector<int>& arr) {
    n = arr.size();
    
    // Initialize the first level with the elements of the array
    for (int i = 0; i < n; i++) {
        table[i][0] = arr[i];
    }

    // Precompute logs for quick access
    logTable[1] = 0;
    for (int i = 2; i <= n; i++) {
        logTable[i] = logTable[i / 2] + 1;
    }

    // Build the table by filling in intervals of increasing powers of 2
    for (int j = 1; (1 << j) <= n; j++) {      // Power of 2 intervals
        for (int i = 0; (i + (1 << j) - 1) < n; i++) { // Range start
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Range Minimum Query (RMQ) for the range [L, R]
int rangeMinQuery(int L, int R) {
    int length = R - L + 1;
    int j = logTable[length]; // Find the largest power of 2 within range length
    return min(table[L][j], table[R - (1 << j) + 1][j]);
}

int main() {
    int q;
    cin >> n >> q;
    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the sparse table
    buildSparseTable(arr);

    // Process queries
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << rangeMinQuery(L, R) << endl;
    }

    return 0;
}
