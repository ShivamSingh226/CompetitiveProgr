#include <bits/stdc++.h>
using namespace std;
vector<int> computeTemp(string &pattern){
    int n=pattern.length();
    vector<int> lps(n,0);
    int index=0;
    for(int i=1;i<n;){
        if(pattern[i]==pattern[index]){
            lps[i]=index+1;
            index++;
            i++;
        }else{
            if(index!=0){
                index=lps[index-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
bool computeKMP(string &text, string &pattern){
    vector<int> lps=computeTemp(pattern);
    int i=0,j=0;
    while(i<text.length() && j<pattern.length()){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    if(j==pattern.length())return true;
    else return false;
}