#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
template<typename T>
class Node{
public:
	string key;
	T value;
	Node<T>*next;
	Node(string key,T value){
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};
template<typename T>
class Hashtable{
public:
	int cs;
	int ts;
	Node<T> **arr;
	Hashtable(int ts = 2){
		this->cs = 0;
		this->ts = ts;
		arr = new Node<T>*[this->ts];
		for(int i=0;i<this->ts;i++)
			arr[i] = NULL;	
	}
	void display(){
		for(int i=0;i<this->ts;i++){
			Node<T>* temp = this->arr[i];
			if(temp == NULL){
				cout<<"EMPTY"<<endl;
				continue;
			}
			while(temp!=NULL){
				cout<<"("<<temp->key<<","<<temp->value<<") -> ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	int hashFunction(string key){
		ll sum = 0;
		ll factor = 1;
		for(int i=0;i<key.size();i++){
			sum = (sum%this->ts) + ((int)key[i] * factor)%this->ts;
			sum = sum%this->ts;
			factor = ((factor%this->ts) * (37%this->ts))%this->ts;
		}
		return (int)sum;
	}
	void reHash(){
		int old_size = this->ts;
		this->ts = 2 * old_size;
		Node<T>** old_table = new Node<T>*[this->ts];
		for(int i=0;i<this->ts;i++){
			arr[i] = NULL;
		}
		for(int i=0;i<old_size;i++){
			Node<T>* temp = old_table[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
		}
	}
	void insert(string key,T value){
		int bi = hashFunction(key);
		Node<T>* newnode = 	new Node<T>(key,value);
		if(this->arr[bi] == NULL){
			this->arr[bi] = newnode;
		}else{
			newnode->next = this->arr[bi];
			this->arr[bi] = newnode;
		}
		this->cs++;
		double loadfactor = (double)(this->cs) /(this->ts);
		if(loadfactor > 0.5)
			reHash();
	}
	T search(string key){
		int idx = hashFunction(key);
		Node<T>* temp = this->arr[idx];
		while(temp!=NULL){
			if(temp->key == key)
				return temp->value;
			temp = temp->next;
		}
		return NULL;
	}

	
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	Hashtable<int>* hash = new Hashtable<int>();
	while(n--){
		string key;
		int value;
		cin>>key>>value;
		hash->insert(key,value);
		hash->display();
		cout<<"**************************\n";
	}
	

	return 0;
}