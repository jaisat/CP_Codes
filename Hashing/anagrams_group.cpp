#include<bits/stdc++.h>
using namespace std;
void Anagroup(vector<string> &v){
	map<string,vector<string> > mp;
	for(auto x : v){
		string str = x;
		sort(str.begin(),str.end());
		mp[str].push_back(x);
	}
	for(auto x : mp){
		cout<<x.first<<"---> ";
		for(auto y : mp[x.first]){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    unordered_map<string,vector<string> > mp;
    for(auto str : string_list){
        string temp = str;
        sort(temp.begin(),temp.end());
        mp[temp].push_back(str);
    }
    vector<vector<string> > res;
    int j = 0;
    for(auto strPair : mp){
        for(auto l : mp[strPair.first]){
            res[j].push_back(l);
        }
       j++;
    }
    return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	vector<string> v;
	int n;
	cin>>n;
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		v.push_back(str);
	}
	auto vi = Anagrams(v);
	for(int i=0;i<vi.size();i++){
		for(int j=0;j<vi[i].size();j++)
			cout<<vi[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}