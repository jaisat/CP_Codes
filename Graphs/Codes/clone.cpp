#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int> *l;
    graph(int v){
        this->v = v;
        l = new list<int> [v+1];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
};  
int main(){


}