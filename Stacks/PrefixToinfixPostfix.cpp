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

int calc(int v1,int v2,char op){
    if(op == '+')
        return v1 + v2;
    if(op == '-')
        return v1 - v2;
    if(op == '*')
        return v1 * v2;
    if(op == '/')
        return v1 / v2;

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
    

    vector<int> eval;
    vector<string> postfix;
    vector<string> infix;
    int n = s.size();	

    for(int i=n-1;i>=0;i--){
    	if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
    		char op = s[i];

    		int v1 = eval.back();
    		eval.pop_back();
    		int v2 = eval.back();
    		eval.pop_back();

    		int v = calc(v1,v2,op);
    		eval.push_back(v);

    		string s1 = infix.back();
    		infix.pop_back();
    		string s2 = infix.back();
    		infix.pop_back();
    		string new_str = '(' + s1 + op + s2 + ')';
    		infix.push_back(new_str);



    		s1 = postfix.back();
    		postfix.pop_back();
    		s2 = postfix.back();
    		postfix.pop_back();
    		new_str = s1 + s2 + op;
    		postfix.push_back(new_str);

    	}else{
    		string str = "";
    		str += s[i];
    		eval.push_back(s[i] - '0');
    		infix.push_back(str);
    		postfix.push_back(str);
    	}

    }
    cout<<eval.back()<<"\n";
    cout<<infix.back()<<"\n";
    cout<<postfix.back()<<"\n";

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