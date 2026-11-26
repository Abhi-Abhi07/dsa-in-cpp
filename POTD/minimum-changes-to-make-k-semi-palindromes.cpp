// Problem link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/

class Solution {
public:
    vector<vector<int>> cost_memo;
    vector<vector<int>> memo;
    int getCost(int &i, int &j, string &s){
        if(cost_memo[i][j] != -1)
            return cost_memo[i][j];

        int len = j - i + 1;
        int min_cost = INT_MAX;
        for(int d=1; d<=(len/2); d++){
            if(len % d != 0)    
                continue;
                
            int cost = 0;
            for(int g=0; g<d; g++){
                int l = g + i;
                int r = len - d + g + i;
                while(l < r){
                    if(s[l] != s[r])
                        cost++;
                    l += d;
                    r -= d;
                }
            }
            min_cost = min(min_cost, cost);
        }

        return cost_memo[i][j] = min_cost;
    }
    int solve(int st, int &n, string &s, int k){
        if(k == 0){
            if(st == n)  return 0;
            else return INT_MAX;
        }

        // early return -> not possible to make k subStr
        if(st + 2*k > n) return INT_MAX;

        if(memo[st][k] != -1)
            return memo[st][k];

        int min_cost = INT_MAX;
        for(int ed=st+1; ed<n; ed++){
            int rem_cost = solve(ed+1,n,s,k-1);
            if(rem_cost == INT_MAX) continue;

            int cost = getCost(st,ed,s);
            min_cost = min(min_cost, rem_cost + cost);
        }

        return memo[st][k] = min_cost;
    }
    int minimumChanges(string s, int k) {
        int n = s.length();
        cost_memo.assign(n,vector<int>(n,-1));
        memo.assign(n,vector<int>(k+1,-1));
        return solve(0,n,s,k);
    }
};