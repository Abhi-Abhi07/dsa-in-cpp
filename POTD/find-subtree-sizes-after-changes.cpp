// Problem link: https://leetcode.com/problems/find-subtree-sizes-after-changes/

class Solution {
public:
    vector<vector<int>> adjList;

    void dfs(int node,int p,vector<int> v,vector<int>&parent,string &s){
        for(auto &neigh: adjList[node]){
            if(neigh == p) continue;
            v[s[node]-'a'] = node;
            dfs(neigh,node,v,parent,s);
            if(v[s[neigh]-'a'] != -1)
                parent[neigh] = v[s[neigh]-'a'];
        }
    }

    void dfsSubtreeSize(int node,int p,vector<int>&subtree_sizes){
        subtree_sizes[node] = 1;
        for(auto &neigh: adjList[node]){
            if(neigh == p) continue;
            dfsSubtreeSize(neigh,node,subtree_sizes);
            subtree_sizes[node] += subtree_sizes[neigh];
        }
    }

    void makeAdjList(vector<int> &parent,int &n){
        adjList.assign(n,{});
        for(int i=1; i<n; i++){
            adjList[i].push_back(parent[i]);
            adjList[parent[i]].push_back(i);
        }
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        makeAdjList(parent,n);
        vector<int> v(26,-1);
        dfs(0,-1,v,parent,s);

        makeAdjList(parent,n);
        vector<int> subtree_sizes(n,0);
        dfsSubtreeSize(0,-1,subtree_sizes);
        return subtree_sizes;
    }
};