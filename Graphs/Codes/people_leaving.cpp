#include<bits/stdc++.h>
#define int long long int
using namespace std;
int get(vector<int> &parent,int i){
	if(parent[i] == i)
		return i;
	return parent[i] = get(parent,parent[i]);
}
void Union(int a,int b,vector<int> &parent){
	int s1 = get(parent,a);
 	int s2 = get(parent,b);
	if(s1!=s2){
		parent[s1] = s2;
	}
}
signed main(){
	int n,m;
	cin>>n>>m;
	vector<int> parent(n+2);
	for(int i = 0;i<=n+1;i++)
		parent[i] = i;

	while(m--){
		char ch;
		int x;
		cin>>ch>>x;
		if(ch == '-'){
			Union(x,x+1,parent);
		}else{
			int res = get(parent,x);
			if(res == n+1)
				cout<<-1<<endl;
			else
				cout<<res<<endl;
		}	
	}
	return 0;
}