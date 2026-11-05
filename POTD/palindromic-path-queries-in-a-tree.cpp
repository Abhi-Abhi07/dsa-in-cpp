// problem link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/description/

class Solution {
public:
    int time;
    vector<int>tin, tout, eulerTour;

    vector<int>segTree;

    int cols;
    vector<int>depth;
    vector<vector<int>>ancestorTable;
    
    void buildEulerTourDFS(int node,int parent,unordered_map<int,list<int>> &adj, string &s,int d){
        depth[node] = d;
        ancestorTable[node][0] = parent;

        tin[node] = time;
        eulerTour[time] = 1 << ((int)(s[node] - 'a'));
        time++;
        for(auto &neigh: adj[node]){
            if(neigh == parent)  continue;
            buildEulerTourDFS(neigh,node,adj,s,d+1);
        }
        tout[node] = time;
        eulerTour[time] = 1 << ((int)(s[node] - 'a'));
        time++;
    }

    void buildSegmentTree(int i, int s, int e){
        if(s == e){
            segTree[i] = eulerTour[s];
            return;
        }

        int mid = s + (e-s)/2;
        buildSegmentTree(2*i + 1, s, mid);
        buildSegmentTree(2*i + 2, mid+1, e);

        segTree[i] = segTree[2*i + 1] ^ segTree[2*i + 2];
    }

    int querySegmentTree(int i, int s, int e, int l, int r){
        if(e < l || s > r) 
            return 0;
        if(l <= s && e <= r) 
            return segTree[i];

        int mid = s + (e-s)/2;
        int left = querySegmentTree(2*i + 1, s, mid, l, r);
        int right = querySegmentTree(2*i + 2, mid+1, e, l, r);

        return left ^ right;
    }

    void updateSegmentTree(int i, int s, int e, int idx, int val){
        if(s == e){
            segTree[i] = val;
            return;
        }

        int mid = s + (e-s)/2;
        if(idx <= mid)
            updateSegmentTree(2*i + 1, s, mid, idx, val);
        else
            updateSegmentTree(2*i + 2, mid+1, e, idx, val);

        segTree[i] = segTree[2*i + 1] ^ segTree[2*i + 2];
    }

    void buildAncestorTable(int &n){
        for(int j=1; j<cols; j++){
            for(int node = 0; node < n; node++){
                if(ancestorTable[node][j-1] != -1){
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
    }

    int getLCA(int u,int v){
        if(depth[u] < depth[v]) swap(u,v);

        int diff = depth[u] - depth[v];
        for(int j=0; j<cols; j++){
            if(diff & (1 << j)){
                u = ancestorTable[u][j];
            }
        }

        if(u == v)  return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        unordered_map<int,list<int>> adj;
        for(vector<int> &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        time = 0;
        tin.assign(n,0);
        tout.assign(n,0);
        eulerTour.assign(2*n,0);

        depth.assign(n,0);
        cols = log2(n) + 1;
        ancestorTable.assign(n,vector<int>(cols,-1));
        buildEulerTourDFS(0,-1,adj,s,0);
        buildAncestorTable(n);

        int size = 2*n;
        segTree.assign(4 * size, 0);
        buildSegmentTree(0,0,size-1);

        vector<bool>res;
        for(string &q: queries){
            stringstream ss(q);
            string type;
            ss >> type;
            if(type == "query"){
                int u, v;
                ss >> u >> v;

                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int charValue = (1 << (ch - 'a'));

                int mask = querySegmentTree(0, 0, 2*n-1, 0, tin[u]) ^
                        querySegmentTree(0, 0, 2*n-1, 0, tin[v]) ^
                        charValue;
                
                res.push_back((mask & (mask-1)) == 0); 
            }else{
                int node;
                char ch;

                ss >> node >> ch;

                int charValue = (1 << (ch - 'a'));
                s[node] = ch;
                updateSegmentTree(0, 0, 2*n-1, tin[node], charValue);
                updateSegmentTree(0, 0, 2*n-1, tout[node], charValue);
            }
        }

        return res;
    }
};