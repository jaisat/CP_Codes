#include<bits/stdc++.h>
#define pi pair<int,int> 
using namespace std;
vector<pi> cords;
int count_rect(){
	int n = cords.size();
	set<pi> s;
	for(auto p : cords){
		s.insert(p);
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			pi p1 = cords[i];
			pi p2 = cords[j];
			if(p1.first == p2.first or p1.second == p2.second)
				continue;
			if(s.find({p1.first,p2.second})!=s.end() and s.find({p2.first,p1.second})!=s.end())
				ans++;
		}
	}
	return ans/2;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int m;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		cords.push_back({x,y});
	}
	cout<<count_rect()<<endl;
	return 0;
}