#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<int>&vis,vector<int> adj[],stack<int> &st){
          vis[node]=1;
          for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,visited,adj,st);
            }
          }
          st.push(node);
    }
    private:
    void dfs3(int node,vector<int>&vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    public:
    int kosaroju(int V,vector<int> adj[]){
          vector<int> &vis(V,0);
          stack<int> st;
          for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
          }
          vector<int> adjT[];
          for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
          }
          int scc=0;
          while(!st.empty){
            int start=st.top();
            st.pop();
            if(!vis[start]){
                
                    scc++;
                    dfs3(start,vis,adjT);
                
            }
          }
          return scc;

    }
};