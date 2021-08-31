#include<bits/stdc++.h>
#define vi vector<int> 
#define MAX 1001
using namespace std;
int get(vi &parent,int i){
	if(parent[i] == i)
		return i;
	return parent[i] = get(parent,parent[i]);
}
void Union(vi &parent,vi &rank,int a,int b){
	a = get(parent,a);
	b = get(parent,b);
	if(rank[a] == rank[b]) rank[a]++;
	if(rank[a] > rank[b]) parent[b] = a;
	else parent[a] = b;
}
int main(){
	int n;
	cin>>n;
	vi parent(MAX);
	vi rank(MAX,1);
	for(int i = 1;i<=n;i++)
		parent[i] = i;
	int cnt = 0;
	vector<pair<int,int> > v;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(get(parent,a) == get(parent,b)){
			v.push_back({a,b});
		}else{
			Union(parent,rank,a,b);
		}
	}
	
	// cout<<v.size()<<endl;
	// for(auto val : v){
	// 	int x = val.first;
	// 	int y = val.second;
	// 	for(int i = 1;i<=n;i++){
	// 		if(get(parent,x)!=get(parent,i)){
	// 			cout<<x<<" "<<y<<" "<<x<<" "<<i<<endl;
	// 			Union(parent,rank,x,i);
	// 		}
	// 	}
	// 	cout<<x<<" "<<y<<endl; 
	// }

    int  par = get(1);
 
    cout<<v.size()<<"\n";
 
    for (int i = 2; i <= n && v.size(); ++i)
    {
        // cout<<parent[i]<<" ";
        
        int cur = get(i);
 
        if(cur != par)
        {
            merge(par,cur);
            cout<<v.back().first<<" "<<v.back().second<<" "<<par<<" "<<cur<<"\n";
            v.pop_back();
        }
    }

	return 0;
}