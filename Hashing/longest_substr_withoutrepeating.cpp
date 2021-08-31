#include<bits/stdc++.h>
using namespace std;
int Longest_sub(string s){
	int j = 0;
	unordered_set<char> st;
	int max_L = INT_MIN;
	for(int i=0;i<s.length();i++){
		if(st.count(s[i])>0){
			st.erase(s[i]);
			j++;
		}
		st.insert(s[i]);
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