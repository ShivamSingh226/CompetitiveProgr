#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long int
#define vi vector<int>
#define f(i,a,b) for(int i=a;i<b;i++)
const int N=1000;
int lazy[N]={0};
int tree[N]={0};
// l, r to update the value
void rangeUpdate(int ind, int low,int high, int l, int r, int val){
   if(lazy[ind]!=0){
       seg[ind]+=(high-low+1)*lazy[ind];
       if(low!=high){
           lazy[2*ind+1]+=lazy[ind];
           lazy[2*ind+2]+=lazy[ind];
       }
       lazy[ind]=0;
   }
   if(r<low || l>high || low>high) return;
   if(low>=l && high<=r){
       seg[ind]+=(high-low+1)*val;
       if(low!=high){
           lazy[2*ind+1]+=lazy[ind];
           lazy[2*ind+2]+=lazy[ind];
       }
       return;
   }
   int mid=(high+low)>>1;
   rangeUpdate(2*ind+1,low, mid,l,r,val);
   rangeUpdate(2*ind+2, mid+1, high, l, r, val);
   seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}
int querySumLazy(int ind, int low, int high, int l, int r, int val){
      if(lazy[ind]!=0){
          seg[ind]+=(high-low+1)*lazy[ind];
          if(low!=high){
              lazy[2*ind+1]+=lazy[ind];
              lazy[2*ind+2]+=lazy[ind];
          }
          lazy[ind]=0;
      }
      if(low>r || high<l|| low>high) return;
      if(low>=l &&high<=r){
          return seg[ind];
      }
      int mid=(high+low)>>1;
      return querySumLazy(2*ind+1, low, mid, l,r, val)+querySumLazy(2*ind+2,mid+1,high,l,r,val);
      int main(){
          int n;
          cin>>n;
          f(i,0,n){
              cin>>a[i];
          }
          
      }
}