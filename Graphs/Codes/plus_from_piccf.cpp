#include<bits/stdc++.h>
using namespace std;
char a[501][501];
bool row[501] = {false};
bool col[501] = {false};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int r,c;
bool valid(int x,int y){
	if(x<0 || x>=r || y<0 || y>=c || a[x][y] == '.')
		return false;
	return true;
}
bool isValid(int i,int j){

		if(a[i][j] == '.')
			return false;

		for(int k = 0;k<4;k++){
			int sx = i + dx[k];
			int sy = j + dy[k];
			if(valid(sx,sy))
				return true;
		}
	return false;
}
bool syvalid(int i,int j){

		for(int k = 0;k<4;k++){
			int sx = i + dx[k];
			int sy = j + dy[k];
			if(valid(sx,sy))
				return true;
		}
	return false;

}
bool func(){


	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			if(a[i][j] == '*'){
				if(syvalid(i,j) == false)
					return false;
			}
		}
	}

	int rw = 0;
	int cl = 0;
	int cnt1 = 0;
	for(int i = 0;i<r;i++){
		if(row[i]){
			cnt1++;
			rw = i;
		}
	}
	if(cnt1>1)
		return false;
	int cnt2 = 0;
	for(int i = 0;i<c;i++){
		if(col[i]){
			cnt2++;
			cl = i;
		}
	}
	if(cnt2>1)
		return false;

	if(cnt1 == 0 and cnt2 == 0)
		return false;


	for(int i = 0;i<r;i++){
		bool sub = isValid(rw,i);
		if(sub){
			return true;
		}
	}

	for(int i = 0;i<c;i++){
		bool sub = isValid(i,cl);
		if(sub){
			return true;
		}
	}

return false;


}
int main(){

	 	
	 	
	 	cin>>r>>c;
	 	for(int i = 0;i<r;i++){
	 		for(int j = 0;j<c;j++){
	 			cin>>a[i][j];
	 			}
	 		}
	 	int cnt;
	 	for(int i = 0;i<r;i++){
	 		cnt = 0;
	 		for(int j = 0;j<c;j++){
	 			if(a[i][j] == '*'){
	 				cnt++;
	 			}
	 		}
	 		if(cnt >1)
	 			row[i] = true;
	 	}
	 		for(int j= 0;j<c;j++){
	 		cnt = 0;
	 		for(int i = 0;i<r;i++){
	 			if(a[i][j] == '*'){
	 				cnt++;
	 			}
	 		}
	 		if(cnt >1)
	 			col[j] = true;
	 	}



	 	// for(int i = 0;i<r;i++){
	 	// 	cout<<row[i]<<" ";
	 	// }
	 	// cout<<endl;
	 	// for(int i =0;i<c;i++){
	 	// 	cout<<col[i]<<" ";
	 	// }
	 	// cout<<endl;
	 	if(func()){
	 		cout<<"YES"<<endl;
	 	}else{
	 		cout<<"NO"<<endl;
	 	}
	 	return 0;
}