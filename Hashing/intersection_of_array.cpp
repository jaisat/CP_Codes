#include<bits/stdc++.h>
using namespace std;
vector<int> Intersection(vector<int> &v1,vector<int> &v2){
	vector<int> res;
	unordered_map<int,int> mp;
	for(auto x : v1){
		mp[x]++;
	}
	for(auto no : v2){
		if(mp.find(no)!=mp.end() and mp[no] >0){
			res.push_back(no);
			mp[no]--;
		}
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	vector<int> v1{5,5,7,7,2,5};
	vector<int> v2{6,7,9,5,5,5,5};
	vector<int> res = Intersection(v1,v2);
	for(auto x : res){
		cout<<x<<" ";
	}
	return 0;
}