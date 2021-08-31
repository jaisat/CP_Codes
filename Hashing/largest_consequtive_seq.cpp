#include<bits/stdc++.h>
using namespace std;
int Largest_conseq(int arr[],int n){
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		int no = arr[i];
		if(m.count(no-1)==0 and m.count(no+1)==0){
			m[no] = 1;
		}else if(m.count(no-1) and m.count(no+1)){
			int len1 = m[no-1];
			int len2 = m[no+1];

			int streak = len1 + 1 + len2;
			m[no-len1] = streak;
			m[no-len2] = streak;
		}else if(m.count(no-1) and !m.count(no+1)){
			int len = m[no-1];
			m[no-len] = len + 1;
			m[no] = len + 1;
		}else{
			int len = m[no+1];
			m[no+len] = len + 1;
			m[no] = len;
		}
	}
	int largest = 0;
	for(auto p: m){
		largest = max(largest,p.second);
	}
	return largest;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	cout<<Largest_conseq(arr,n)<<endl;
	return 0;
}
