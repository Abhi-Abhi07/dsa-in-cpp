// problem link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

class Solution {
public:
    typedef pair<int,int> P; // {finishTime, server}
    priority_queue<P, vector<P>, greater<P>> busy_servers;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0; i<k; i++)
            available_servers.insert(i);

        vector<int> cnt_requests(k,0);
        int n = arrival.size();
        for(int i=0; i<n; i++){
            int time = arrival[i];
            while(!busy_servers.empty() && busy_servers.top().first <= time){
                available_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }

            if(available_servers.empty()) continue;

            int target = i % k;
            set<int>::iterator it = available_servers.lower_bound(target);
            if(it == available_servers.end())
                it = available_servers.begin();

            busy_servers.push({time + load[i], *it});
            cnt_requests[*it]++;

            available_servers.erase(it);
        }

        vector<int> ans;
        int max_request = *max_element(begin(cnt_requests), end(cnt_requests));
        for(int i=0; i<k; i++)
            if(cnt_requests[i] == max_request)
                ans.push_back(i);

        return ans;
    }
};