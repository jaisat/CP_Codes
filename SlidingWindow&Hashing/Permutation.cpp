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
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string text,pattern;
    cin >> text >> pattern;
/*
    unordered_map<char,int> mp,test;
    for(auto ch : pattern){
    	mp[ch]++;
    }
    test = mp;
    int start = 0;
    int flag = 0;
    int n = text.size();
    for(int end = 0; end < n; end++){
    	char currchar = text[end];
    	if(test.find(currchar) != test.end()){
    		test[currchar]--;
    		if(test[currchar] == 0)
    			test.erase(currchar);

    		if(test.size() == 0){
    			flag = 1;
    			break;
    		}
    	}else{
            end = start;
    		start = start + 1;
    		test = mp;
    	}
    }
    if(flag){
    	cout<<"YES"<<"\n";
    }else{
    	cout<<"NO"<<"\n";
    }*/

    unordered_map<char,int> mp;
    int matched = 0;
    int start = 0;
    for(auto ch : pattern){
        mp[ch]++;
    }
    int n = text.size();
    for(int end = 0; end < n; end++){
        char currchar = text[end];
        if(mp.find(currchar) != mp.end()){
            mp[currchar]--;
            if(mp[currchar] == 0){
                matched++;
            }

            if(matched == (int) mp.size()){
                cout<<"YES"<<"\n";
                return;
            }
        }

        if(end >= (int)mp.size()- 1){
            char left = text[start++];
            if(mp.find(left) != mp.end()){
                if(mp[left] == 0){
                    matched--;
                }
                mp[left]++;
            }
        }   
    }
    cout<<"NO"<<"\n";
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