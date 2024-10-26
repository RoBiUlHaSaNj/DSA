#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;  // Maximum size of the array
int bit[MAXN + 1];     // Fenwick Tree (1-based indexing)
int n;                 // Size of the array

// Point Update: Adds 'val' to element at index 'i'
void update(int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += i & -i;  // Move to the next index in the tree
    }
}

// Prefix Sum: Returns the sum of elements from index 1 to index 'i'
int prefixSum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & -i;  // Move to the parent index in the tree
    }
    return sum;
}

// Range Sum Query: Returns the sum of elements in the range [l, r]
int rangeSum(int l, int r) {
    return prefixSum(r) - prefixSum(l - 1);
}

int main() {
    int q;
    cin >> n >> q;
    vector<int> arr(n + 1);  // 1-based indexing for convenience

    // Input array and build the Fenwick Tree
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i]);  // Initialize BIT with initial array values
    }

    // Process queries
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            // Point update: add y to arr[x]
            update(x, y);
        } else if (type == 2) {
            // Range sum query: sum of elements from arr[x] to arr[y]
            cout << rangeSum(x, y) << endl;
        }
    }

    return 0;
}
