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
    private:
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nr<n && nc>=0 && nc<m; 
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int row=it[0]
            int col=it[1];
            if(visited[row][col]){
                ans.push_back(cnt);
                continue;
            }
            visited[row][col]=1;
            cnt++;
            //row-1,col
            // row+1,col
            //row,col-1
            //row,col+1
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            for(int j=0;j<4;j++){
                int nr=row+dr[j];
                int nc=col+dc[j];
                if(isValid(nr,nc,n,m)){
                    if(visited[nr][nc]){
                        int node1=row*m+col;
                        int node2=nr*m+nc;
                        if(ds.findUPar(node1)!=ds.findUPar(node2)){
                            cnt--;
                            ds.UnionBySize(node1,node2);
                        }
                    }
                }


            }
            ans.push_back(cnt);



        }
        
        return ans;
    }   
};