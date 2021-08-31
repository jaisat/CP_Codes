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
// Information to be returned by every node in bottom-up manner
struct Info
{
	int sz; // size of subtree which is bst
	int min;
	int max;
	int ans;
	bool isBST;
};

Info largestBST(Node* root){
	
	if(root == NULL){
		return {0,INT_MAX,INT_MIN,0,true};
	}
	if(root->left == NULL and root->right == NULL){
		return {1,root->data,root->data,1,true};
	}
	Info l = largestBST(root->left);
	Info r = largestBST(root->right);

	Info  ret;
	ret.sz = l.sz + r.sz + 1;

	// condition for a subtree to be a BST is --->  max(Left) < root->data < min(Right) and left bst and right
	if(l.isBST and r.isBST and root->data > l.max and root->data < r.min){
		ret.min = min({l.min,r.min,root->data});
		ret.max = max({l.max,r.max,root->data});
		ret.isBST = true;
		ret.ans = ret.sz;
		return ret;
	}

	ret.ans = max(l.ans,r.ans);
	ret.isBST = false;
	return ret;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = buildTree();

    
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