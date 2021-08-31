#include<bits/stdc++.h>
#define int long long int 
using namespace std;
int power_of10(int x){
	int res = 1;
	for(int i=1;i<=x;i++){
		res *= 10;
	}
	return res;
}
int sum_of_digits(int num){
	if(num/10 == 0) return (num*(num+1))/2;
	string s = to_string(num);
	int n = s.size();
	int result = 0;
	int pow10 = power_of10(n-1);
	int first = num / pow10;
	int sum = power_of10(n-2)*45*(n-1); 
	for(int i=0;i<=first-1;i++){
		result += i*pow10 + sum;
	}
	int rest_No = num % pow10;
	result += first*(rest_No+1);
	result += sum_of_digits(rest_No);
	return result;
}
signed main(){
	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
   			freopen("output.txt", "w", stdout);
	#endif
	int a,b;
	while(1){
		cin>>a>>b;
		if(a == -1 and b == -1){
			break;
		}
		int x = sum_of_digits(b);
		int y = sum_of_digits(a-1);
		cout<<x - y<<"\n";
	}
	return 0;
} 