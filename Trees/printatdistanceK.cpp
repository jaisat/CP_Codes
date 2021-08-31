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
void printatk(node* root,int k){
	if(root == NULL){
		return;
	}
	if(k == 1){
		cout<<root->data<<" ";
	}
	printatk(root->left,k-1);
	printatk(root->right,k-1);
}

// Function which returns the distance b/w ancestor and target node-->
int printatdistanceK(node* root,node* target,int k){
	// base case
	if(root == NULL){
		return -1;
	}
	// reach to the target node 
	if(root == target){
		printatk(root,k);
		return 0;
	}
	int DL = printatdistanceK(root->left,target,k);
	if(DL != -1){
	// the target has found in the left subtree of an ancestor
	// 2 Cases--> Ancestor itself at k distance or we've to go the right subtree
		if(DL+1 == k){
			// Ancestor itself at a distace k from target node
			cout<<root->data<<" ";
		}else{
			// we've to call to right part of subtree
			printatk(root->right,k-DL-2);
		}
		return 1 + DL;
	}
	int DR = printatdistanceK(root->right,target,k);
	if(DR != -1){
	// the target has found in the right subtree of an ancestor
	// 2 Cases--> Ancestor itself at k distance or we've to go the left subtree
		if(DR+1 == k){
			// Ancestor itself at a distace k from target node
			cout<<root->data<<" ";
		}else{
			// we've to call to left part of subtree
			printatk(root->left,k-DR-2);
		}
		return 1 + DR;
	}
	// Node was not present in leftsubtree as well as rightsubtree
	return -1;
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