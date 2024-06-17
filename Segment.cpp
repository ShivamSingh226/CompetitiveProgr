#include <bits/stdc++.h>
using namespace std;
bool isPeak(vector<int> &nums, int ind){
    if(find(nums.begin(),nums.end(),ind)!=nums.end()){
        return true;
    }
    return false;
}
class SegmentTree{
    private:
        vector<int> tree;
        int n;
        void build(vector<int> &nums,int low,int high,int node){
            if(high==low){
                tree[node]=isPeak(nums,high)?1:0;
            }else{
                int mid=(low+high)>>1;
                build(nums,low,mid,2*node+1);
                build(nums,mid+1,high,2*node+2);
                tree[node]=tree[2*node+1]+tree[2*node+2];
            }
        }
        void update(vector<int> &nums,int low,int high,int node,int idx){
             if(low==high){
                tree[node]=isPeak(nums,idx)?1:0;
             }
             int mid=(low+high)>>1;
             if(idx>=low && idx<=mid){
                update(nums,low,mid,2*node+1,idx);
             }else{
                update(nums,mid+1,high,2*node+2,idx);
             }
             tree[node]=tree[2*node+1]+tree[2*node+2];
        }
        int query(int node,int low, int high,int l,int r){
            if(l>high || r<low){
                return 0;
            }
            if(l>=low && r<=high){
                return tree[node];
            }
            int mid=(low+high)>>1;
            int left_query=query(2*node+1,low,mid,l,r);
            int right_query=query(2*node+2,mid+1,high,l,r);
            return left_query+right_query;
        }
        public:
            SegmentTree(vector<int> &nums){
                n=nums.size();
                tree.resize(4*n);
                build(nums,0,n-1,0);
            }
            void update(vector<int> &nums,int idx){
                update(nums,0,n-1,0,idx);
            }
            int query(int l,int r){
                return query(0,0,n-1,l,r);
            }
};
int main(){
    return 0;
}