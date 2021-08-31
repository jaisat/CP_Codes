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
// Assuming that given nodes a & b both are present in the tree
node* LCA(node* root,int a,int b){
	if(root == NULL){
		return NULL;
	}
	if(root->data == a or root->data == b){
		return root;
	}

	node* opL = LCA(root->left,a,b);
	node* opR = LCA(root->right,a,b);

	if(opR != NULL and opL != NULL){
		return root;
	}

	if(opL != NULL){
		return opL;
	}
	return opR;

}
int search(node* root,int key,int level){
 	if(root == NULL){
 		return -1;
 	}
 	if(root->data == key){
 		return level;
 	}

 	int left = search(root->left,key,level+1);
 	if(left!=-1){
 		return left;
 	}
 	return search(root->right,key,level+1);
 }

int shortestDist(node* root,int a,int b){
	node* lca_node = LCA(root,a,b);
	int l = search(lca_node,a,0);
	int r = search(lca_node,b,0);

	return (l+r);
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = buildTree();
    print(root);
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