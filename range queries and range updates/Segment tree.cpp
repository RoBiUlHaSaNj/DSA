#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5; // Assuming maximum array size for simplicity
int tree[4 * MAXN];   // Segment tree array
int n;                 // Size of the array

// Build the segment tree
void build(const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        // Leaf node will have a single element
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

// Update a value at index `idx` to `val`
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        // Leaf node
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            // Update the left child
            update(2 * node + 1, start, mid, idx, val);
        } else {
            // Update the right child
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        // After updating the child, recalculate the parent node
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

// Query the sum in range [l, r]
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0; // Out of range
    }
    if (l <= start && end <= r) {
        return tree[node]; // Completely within range
    }
    int mid = (start + end) / 2;
    int leftSum = query(2 * node + 1, start, mid, l, r);
    int rightSum = query(2 * node + 2, mid + 1, end, l, r);
    return leftSum + rightSum;
}

int main() {
    int q;
    cin >> n >> q;
    vector<int> arr(n);

    // Input array values
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the segment tree
    build(arr, 0, 0, n - 1);

    // Process queries
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // Update query
            int idx, val;
            cin >> idx >> val;
            update(0, 0, n - 1, idx, val);
        } else if (type == 2) { // Range sum query
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}
