#include<iostream>
#include<vector>

using namespace std;

// Standard Recursive Segment Tree with Lazy Propagation
struct SegmentTree {
    int n;
    vector<int> tree, lazy;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (r < start || l > end) return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        push(node, start, end);
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = query(node * 2, start, mid, l, r);
        int rightMax = query(node * 2 + 1, mid + 1, end, l, r);
        return max(leftMax, rightMax);
    }

    // Helper functions to call from outside with 0-based indexing
    void updateRange(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main(){
    vector<int>arr = {2,3,1,4,2,5,2,3,1,5};
    int n = arr.size();
    SegmentTree seg(n);
}