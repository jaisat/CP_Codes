#include<bits/stdc++.h>
using namespace std;
int get(vector<int> &parent,int i){
	if(parent[i] == i)
		return i;
	return parent[i] = get(parent,parent[i]);
}
void Union(vector<int> &parent,vector<int> &rank,int a,int b){
	a = get(parent,a);
	b = get(parent,b);
	if(rank[a] == rank[b]) rank[a]++;
	if(rank[a] > rank[b]) parent[b] = a;
	else parent[a] = b;
}
int main(){

	int n,m,q;
	cin>>n>>m>>q;
	vector<int> parent(n+1);
	vector<int> rank(n+1,1);
	for(int i=0;i<=n;i++)
		parent[i] = i;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
	}
	vector<pair<int,int> > qval(q);
	vector<int> qtype(q);
	for(int i=0;i<q;i++){
		string str;
		cin>>str;
		int a,b;
		cin>>a>>b;
		qval[i] = {a,b};
		if(str == "cut")
			qtype[i] = 1;
		else
			qtype[i] = 2;
	}
	reverse(qtype.begin(),qtype.end());
	reverse(qval.begin(),qval.end());
	vector<string> s;
	for(int i=0;i<q;i++){
		if(qtype[i] == 1){
			Union(parent,rank,qval[i].first,qval[i].second);
		}else{
			if(get(parent,qval[i].first) == get(parent,qval[i].second))
				s.push_back("YES");
			else
				s.push_back("NO");
		}
	}
	reverse(s.begin(),s.end());
	for(auto x : s)
		cout<<x<<endl;
	return 0;
}