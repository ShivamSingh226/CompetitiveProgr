#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define int long long
#define lld long  double
#include <queue>
//#define lint int
#define f(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,n) for(int i=a;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pb push_back
const int mod=998244353;
//998244353
//1e9+7
int mx=998244353;
int power(int x, int n) {
    if(n==0)return 1;
    if(n==1)return x;
    int ret=power(x,n/2);
    if(n%2==0)return (ret*ret)%mx;
    else return ((ret*ret)%mx*x)%mx;
}

vi fac(2e5+5,1);
int inv(int a){
    return (power(a,mod-2)%mod+mod)%mod;
}
int binom(int x,int y){
    if(x<0 || y<0)return 0;
    return (((fac[x]*inv(fac[y]))%mod *inv(fac[x-y]))%mod+mod)%mod;
}





bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
//vector<int> a[mod];

//int a[1000005];
//int b[1000005];
    //bool check(int mid){
    //  int k=mid-mid/4;
  //      int ti=n-min(n,k);
    //    int sum=0;
      //  for(int i=n-1;i>=ti;i--){
          //  sum+=b[i];
        //}
        //int tin=0;
        //int ahead=min(k,mid-n);
        //k-=ahead;
        //tin=ahead*100;
        //int zz=n-1;
        //while(zz>=0 && k-- ){
          //  tin+=a[zz];
            //zz--;

        //}
        //return tin>=sum;
    //}

string ffs(int i){
    if(i==0)return "";
    else return ffs((i-1)/26) +char((i-1)%26+'a');
}


const int ftr=4e5+5;
const int mod22=1e9+7;
bool checkcycle[ftr];
vector<int>adj[ftr];
void rotatecycle(int y){
     checkcycle[y]=true;
     for(auto x:adj[y]){
         if(!checkcycle[x])rotatecycle(x);
     }

}

// bool isPal(string &str){
//     int l=0;
//     int h=(int)str.size()-1;
//     while(l<h){
//         if(str[l++]!=str[h--]){
//             return false;
//         }

//     }
//     return true;
// }
int xxxor(int n){
    if(n%4==0){
        return n;
    }
    if(n%4==1){
        return 1;
    }
    if(n%4==2){
        return n+1;
    }
    return 0;
}



      
     
  
  
   

   

   
   

   
   
   
   

  // while(n){
    //   int r=n%10;
      // if(i%2==0){
        //   a=r*c1+a;
          // c1*=10;
       //}else{
         //  b=r*c2+b;
           //c2*=10;
       //}
       //n=n/10;
       //i++;
   //}
   //cout<<(a+1)*(b+1)-2<<'\n';




    
    
    



bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second<b.second);
}
bool sortbysecgt(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second>b.second);
}         

const int mmt=998244353;
int factorial(int n){
    int res=1;
    for(int i=1;i<=n;i++){
        res=(res*i)%mmt;
    }
    return res;
} 

bool isPal(vi &a){
    int n=a.size();
    int i=0,j=n-1;
    while(i<j){
        if(a[i]!=a[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
bool check(vi &z,int x){
    int n=z.size();
    vi b;
    f(i,0,n){
        if(z[i]!=x){
            b.pb(z[i]);
        }
    }
    bool ans=isPal(b);
    return ans;
}
bool helper(int mid,vi &a,vi &b){
    int people=0;
    int n=a.size();
    f(i,0,n){
        if(people<=b[i]&& mid-people-1<=a[i]){
            people++;
        }
    }
    return people>=mid;
}
const int inf=1e18;
void solve(){
   int n,l,k;
   cin>>n>>l>>k;
   vi d(n+1);
   f1(i,1,n){
       cin>>d[i];
   }
   vi a(n+1);
   f1(i,1,n){
       cin>>a[i];
   }
   vvi dp(n+1,vi(k+1,inf));
   dp[1][0]=0;
   for(int i=2;i<=n;i++){
       dp[i][0]=dp[i-1][0]+(d[i]-d[i-1])*a[i-1];
       for(int j=1;j<=k;j++){
           for(int pre=i-1;pre>=1;pre--){
               // remove pre+1 to i-1
               // i-1-pre-1 +1
               // i-pre-1
               if(i-pre-1 <=j){
                   dp[i][j]=min(dp[i][j],dp[pre][j-(i-pre-1)]+a[pre]*(d[i]-d[pre]));
               }
           }
       }
   }
   int ans=inf;
   for(int j=0;j<=k;j++){
       for(int pre=n;pre>=1;pre--){
           if(n-pre<=j){
               ans=min(ans,dp[pre][j-(n-pre)]+a[pre]*(l-d[pre]));
           }
       }

   }
   cout<<ans<<'\n';







    // n%2==0

   

    

    
    // bi between 1 and 1e9
    // bi and bi+1 such that either bi divides bi+1 or bi+1 divides bi
    // from i=1 to n 2(ai-bi)(abs)<=S/2
    
    

     

}
bool hasit(vi &a,int x){
    int n=a.size();
    f(i,0,n){
        if(a[i]==x){
            return true;
        }
    }
    return false;
}
bool doit(int y,int x){
    while(y>0){
        y=y/2;
        if(y==x){
            return true;
        }
    }
    return false;
}
pair<string,int>pp[1000001];
bool checkstop(vi &a){
    int y=a.back();
   
    for(int i=0;i<a.size();i++){
        if(a[i]>y){
            return false;
        }
    }
    return true;
}
bool checksubs(string &substr,string &st){
    int n=st.size();
    int m=substr.size();
    int j=0;
    for(int i=0;i<n&&j<m;i++){
        if(st[i]==substr[j]){
            j++;
        }
    }
    return (j==m);
}
int damage(int &mid,vi &a){
    int n=a.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]>=mid){
            cnt+=mid;
        }else{
            cnt+=(a[i+1]-a[i]);
        }
    }
    return cnt;
}
int func(int n)
{
	return (n * (n + 1))/2;

}
bool palpal(string &s){
    int l=0;
    int h=(int)s.size()-1;
    while(l<h){
        if(s[l++]!=s[h--]){
            return 0;
        }
    }
    return 1;
}
int isPresent(vi &a,int x){
    int n=a.size();
    int ind=-1;
    f(i,0,n){
        if(a[i]==x){
            ind=i;
            break;
            
            
        }
    }
    return ind;
    

}

void helper(int start,int end, int depth,vi &a,vi &ans){
    if(start>end)return;
    int index;
    int val=INT_MIN;
    for(int j=start;j<=end;j++){
       if(a[j]>=val){
           val=a[j];
           index=j;
       }
    }
    ans[index]=depth;
    helper(start,index-1,depth+1,a,ans);
    helper(index+1,end,depth+1,a,ans);

}


int nextPrime(int &a){
    int ans=0;
    while(1){
        bool flag=0;
        for(int i=2;i*i<=a;i++){
            if(a%i==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            a++;
        }else{
            ans=a;
           break;
        }
    }
    return ans;
}
int vis[200005];
int mxy=INT_MIN;
void dfs(vi &a,int idx,int sum){

    if(idx>a.size()-1){
        return;
    }
    sum+=a[idx];
    if(vis[idx]!=-1){
        return;
    }
    if(sum>mxy){
        mxy=sum;
        vis[idx]=sum;
    }
    idx=idx+a[idx];
    dfs(a,idx,sum);


}
int myfun(int &x,int &y){
    return abs(x)>abs(y);
}
int query(int i,int j,int k){
    cout<<"? "<<i<<" "<<j<<" "<<k<<'\n';
    int ans;
    cin>>ans;
    return ans;
}
string funccom(int x){
    string ans="";
    int loop=x/26;
    int rem=x%27;
    while(loop){
        for(int i=97;i<=122;i++){
            ans+=(char)(i);
        }
        loop--;
    }
    for(int i=97;i<(97+rem);i++){
        ans+=(char)(i);
    }
    return ans;
}
bool valid(int k,string &s){
    int arr[4]={0};
    int n=(int)s.size();
    f(i,0,k-1){
        int ind=s[i]-'0';
        arr[ind]++;
    }
    f(i,k-1,n){
        int ind=s[i]-'0';
        arr[ind]++;
        if(arr[1]>0 && arr[2]>0 && arr[3]>0){
            return true;
        }
        ind=s[i-k+1]-'0';
        arr[ind]--;
    }
    return false;
}

    

void asquare(){
int n;
cin>>n;
int x;
cin>>x;
int a[n-1];
map<int,int> mpp;
f(i,0,n){
    
    cin>>a[i];
    mpp[a[i]]++;
}
int ans=n;
for(auto &z:mpp){
    
    if((z.first) %x==0 && mpp[(z.first)/x]){
          ans-=2*min(mpp[(z.first)/x],z.second);
          z.second-=min(mpp[(z.first)/x],z.second); 
          
    }
}
cout<<ans<<"\n";








}




























   // a+b+c=n and gcd(a,b)=c

//   vi steps(1001,INT_MAX);
//   steps[1]=0;
//   for(int i=1;i<=1000;i++){
//       for(int j=i;j>=1;j--){
//           int val=i+i/j;
//            if(val>1000){
//                break;
//            }
//            steps[val]=min(steps[val],1+steps[i]);
//       }
//
//   int n,m,k,q;
//   cin>>n>>m>>k>>q;
//   vector<pair<int,int>>pq(q);
//   f(i,0,q){
//       int x,y;
//       cin>>x>>y;
//       pq[i].first=x;
//       pq[i].second=y;
//   }
//   int ans=1;
//   set<int> r;
//   set<int> c;
//   for(int i=q-1;i>=0;i--){
//       bool fl=0;
//      if(!(r.count(pq[i].first))){
//          r.insert(pq[i].first);
//          fl=1;
//      }
//      if(!(c.count(pq[i].second))){
//          c.insert(pq[i].second);
//          fl=1;
//      }
//      if(fl){
//          ans=(ans*k)%998244353;
//      }
//      if(r.size()==n || c.size()==m){
//          break;
//      }
//   }
//   cout<<ans<<"\n";
  
//   if(k%2==0 ){
//       if(n%2==0){
//           cout<<"YES"<<"\n";
//           f(i,0,k){
//               cout<<(n/k)<<" ";
//           }
//           cout<<"\n";
//       }else{
//           cout<<"NO"<<"\n";
//       }

 
  
  
  

      
      
      
  








// cout<<*max_element(ans.begin(),ans.end())<<'\n';


// int ans=INT_MAX;
// for(auto &x:mp ){
//     vi temp=x.second;
//     sort(temp.begin(),temp.end());
//     int cnt=temp.size();
//     cnt++;
//     for(int i=0;i<temp.size()-1;i++){
//         if(abs(temp[i]-temp[i+1])==1){
//             cnt--;
//         }
//     }
//     if(temp.back()==n-1){
//         cnt--;
//     }
//     if(temp[0]==0){
//         cnt--;

//     }
    
    
//     ans=min(ans,cnt);
// }
// cout<<ans<<"\n";

 

 
 
  
  

  



//   for(int i=0;i<n;i++){
//       if(s[i]=='?'){

//       }
//   }



  
  

  
  
  
   

  


  

   
  
  

  
   
    
    


bool occurence(int i, string &s){
    if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
        return 1;
    }
    return 0;
}
void query(){
    int n,q,k;
    cin>>n>>q>>k;
    vi a(n);
    f(i,0,n){
        cin>>a[i];
    }
    vi ans(n);
    f(i,0,n){
        if(i==0 && n!=1){
            ans[i]=a[1]-2;
        }
        if(i!=0 && i!=n-1){
            ans[i]=a[i+1]-a[i-1]-2;
        }
    }
    vi pref(n);
    pref[0]=0;
    for(int i=1;i<n-1;i++){
        pref[i]=ans[i]+pref[i-1];
    }


    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        
        int x=a[l]-1;
        int y=k-a[r];
        int z=(a[r]-a[l]-1)-(r-l-1);
        cout<<x+y+2*z<<'\n';
    


    }
    
}
    
    


    
    

    

    

int32_t main(){
    


     unordered_map<int,int> mp;
mp[0]=0;
for(int i=1;i<=10000;i++){
    mp[i*i*i]++;
}
   
    int t;
    // t=1;
     cin>>t;
    //for(int i=1;i<=2e5+5;i++){
      //    fac[i]=(i*fac[i-1])%mod;
      //}

    int ind=0;
       int idx=0;  
       
    priority_queue<pair<int,int>> pq;
    vector<bool> vis(500005,false);   
    
     int mni=1e9+7;   // if((a - 1) > b + c + m || (b - 1) > a + c + m || (c - 1) > a + b + m) cout << "NO" << endl; else if(m <= (a + b + c - 3)) cout << "YES" << endl; else co "NO"
    while(t--){
       

      asquare();
            
        // int n,k;
        // cin>>n>>k;
        // if(n==4 && k==3){
        //     cout<<-1<<'\n';
        //     continue;
        // }
        // int nbits=floor(log2(n))+1;
        // int v[n/2][2];
        // for(int i=0;i<n/2;i++){
        //     v[i][0]=i;
        //     v[i][1]=n-i-1;
        // }
        // if(k==n-1){
            
        //         swap(v[0][0],v[1][1]);
        //         swap(v[1][1],v[2][1]);
            
            
        // }else{
        //     if(k<n/2){
        //          swap(v[0][0],v[k][0]);
        //     }else{
        //         swap(v[0][0],v[n-k-1][1]);
        //     }
        // }
        // f(i,0,n/2){
        //     cout<<v[i][0]<<" "<<v[i][1]<<'\n';
        // }

        
        
    }




  

  
  

       
       

       //if(m==0){
         //  cout<<"YES"<<'\n';
           //continue;
      // }
      




       
       
       
    
	// your code goes here
	return 0;
}


