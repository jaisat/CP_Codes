#include<bits/stdc++.h>
using namespace std;
vector<int> dsuf;
int find(int v){
	if(dsuf[v] == -1)
		return v;
	return find(dsuf[v]);
}
void union_op(int a,int b){
	a = find(a);
	b = find(b);
	dsuf[a] = b;
}
int main(){
	

	return 0;
}