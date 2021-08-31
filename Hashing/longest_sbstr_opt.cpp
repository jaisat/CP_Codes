#include<bits/stdc++.h>
using namespace std;
int Longest_sub(string s){
	unordered_map<char,int> mp;
	int j = 0;
	int max_L = INT_MIN;
	for(int i=0;i<s.length();i++){
		if(mp.count(s[i]) > 0){
			j = mp[s[i]];
		}
		mp[s[i]] = i + 1;
		max_L = max(max_L,i - j + 1);
	}
	return max_L;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	cout<<Longest_sub(s)<<"\n";
	return 0;
}