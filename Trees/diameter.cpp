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
int height(node* root){
	if(root == NULL){
		return 0;
	}
	return max(height(root->left),height(root->right)) + 1;
}
/* O(N^2) Approach ---> */
int diameter(node* root){
	if(root == NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max({op1,op2,op3});
}
// This Algo will run in O(N) time cuz we have removed repetitive cases-->
pii diameter_optimized(node* root){
	pii p;
	if(root == NULL){
		p.ff = p.ss = 0;
		return p;
	}

	pii p1 = diameter_optimized(root->left);
	pii p2 = diameter_optimized(root->right);

	p.ff = max(p1.ff,p2.ff) + 1;
	p.ss = max({p1.ss,p2.ss,p1.ff+p2.ff});
	return p;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = buildTree();
   /* print(root);
   	cout<<diameter(root)<<"\n";
   */ 
    pii p = diameter_optimized(root);
    cout<<"Height   ==> "<<p.ff<<"\n"<<"Diameter ==> "<<p.ss<<"\n";
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