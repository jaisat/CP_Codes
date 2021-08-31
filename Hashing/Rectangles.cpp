#include<bits/stdc++.h>
using namespace std;
class Point{
	
public:
	int x,y;
	Point(int x,int y){
		this->x = x;
		this->y = y;
	}
};
class Compare{
public:
	bool operator()(Point p1,Point p2){
		if(p1.x==p2.x){
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};
vector<Point> cords;
int count_cords(){
	int n = cords.size();

	set<Point,Compare> s;
	for(auto p : cords){
		s.insert(p);
	}
	int ans = 0;
	for(auto it = s.begin();it!=prev(s.end());it++){
		for(auto jt = next(it);jt!=s.end();jt++){
			Point p1 = *it;
			Point p2 = *jt;
			if(p1.x == p2.x or p1.y == p2.y){
				continue;
			}
			Point p3(p1.x,p2.y);
			Point p4(p2.x,p1.y);
			if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
				ans++;

		}
	}
	return ans/2;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int m;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		Point p(x,y);
		cords.push_back(p);
	}
	cout<<count_cords()<<endl;
	return 0;
}