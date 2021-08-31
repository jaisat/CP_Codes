#include<bits/stdc++.h>
using namespace std;

int min_pour(int from_cap,int to_cap,int d ){

	int from = from_cap;
	int to = 0;
	int step = 1;

	while(from != d and to != d){

		int temp = min(from,to_cap - to);

		from -= temp;
		to   += temp;

		step++;

		if(from == d || to == d)
			break;

		if(from == 0){
			from = from_cap;
			step++;
		} 
		if(to == to_cap){
			to = 0;
			step++;
		}
	}
	return step;

}
int min_steps(int m,int n,int d){

	if(n < m)
		swap(n,m);

	if(d > n)
		return -1;

	if(d%__gcd(n,m) != 0)
		return -1;

	return min(min_pour(n,m,d),min_pour(m,n,d));


}
int main(){

	int n,m,d;
	cin>>n>>m>>d;
	cout<<min_steps(n,m,d)<<endl;
	return 0;
}