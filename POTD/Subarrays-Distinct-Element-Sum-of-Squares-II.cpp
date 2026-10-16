/*
Problem link : https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/description/
*/

class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    vector<ll>lazy, sumSegTree,  sqrSumSegTree;

    void push(int node,int s,int e){
        if(lazy[node] == 0) return;

        int val = lazy[node];
        int len = e - s + 1;
        sqrSumSegTree[node] = (sqrSumSegTree[node] +  2 * val * sumSegTree[node] + len * val * val) % MOD;
        sumSegTree[node] = (sumSegTree[node] + val * len) % MOD;
        if(s != e){
            lazy[node*2 + 1] += lazy[node];
            lazy[node*2 + 2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int i,int s,int e,int l,int r){
        //lazy insertion
        push(i,s,e);

        // completely out of range
        if(r < s || l > e || l > r)  return;

        // within range
        if(l <= s && e <= r){
            lazy[i] += 1;
            push(i,s,e);
            return;
        }

        int mid = s + (e-s)/2;
        update(i*2 + 1, s, mid, l, r);
        update(i*2 + 2, mid+1, e, l, r);

        sqrSumSegTree[i] = (sqrSumSegTree[i*2 + 1] + sqrSumSegTree[i*2 + 2]) % MOD;
        sumSegTree[i] = (sumSegTree[i*2 + 1] + sumSegTree[i*2 + 2]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        lazy.assign(4*n, 0);
        sumSegTree.assign(4*n, 0);
        sqrSumSegTree.assign(4*n, 0);

        int res = 0;
        vector<int>lastSeen(1e5+1, -1);
        for(int i=0; i<n; i++){
            int l = lastSeen[nums[i]] + 1;
            int r = i;
            update(0,0,n-1,l,r);

            res = (1LL * res + sqrSumSegTree[0]) % MOD;
            lastSeen[nums[i]] = i;
        }
        return res;
    }
};