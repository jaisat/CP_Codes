#include<bits/stdc++.h>
using namespace std;
void generate_strings(char* in,char *out,int i,int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	int digit = in[i] - '0';
	if(digit == 0){
		generate_strings(in,out,i+1,j);
	}else{
	char ch = digit + 'A' - 1;
	out[j] = ch;
	generate_strings(in,out,i+1,j+1);
	if(in[i+1]!='\0'){
		int next = in[i+1] - '0';
		int no = digit*10 + next;
		if(no<=26){
		   char ch = no + 'A' - 1;
		   out[j] = ch;
		   generate_strings(in,out,i+2,j+1);
	    	}
		}
	}
	return;

}
int main(){
	char in[100];
	cin>>in;
	char out[100];
	generate_strings(in,out,0,0);
	return 0;
}