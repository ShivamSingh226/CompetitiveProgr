#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long int
#define vi vector<int>
#define f(i,a,b) for(int i=a;i<b;i++)
void construct_sgt(vi &a, vi &sgt, int n ){
    f(i,0,n){
        sgt[n+i]=a[i];
    }
    for(int i=n-1;i>=1;i--){
        sgt[i]=min(sgt[2*i],sgt[2*i+1]);
    }

}
void update(vi &sgt, int val, int pos, int n){
    pos+=n;

    sgt[pos]=val;
    while(pos>1){
        pos>>=1;
        sgt[pos]=min(sgt[2*pos],sgt[2*pos+1]);
    }
}
int range_query(vi &sgt, int left, int right, int n){
    left+=n;
    right+=n;
    int mi=(int)1e9;
    while(left<=right){
        if(left&1){
            mi=min(mi,sgt[left]);
        }
        left++;
        if(!(right&1)){
            right--;
            mi=min(mi,sgt[right]);
        }

        left>>=1;
        right>>=1;
    }
    return mi;
}
int32_t main(){
    return 0;
     vector<int> a = { 2, 6, 10, 4, 7, 28, 9, 11, 6, 33 };
    int n = a.size();
  
    /* Construct the segment tree by assigning
       the values to the internal nodes*/
    vector<int> segtree(2 * n);
    construct_sgt( a,segtree, n);
    return 0;
}
