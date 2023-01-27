#include <bits/stdc++.h>
using namespace std;
// Directed Acyclic Graph is used for topological sorting
class Solution{
    private:
       void toposortfunc(vector<int> &vis,stack<int> &st,int v,vector<int> adj[]){
        vis[v]=1;
        for(auto it:adj[v]){
            if(!vis[it]){
                toposortfunc(vis,st,it,adj);
            }
        }
        st.push(v);


       }
    public:
        vector<int> toposort(int v, vector<int> graph[]){
           vector<int> adj[];
           stack<int> st;
           for(auto it: graph){
            adj[it[0]].push_back(it[1]);
           }
           vector<int> vis(v);
           for(int i=0;i<v;i++){
            if(!vis[i]){
                toposortfunc(vis,st,i,adj);
            }
           }
           vector<int> ans;
           while(!st.empty()){
                int ad=st.top();
                ans.push_back(ad);
                st.pop();
           }
           return ans;
        }
};