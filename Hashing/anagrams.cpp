#include<bits/stdc++.h>
using namespace std;
bool IsAnagram(string s1,string s2){
	if(s1.size() != s2.size())
		return false;
	unordered_map<char,int> mp;
	for(auto x : s1){
		mp[x]++;
	}
	for(auto x : s2){
		mp[x]--;
	}
	for(auto v : mp){
		if(mp[v.first]!=0)
			return false;
	}
	return true;
}
// SPACE COMPLEXITY WILL NOT DEPENDENT ON N ... O(1)
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	string s1,s2;
	cin>>s1>>s2;
	cout<<IsAnagram(s1,s2)<<"\n";
	return 0;
}