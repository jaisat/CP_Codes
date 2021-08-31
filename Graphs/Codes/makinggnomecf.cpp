#include<bits/stdc++.h>
using namespace std;
vector<int> G[50];
int vis[50];
string ans;
void dfs(int i){
	vis[i] = 2;
	ans += i + 'a';
	for(auto it : G[i])
	if(vis[it] == 1)
		dfs(it);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i = 0;i<s.size()-1;i++){
			G[s[i]-'a'].push_back(s[i+1]-'a');
			vis[s[i+1]-'a'] = 1;	
		}
		if(!vis[s[0]-'a'])
			vis[s[0]-'a'] = 3;
	}
	for(int i =0;i<26;i++){
		if(vis[i] == 3)
			dfs(i);
	}
	cout<<ans<<endl;
	return 0;
}