#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


string pre_operation(string v1,string v2,char op){
	string ans = "";
	ans += op + v1 + v2;
	return ans;
}

string post_operation(string v1,string v2,char op){
	string ans = "";
	ans += v1 + v2 + op;
	return ans;
}
int precedence(char op){
	if(op == '+')
		return 1;
	if(op == '-')
		return 1;
	if(op == '*')
		return 2;
	if(op == '/')
		return 2;

	return -1;
} 

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    getline(cin,s);

    vector<char> optr;
    vector<string> prefix;
    vector<string> postfix;
    int n = s.size();
    for(int i=0;i<n;i++){
    	if(s[i] == '('){
    		optr.push_back(s[i]);
    	}else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
    		while(!optr.empty() and optr.back() != '(' and precedence(optr.back()) >= precedence(s[i])){
    			char op = optr.back();
    			optr.pop_back();

    			string v2 = prefix.back();
    			prefix.pop_back();
    			string v1 = prefix.back();
    			prefix.pop_back();
    			string str = pre_operation(v1,v2,op);
    			prefix.push_back(str);


    			v2 = postfix.back();
    			postfix.pop_back();
    			v1 = postfix.back();
    			postfix.pop_back();

    			string str2 = post_operation(v1,v2,op);
    			postfix.push_back(str2);
    		}
    		optr.push_back(s[i]);
    	}else if(s[i] == ')'){
    		while(optr.back() != '('){
    			char op = optr.back();
    			optr.pop_back();

    			string v2 = prefix.back();
    			prefix.pop_back();
    			string v1 = prefix.back();
    			prefix.pop_back();
    			string str = pre_operation(v1,v2,op);
    			prefix.push_back(str);


    			v2 = postfix.back();
    			postfix.pop_back();
    			v1 = postfix.back();
    			postfix.pop_back();

    			string str2 = post_operation(v1,v2,op);
    			postfix.push_back(str2);
    		}
    		optr.pop_back();
    	}else{	
    		string new_str = "";
    		new_str += s[i];
    		prefix.push_back(new_str);
    		postfix.push_back(new_str);
    	}	
    }
    while(!optr.empty()){
    			char op = optr.back();
    			optr.pop_back();

    			string v2 = prefix.back();
    			prefix.pop_back();
    			string v1 = prefix.back();
    			prefix.pop_back();
    			string str = pre_operation(v1,v2,op);
    			prefix.push_back(str);


    			v2 = postfix.back();
    			postfix.pop_back();
    			v1 = postfix.back();
    			postfix.pop_back();

    			string str2 = post_operation(v1,v2,op);
    			postfix.push_back(str2);
    }

    cout<<postfix.back()<<"\n";
    cout<<prefix.back()<<"\n";
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
    return 0;
}