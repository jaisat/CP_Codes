#include<bits/stdc++.h>
#define int long long int
#define vi vector<int> 
using namespace std;
int get(vi &parent,int i){
	if(parent[i] == i)
		return i;
	return parent[i] = get(parent,parent[i]);
}
void Union(vi &parent,vi &rank,vi &max_,vi &min_,vi &size_,int a,int b){
	a = get(parent,a);
	b = get(parent,b);
	if(rank[a] == rank[b]) rank[a]++;
	if(rank[a] > rank[b]){
		parent[b] = a;
		max_[a] = max(max_[a],max_[b]);
		min_[a] = min(min_[a],min_[b]);
		size_[a] += size_[b]; 
	}else{
		parent[a] = b;
		max_[b] = max(max_[a],max_[b]);
		min_[b] = min(min_[a],min_[b]);
		size_[b] += size_[a];
	}
}
signed main(){

	return 0;
}

