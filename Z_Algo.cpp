#include <bits/stdc++.h>
using namespace std;
vector<int> calculateZ(vector<int> &arr){
    int n=arr.size();
    vector<int>Z_arr(n,0);
    int l=0,r=0;
    for(int k=1;k<n;k++){
        if(k>r){
            l=r=k;
            while(r<n && arr[r]==arr[r-l]){
                r++;
            }
            Z_arr[k]=right-left;
            right--;
        }else{
            int k1=k-l;
            if(Z_arr[k1]<right-k+1){
                Z_arr[k]=Z_arr[k1];
            }else{
                l=k;
                while(r<n && arr[r]==arr[r-l]){
                    r++;
                }
                Z_arr[k]=r-l;
                r--;
            }
        }
    }
    return Z_arr;

}
vector<int> giveAnswer(string &txt, string &pattern){
    string str(txt.size()+pattern.size()+1,0);
    int i=0;
    for(auto pt:pattern){
        str+=pt;
        i++;
    }
    str[i]='$';
    for(auto t:txt){
        str+=t;
        i++;
    }
    vector<int> ans;
    vector<int> Z_arr=calculateZ(str);
    for(int i=0;i<Z.size();i++){
        if(Z_arr[i]==pattern.size()){
            ans.push_back(i-patter.size()-1);
        }
    }
    return ans;
}