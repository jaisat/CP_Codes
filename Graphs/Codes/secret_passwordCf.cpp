#include<bits/stdc++.h>
#define int long long int
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
signed main(){
	int n;
	cin>>n;
	vector<int> parent(27);
	vector<int> rank(27,1);
	for(int i = 0;i<=26;i++)
		parent[i] = i;
	vector<bool> total(26,false);
	vector<bool> curr(26,false);
	for(int j=0;j<n;j++){
		string str;
		cin>>str;
		for(int i=0;i<26;i++) curr[i] = false;
		for(char ch : str){
			curr[ch-'a'] = true;
 		}
 		for(int i=0;i<26;i++){
 			if(curr[i] == true){
 				total[i] = true;
 				Union(parent,rank,str[0]-'a',i);
 			}
 		  }
 		}
 	int cnt = 0;
 	for(int i=0;i<26;i++){
 		if(total[i] == true and get(parent,i) == i)
 			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}