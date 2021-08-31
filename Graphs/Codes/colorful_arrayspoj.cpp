#include<bits/stdc++.h>
using namespace std;
class Dsu{
	
public:
	vector<int> parent;
	Dsu(int n){
		parent.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
		}
	}
	int get(int i){
		return (parent[i] == i ? i: parent[i] = get(parent[i]));
	}
	void Unite(int x,int y){

		x = get(x);
		y = get(y);
		if(x != y){
			parent[x] = max(parent[x],parent[y]);
			parent[y] = max(parent[x],parent[y]);
		}
	}
};
int main(){
	int n,q;
	cin>>n>>q;

	int l[q],r[q],c[q];
	for(int i = 0; i < q; i++){
		cin>>l[i]>>r[i]>>c[i];
	}
 	
 		Dsu g(n+2);
 		int res[n+1] = {0};
 		for(int i = q - 1;i>=0;i--){
 			int index = g.get(l[i]);

 			while(index<=r[i]){

 				res[index] = c[i];
 				g.Unite(index,index+1);
 				index = g.get(index);
 			}
 		}

 		for(int i = 1;i<=n;i++){
 			cout<<res[i]<<endl;
 		}

 		return 0;

}