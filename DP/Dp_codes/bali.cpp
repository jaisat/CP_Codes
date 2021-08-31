#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll modu(ll a, ll b){
	ll ans = 1;
	while(b>0){
		if(b&1)
			ans = (ans * a)%mod;
		a =(a*a)%mod;
		b = b>>1;
	}
return ans % mod;
}
int main(){
		ll n,l,r;
		cin>>n;
		ll oe,ee,oo;
		oe = ee = oo = 0;
		for(int i = 0;i<n;i++){
			cin>>l>>r;
			if(l % 2 == 0 and r % 2 ==0)
				ee++;
			else if(l % 2 == 1 and r % 2 == 1)
				oo++;
			else
				oe++;
		}
		if(ee == n)
			cout<<0<<endl;
		else if(oo == n){
			if(n % 2 == 0)
				cout<<0<<endl;
			else
				cout<<modu(2,n)<<endl;
		}
		else
			cout<<modu(2,n-1)<<endl;
		return 0;
}