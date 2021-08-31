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
 
class DLLNode{
public:
	int key;
	int value;
	DLLNode *next;
	DLLNode *prev;
	DLLNode(int key,int value){
		this->key = key;
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};
unordered_map<int,DLLNode*> cache;
int size;
int capacity;
DLLNode *head = new DLLNode(-1,-1);
DLLNode *tail = new DLLNode(-1,-1);

void addNodeAtHead(DLLNode *node){
	node->prev = head;
	head->next->prev = node;
	node->next = head->next;
	head->next = node;
	return;
}
void removeNode(DLLNode *node){
	DLLNode *prev = node->prev;
	DLLNode *next = node->next;
	next->prev = prev;
	prev->next = next;
	delete node;
}
int removeFromtail(){
	DLLNode *temp = tail->prev;
	removeNode(temp);
	return temp->key;
}
void moveTohead(DLLNode *node){
	cout<<"Accessed the Key"<<node->key<<"\n";
	removeNode(node);
	addNodeAtHead(node);
	return;
}
int get(int k){
	if(cache.count(k) == 0){
		cout<<"This key is not present in the Cache"<<"\n";
		return INT_MIN;
	}
	DLLNode *node = cache[k];
	moveTohead(node);
	return node->value;
}
void put(int k,int v){
	if(cache.count(k) == 0){
		// Key is not present 
		DLLNode *node = new DLLNode(k,v);
		cache[k] = node;
		cout<<"Added a Key"<<k<<endl;
		addNodeAtHead(node);
		capacity++;
		if(capacity > size){
			int removeKey = removeFromtail();
			cout<<"As capacity is Full we need to remove key"<<removeKey<<endl;
			capacity--;
			cache.erase(removeKey);
		}
	}else{
		// Key is Already present
		DLLNode *node = cache[k];
		node->value = v;
		addNodeAtHead(node);
	}
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout<<"Please Enter the size of cache\n";
    cin >> size;
    cout << "Size of cache is "<<size<<"\n";
    head->next = tail;
    tail->next = head;
    int q;
    cin >> q;
    while(q--){
    	char ch;
    	int k,v;
    	cin >> ch;
    	if(ch == 'p'){
    		cin >> k >> v;
    		put(k,v);
    	}else{
    		cin >> k;
    		int v = get(k);
    		cout<<"Value for key "<<k<<" is "<<v<<endl;
    	}
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}