#include <bits/stdc++.h>
using namespace std;
class Solution{
    private:
       int timer=0;
       void dfs(int node,int parent,int tin[],int low[],vector<int> &vis,vector<int> &mark,vector<int> adj[]){
           vis[node]=1;
           tin[node]=low[node]= timer;
           timer++;
           int child=0;
           for(auto it:adj[node]){
             if(it==parent) continue;
             if(!vis[it]){
                dfs(it,node,tin,low,vis, mark,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent==-1){
                    mark[node]=1;
                }
                child++;
             }else{
                 low[node]=min(low[node],tin[it]);
              }

           }
           if(child>1 && parent==-1){
                   mark[node]=1;
           }                                                                                                         
       }
     public:
         vector<int> articulationPoints(int n,vector<int> adj[]){
            vector<int> vis(n,0);
            int tin[n];
            int low[n];
            vector<int> mark(n,0);
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    dfs(i,-1,tin,low,vis,mark,adj);
                }
            }
            for(int i=0;i<n;i++){
                if(mark[i]==1){
                    ans.push_back(i);
                }
            }
            return ans;

         }//hello
};