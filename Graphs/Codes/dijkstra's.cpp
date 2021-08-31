#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int> > > m;
public:
    void addEdge(T x,T y,int dist,bool bidr=true){
        m[x].push_back({y,dist});
        if(bidr){
            m[y].push_back({x,dist});
        }
    }
    void printAdj(){
        for(auto node_pair : m){
            T node = node_pair.first;
            cout<<node<<"-->";
            for(auto nbr : node_pair.second){
                cout<<"("<<nbr.first<<","<<nbr.second<<")";
            }
            cout<<endl;   
        }
    }
    void Dijkstra(T src){
        unordered_map<T,int> dist;
        for(auto node_pair : m){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;
        set<pair<int,T> > s;

        s.insert({0,src});
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;

            int node_dist = p.first;
            s.erase(s.begin());
            for(auto child : m[node]){
                if(node_dist + child.second < dist[child.first]){
                    // IN SET UPDATION IS NOT POSSIBLE
                    T dest = child.first;
                    auto f = s.find({dist[child.first],dest});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = node_dist + child.second;
                    s.insert({dist[dest],dest});
                }
            }
        }
         for(auto d:dist){
            
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
    }

};
int main(){
     Graph<int> g;
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,2);
    // g.addEdge(1,4,7);
    // g.printAdj();
    // g.Dijkstra(1);
    
    
    
    
    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    //india.printAdj();
    india.Dijkstra("Amritsar");


    return 0;
}