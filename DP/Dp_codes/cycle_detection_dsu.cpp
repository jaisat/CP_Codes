#include<bits/stdc++.h>
using namespace std;
vector<int> dsuf;
int find(int v){
	if(dsuf[v] == -1)
		return v;
	return find(dsuf[v]);
}
void union_op(int fromP,int toP){
	fromP = find(fromP);
	toP = find(toP);

	dsuf[fromP] = toP;
 }

bool isCycle(vector<pair<int,int>> edge_list){

	for(auto x : edge_list){
		int fromP = find(x.first);
		int toP = find(x.second);
		if(fromP == toP)
			return true;
		union_op(fromP,toP);
	}
	return false;
}
int main(){

	int V,E;
	cin>>E>>V;
	dsuf.resize(V,-1);
	vector<pair<int,int>> edge_list;
	for(int i = 0;i<E;i++){
		int from,to;
		cin>>from>>to;
		edge_list.push_back({from,to});
	}
	if(isCycle(edge_list))
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	return 0;

}