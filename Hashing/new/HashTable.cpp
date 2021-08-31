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
 
template<typename T> 
class Node{

public:
	string key;
	T val;
	Node<T>* next;
	Node(string key,T val){
		this->key = key;
		this->val = val;
		next = NULL;
	}
	~Node(){
			if(next!= NULL)
				delete next;
	}
};

template<typename T>
class Hashtable{
	Node<T>** table;
	int current_size;
	int total_size;

	int HashFn(string key){
		int idx = 0;
		int p = 1;
		for(int j=0;j<key.length();j++){
			idx = (idx + (key[j]*p)) % total_size;
			p = (p * 27) % total_size; 
		}
		return idx;
	}

	void rehash(){
		Node<T>** oldTable = table;
		int oldsize = total_size;
		total_size = 2 * total_size;
		table = new Node<T>*[total_size];
		for(int i=0;i<total_size;i++)
			table[i] = NULL;
		current_size = 0;

		for(int i=0;i<oldsize;i++){
			Node<T>* temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->val);
				temp = temp->next;
			}
			if(oldTable[i] != NULL){
				delete oldTable[i];
			}
		}
		delete [] oldTable;
	}
public:
	Hashtable(int ts = 7){
		total_size = ts;
		table = new Node<T>*[total_size];
		current_size = 0;
		for(int i=0;i<total_size;i++)
			table[i] = NULL;
	}

	void insert(string key,T val){
		int idx = HashFn(key);

		Node<T>*n = new Node<T>(key,val);
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		// rehash...
		float load_factor = current_size/(1.0*total_size);
		if(load_factor > 0.7){
			rehash();
		}

	}

	void print(){
		for(int i=0;i<total_size;i++){
			Node<T>* temp = table[i];
			while(temp != NULL){
				cout<<temp->key<<"--->"<<temp->val;
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	T* search(string key){
		int idx = HashFn(key);
		Node<T>* temp = table[idx];
		while(temp != NULL){
			if(temp->key == key){
				return &temp->val;
			}
			temp = temp->next;
		}
		return NULL;
	}
};
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Hashtable<int> price;
    price.insert("Burger",100);
    price.insert("Pizza",250);
    price.insert("Samosa",10);
    price.insert("Sandwitch",30);
    int *p = price.search("Samosa");
    if(p == NULL){
    	cout<<"NOT FOUND";
    }else{
    	cout<<"Price is : "<<*p<<"\n";
    }
   // price.print();
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