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
#define setbits(x)      __builtin_popcountint(x)
#define zrobits(x)      __builtin_ctzint(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int data){
		this->data = data;
		left  = NULL;
		right = NULL;
	}
};
void print(node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
node* buildTree(){
	int d;
	cin >> d;
	if(d == -1){
		return NULL;
	}
	node* root 	= new node(d);
	root->left 	= buildTree();
	root->right = buildTree();
	return root;
}
node* Hbtree(int *arr,int s,int e){
	if(s > e){
		return NULL;
	}
	int mid = (s+e)/2;
	node* root  = new node(arr[mid]);
	root->left  = Hbtree(arr,s,mid-1);
	root->right = Hbtree(arr,mid+1,e);
	return root;
}
void bfs(node* root){
	if(root == NULL){
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* f = q.front();
		if(f == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
			continue;
		}
		cout<<f->data<<" ";
		q.pop();
		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f->right);
		}
	}
	return;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  /*node* root = buildTree();
    print(root);*/
    int arr[] = {1,2,5,6,4,8};
    int n = sizeof(arr)/sizeof(int);
    node* root = Hbtree(arr,0,n-1);
    bfs(root);
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