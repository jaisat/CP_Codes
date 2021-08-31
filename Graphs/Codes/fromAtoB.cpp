#include<bits/stdc++.h>
#define int long long int 
using namespace std;
stack<int> s;

bool dfs(int a,int b){

	if(a>b)
		return false;
	if(a == b){
		s.push(b);
		return true;
	}

	bool sub1 = dfs(a*2,b);
	if(sub1){
		s.push(a);
		return true;
	}
	bool sub2 = dfs(a*10+1,b);
	if(sub2){
		s.push(a);
		return true;
	}

	return false;


}
signed main(){

	int a,b;
	cin>>a>>b;

	bool ans = dfs(a,b);
	if(ans){
		cout<<"YES"<<endl;
		cout<<s.size()<<endl;
		while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
		}
		
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}