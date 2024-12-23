#include <bits/stdc++.h>
using namespace std;
// Manacher's Algo
int longestPalindromicSubstr(string &str){
    int index=0;
    vector<char> newInput(2*str.length()+1,0);
    for(int i=0;i<newInput.size();i++){
        if(i&1){
            newInput[i]=str[index++];
        }else{
            newInput[i]='$';
        }
    }
    vector<int> T(newInput.size(),0);
    int start=0;
    int end=0;
    for(int i=0;i<newInput.size();){
        while(start>0 && end<newInput.size()-1 && newInput[start-1]==newInput[end+1]){
            start--;
            end++;
        }
        T[i]=end-start+1;
        if(end==T.size()-1){
            break;
        }
        int newCenter=end+ (i%2==0?1:0);
        for(int j=i+1;j<=end;){
            // if it is exceeding the left limit
            T[j]=min(T[i-(j-i)],2*(end-j)+1);
            // if it is extending till the right bound and if the substring is the prefix of the palindromic window
            if(j+T[i-(j-i)]/2==end){
                newCenter=j;
                break;
            }
        }
        i=newCenter;
        start=i-T[i]/2;
        end=t+T[i]/2;

    }
    int mx=INT_MIN;
    for(int i=0;i<T.size();i++){
        int val=T[i]/2;
        mx=max(mx,val);
    }
    return mx;

}