#include <bits/stdc++.h>
using namespace std;
int prime=101;
int patternSearch(string &text, string &pattern){
    int m=pattern.length();
    int n=text.length();
    long patternHash=createHash(pattern,m-1);
    long textHash=createHash(text,m-1);
    // 0 1 2 3 4 5
    for(int i=1;i<=n-m+1;i++){
        if(patternHash==textHash && checkEqual(text,i-1,i+m-2,pattern,0,m-1)){
            return i-1;
        }
        if(i<n-m+1){
            textHash=recaulcateHash(text,i-1,i-1+m,textHash,m);
        }
    }
    return -1;
}
long createHash(string &str, int end){
    long hash=0;
    
    for(int i=0;i<=end;i++){
        hash+=str[i]*pow(prime,i);
    }
    return hash;
}
long recalculateHash(string &str,int oldIndex,int newIndex, long oldHash, int patternLen){
    long newHash=oldHash-str[oldIndex];
    newHash=newHash/prime;
    newHash+=str[newIndex]*pow(prime,patternLen-1);
    return newHash;
}
bool checkEqual(string &str1, int start1, int end1, string &str2,int start2,int end2){
    if(end1-start1 !=end2-start2){
        return false;
    }
    while(start1<=end1 && start2<=end2){
        if(str1[start1]!=str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}