#include<bits/stdc++.h>
using namespace std;
int Longest_Conseq(vector<int> &v){
	unordered_set<int> s;
	int n = v.size();
	for(int i=0;i<n;i++){
		s.insert(v[i]);
	}
	int max_L = INT_MIN;
	for(int i=0;i<n;i++){
		if(s.find(v[i]-1)!=s.end())
			continue;
		int next = v[i] + 1;
		int cnt = 1;
		while(s.find(next)!=s.end()){
			cnt++;
			next++;
		}
		max_L = max(max_L,cnt);
	}
	return max_L;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<Longest_Conseq(v)<<"\n";
	return 0;
}