#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
       int timer=1;
    private:
       void dfs(int node,int parent,vector<int>adj[],vector<int> &vis,int low[],int instime[],vector<vector<int>> &bridge){
             vis[node]=1;
             instime[node]=low[node]=timer;
             timer++;
             for(auto it:adj[node]){
                if(it==parent)continue;
                if(!vis[it]){
                    dfs(it,node,adj,vis,low,instime,bridge);
                    if(low[it]>instime[node]){
                         bridge.push_back({it,node})
                    }
                }else{
                    low[node]=min(low[node],low[it]);
                }
             }



       }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         vector<int> adj[n];
         for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
         }
         vector<int> vis(n,0);
         int instime[n];
         int low[n];
         vector<vector<int>> bridge;
         dfs(0,-1,adj,vis,low,instime,bridge);
         return bridge;     
    }
};