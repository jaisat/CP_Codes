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
int height(node* root){
	if(root == NULL){
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls,rs) + 1;
}

void printKthlevel(node* root,int k){
	if(root == NULL){
		return;
	}
	if(k == 1){
		cout<<root->data<<" ";
		return;
	}
	printKthlevel(root->left,k-1);
	printKthlevel(root->right,k-1);
	return;
}
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
int count(node* root){
	if(root == NULL){
		return 0;
	}
	return count(root->left) + count(root->right) + 1;
}
int sumofnodes(node* root){
	if(root == NULL){
		return 0;
	}

	return root->data + sumofnodes(root->left) + sumofnodes(root->right);
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = buildTree();
    cout<<count(root)<<"\n"<<sumofnodes(root)<<"\n";

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