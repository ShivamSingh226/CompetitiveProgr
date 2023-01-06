#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
   
    public:
     vector<int> rank,parent,size;
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
private:
 bool isValid(int newr,int newc,int n){
   return newr>=0 && newr<n && newc>=0 && newc<n ;
 }    
public:

    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int dr[]={-1,1,0,0};
                int dc[]={0,0,1,-1};
                for(int ind=0;ind<4;ind++){
                     int newr=i+dr[ind];
                     int newc=j+dc[ind];
                     if(isValid(newr,newc,n) && grid[newr][newc]){
                         int node=i*n+j;
                         int adnode=newr*n+newc;
                         ds.UnionBySize(node,adnode);
                     }
                }
            }
        }
        int mx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                 int dr[]={-1,1,0,0};
                int dc[]={0,0,1,-1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                     int newr=i+dr[ind];
                     int newc=j+dc[ind];
                     if(isValid(newr,newc,n) && grid[newr][newc]){
                         int node=i*n+j;
                         int adnode=newr*n+newc;
                         components.insert(ds.findUPar(adnode));
                     }
                }
                int sizetotal=0;
                for(auto it:components){
                    sizetotal+=ds.size[it];
                }
                mx=max(mx,sizetotal+1);
            }

        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};