#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define vb vector<bool>


vi ar[100001];
int vis[100001];
// dfs
void dfs(int v){
   vis[v]=1;
   for(int i=1;i<adj[v].size();i++){
       int child=adj[v][i];
       if(child==0){
           dfs(child);
       }
   }
}

// Bipartite graph -> divide vertex set into two different sets such that each vertex belongs
// to exactly one of the two sets and the edge connects the two different vertices from two different sets
