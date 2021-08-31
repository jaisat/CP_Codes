#include<bits/stdc++.h>
using namespace std;
int Largest(int a[],int n){
	unordered_set<int> s;
	for(int i=0;i<n;i++){
		s.insert(a[i]);
	}
	int max_streak = 1;
	for(int i=0;i<n;++i){
		if(s.find(a[i]-1) == s.end()){
			int next_no = a[i] + 1;
			int streak = 1;
			while(s.find(next_no)!=s.end()){
				next_no += 1;
				streak += 1;
			}
			max_streak = max(max_streak,streak);
		}
	}
	return max_streak;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<Largest(a,n)<<endl;
	return 0;
}