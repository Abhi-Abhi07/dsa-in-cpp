// Problem link: https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/

class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>cum_sum(n,nums[0]);
        for(int i=1; i<n; i++)
            cum_sum[i] = nums[i] + cum_sum[i-1];

        auto rangeSum = [&](int i, int j) -> ll{
            if(i > j)   return 0;
            return i > 0 ? cum_sum[j] - cum_sum[i-1] : cum_sum[j];
        };

        stack<int> s;
        vector<int> NGR(n,n);
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                NGR[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        vector<ll> op(n+1,0);
        for(int i=n-1; i>=0; --i){
            int m = NGR[i];
            ll seg_op = (1LL * nums[i] * (m-i)) - rangeSum(i,m-1);
            op[i] = seg_op + op[m];
        }

        ll res = 0;
        int i=0, j=0;
        deque<int> dq;
        while(j < n){
            while(!dq.empty() && nums[dq.back()] <= nums[j])
                dq.pop_back();

            dq.push_back(j);
            while(i <= j){
                int m = dq.front();
                ll opr_cnt = (op[i] - op[m]) + (1LL * nums[m] * (j-m+1) - rangeSum(m,j));

                if(opr_cnt <= k)    break;

                // shrink the window
                i++;
                if(dq.front() < i)  dq.pop_front();
            }

            res += (j - i + 1);
            j++;
        }
        return res;
    }
};