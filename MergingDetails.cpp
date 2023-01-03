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
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        unordered_map<string,int> mailDetail;
       
        int n=details.size();
         DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<details[i].size;j++){
                string mail=details[i][j];
                if(mailDetail.find(mail)==mailDetail.end()){
                    mailDetail[mail]=i;
                }else{
                      ds.UnionBySize(i,mailDetail[mail]);
                }
            }
        }
        vector<string> arr[n];
        for(auto it:mailDetail){
            string st=it.first;
            int node=ds.findUPar(it.second);
            arr[node].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(arr[i].size()==0)continue;
            sort(arr[i].begin(),arr[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it:arr[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
    }
};