// Problem link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/

class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll x = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        if(need1 < need2)
            return min({x, 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1), 1LL * costBoth * need2});
        else
            return min({x, 1LL * costBoth * need2 + 1LL * cost1 * (need1 - need2), 1LL * costBoth * need1});
    }
};