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

class Node{
	int data;
	Node* next;
public:
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class nodecompare{
public:
	bool operator()(node* n1,node* n2){
		return n1->data > n2->data;
	}
};	

Node* mergeKsortedLL(vector<node*> &v){
	priority_queue<node*,vector<node*>,nodecompare> minHeap;
	for(int i=0;i<v.size();i++){
		minHeap.push(v[i]);
	}
	Node* prev,head;
	int flag = 1;
	while(!minHeap.empty()){
		Node* top = minHeap.top();
		minHeap.pop();
		if(top->next)
		minHeap.push(top->next);
		Node* temp = new Node(top->data);
		if(flag){
			head = temp;
			flag = 0;
		}else{
			prev->next = temp;
		}
		prev = temp;
	}
	return head;	
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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