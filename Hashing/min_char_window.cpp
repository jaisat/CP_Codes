#include<bits/stdc++.h>
using namespace std;
string find_window(string s,string p){
	int SL = s.length();
	int PL = p.length();
	if(SL < PL)
		return "NONE";
       int FS[256] = {0};	
	   int FP[256] = {0};
	for(int i=0;i<PL;++i){
		char ch = p[i];
		FP[ch]++;
	}	
	int cnt = 0;
	int start = 0;
	int start_idx = -1;
	int min_l = INT_MAX;
	int window_length = 0;
	for(int i=0;i<SL;i++){
		char ch = s[i];
		FS[ch]++;

		if(FP[ch]!=0 and FS[ch] <= FP[ch]){
			cnt++;
		}
		if(cnt == PL){
			char temp = s[start];
			while(FP[temp] == 0 or FS[temp] > FP[temp]){
				FS[temp]--;
				start++;
				temp = s[start];
			}
			window_length = i - start + 1;
			if(min_l > window_length){
				min_l = window_length;
				start_idx = start;
			}
		}
	}
	if(start_idx == -1)
		return "NONE";
	string ans = s.substr(start_idx,min_l);
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s = "hellloeeaeo world";
	string p = "eelo";
	cout<<find_window(s,p)<<endl;
	return 0;

}