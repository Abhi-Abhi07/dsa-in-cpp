Problem link: https://leetcode.com/problems/process-tasks-using-servers/

class Solution {
public:
    typedef pair<int, int> P; //wt, idx
    typedef tuple<long, int, int> T; //finTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        //free servers (wt, idx)
        priority_queue<P, vector<P>, greater<P>> freeServers;

        ///Busy servers {fintTime, wt, idx}
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++)
            freeServers.push({servers[i], i}); 

        vector<int> res(m);
        for(int i = 0; i < m; i++) { 
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }
            if(freeServers.empty()) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                res[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            } else { 
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                res[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }
        return res;
    }
};
