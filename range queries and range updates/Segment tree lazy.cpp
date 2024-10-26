#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5; // Maximum number of elements in the array
int tree[4 * MAXN];   // Segment tree array
int lazy[4 * MAXN];   // Lazy array for deferred updates
int n;                 // Size of the array

// Build the segment tree from the initial array
void build(const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

// Apply pending updates and propagate if needed
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        
        if (start != end) { // Not a leaf node
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// Range update: add `val` to elements in range [l, r]
void range_update(int node, int start, int end, int l, int r, int val) {
    propagate(node, start, end);

    if (start > r || end < l) {
        return; // Out of range
    }
    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;

        if (start != end) { // Not a leaf node
            lazy[2 * node + 1] += val;
            lazy[2 * node + 2] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    range_update(2 * node + 1, start, mid, l, r, val);
    range_update(2 * node + 2, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

// Range sum query: get sum in range [l, r]
int range_query(int node, int start, int end, int l, int r) {
    propagate(node, start, end);

    if (start > r || end < l) {
        return 0; // Out of range
    }
    if (start >= l && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int leftSum = range_query(2 * node + 1, start, mid, l, r);
    int rightSum = range_query(2 * node + 2, mid + 1, end, l, r);
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
        if (type == 1) { // Range update
            int l, r, val;
            cin >> l >> r >> val;
            range_update(0, 0, n - 1, l, r, val);
        } else if (type == 2) { // Range sum query
            int l, r;
            cin >> l >> r;
            cout << range_query(0, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}
