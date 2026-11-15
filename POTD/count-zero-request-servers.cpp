// Problem link: https://leetcode.com/problems/count-zero-request-servers/

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>>qs;
        for(int i=0; i<queries.size(); i++)
            qs.push_back({queries[i],i});
        
        sort(qs.begin(),qs.end());

        vector<int>res(qs.size(),0);
        vector<int>cnt(n+1,0);
        int left = 0, right = 0;
        int k = 0;

        int size = logs.size();
        for(pair<int,int> &q: qs){
            int currS = q.first - x;
            int currE = q.first;

            // Shrink the window
            while(left < size && logs[left][1] < currS){
                if(--cnt[logs[left][0]] == 0) k--;
                left++;
            }

            // Expend the window
            while(right < size && logs[right][1] <= currE){
                if(cnt[logs[right][0]] == 0)
                    k++;
                cnt[logs[right][0]]++;
                right++;
            }

            res[q.second] = n - k;
        }
        return res;
    }
};