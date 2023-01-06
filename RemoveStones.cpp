#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }


        }
        int findUPar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUPar(parent[node]);
        }
        void UnionByRank(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
             if(ulp_u==ulp_v)return;
             if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
             }
             else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
             }else{
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
             }
        }
         void UnionBySize(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
             if(ulp_u==ulp_v)return;
             if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
             }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
             }
         }

};
class Solution{
     public:
     int maxRemove(vector<vector<int>> &stones,int n){
       int rows=0;
       int cols=0;
       for(auto it:stones){
        rows=max(rows,it[0]);
        cols=max(cols,it[1]);
       }
       unordered_map<int,int>mp;
       DisjointSet ds(rows+cols+1);
       for(auto it :stones){
        int node1=it[0];
        int node2=it[1]+rows+1;
        ds.UnionBySize(node1,node2);
        mp[node1]=1;
        mp[node2]=1;

       }
       int cnt=0;
       for(auto it:mp){
        if(ds.findUPar(it.first)==it.first){
            cnt++;
        }
       }
       return n-cnt;



     }
};