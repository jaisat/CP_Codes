#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
using namespace std;
signed main(){
		#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
   			freopen("output.txt", "w", stdout);
		#endif
	int n,k,x;
	cin>>n>>k>>x;
	vi freq(1500,0);
	for(int i=0;i<n;i++){
		int f;
		cin>>f;
		freq[f]++;
	}
	vi temp(1500,0);
	while(k--){
		for(int i=0;i<1500;i++){
			temp[i] = freq[i];
		}
		int parity = 0;
		for(int i=0;i<1500;i++){
			if(freq[i] > 0){
				int curr = i ^ x;
				int delta = freq[i] / 2;
				if(parity == 0){
					delta += freq[i]&1;
				}
				temp[i] -= delta;
				temp[curr] += delta;
				parity = parity ^ (freq[i]&1);
			}
		}
		for(int i=0;i<1500;i++){
			freq[i] = temp[i];
		}
	}

	int min_val = INT_MAX, max_val = INT_MIN;
	for(int i=0;i<1500;i++){
		if(freq[i] >0){
			min_val = min(min_val, i);
			max_val = max(max_val, i);
		}
	}
	cout<<max_val<<" "<<min_val<<"\n";
	return 0;
}