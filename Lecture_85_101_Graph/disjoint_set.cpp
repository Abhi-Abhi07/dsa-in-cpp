#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node])    return node;
        // return findUltimateParent(parent[node]); // normal take o(log n) time
        return parent[node] = findUltimateParent(parent[node]); // path compression take o(4 alpha) time (alpha nearly 1)
    }

    void unionByRank(int u,int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return; // both are in same component

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return; // both are in same component

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main(){
    DisjointSet ds(7), ds2(8);
    cout<<"***union by rank***"<<endl;
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Both are in same component"<<endl;
    }else{
        cout<<"Both are not in same component"<<endl;
    }

    ds.unionByRank(3,7);
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Both are in same component"<<endl;
    }else{
        cout<<"Both are not in same component"<<endl;
    }

    cout<<"***union by size***"<<endl;
    ds2.unionBySize(1,2);
    ds2.unionBySize(2,3);
    ds2.unionBySize(4,5);
    ds2.unionBySize(6,7);
    ds2.unionBySize(5,6);
    if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7)){
        cout<<"Both are in same component"<<endl;
    }else{
        cout<<"Both are not in same component"<<endl;
    }

    ds2.unionBySize(3,7);
    if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7)){
        cout<<"Both are in same component"<<endl;
    }else{
        cout<<"Both are not in same component"<<endl;
    }
    return 0;
}