#include<bits/stdc++.h>
using namespace std;
#define int long long
int A,s=0,c=0,n,t;

vector<int> fac(19,1);
int32_t main()
{
	cin>>t;
	for(int i=1;i<=16;i++)
		fac[i]=i*fac[i-1];
	while(t--&&cin>>n)
	{
	       A=__builtin_popcountll(n);	
		for(int i=0;i<(1<<16);i++)
		{
			s=c=0;
			for(int j=0;j<16;j++){
				if(i&(1<<j))
					s+=fac[j+1],c++;}
			if(s<=n)
                
				A=min(A,c+__builtin_popcountll(n-s));
		}
		cout<<A<<'\n';
	}
}
