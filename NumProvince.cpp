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
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
          DisjointSet ds(V);
          for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.UnionBySize(i,j);
                }
            }
          }
          int cntt=0;
          for(int i=0;i<V;i++){
            if(ds.findUPar(i)==i){
                cntt++;
            }
          }
          return cntt;    // code here

    }
};