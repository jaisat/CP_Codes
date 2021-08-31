    #include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

   int n,m,k;

   cin>>n>>m>>k;

   vector<vector<pii>> g(n);

   for(int i=0;i<m;i++) {

       long long u,v,w;

       cin>>u>>v>>w;

       u--;v--;

       g[u].push_back({v,w});

       g[v].push_back({u,w});

   }

 

   vector<vector<long long>> dp(n,vector<long long>(k+1,INT_MAX));

   // dp[i][j] -> min dist to reach node i using j coupons

   long long s = 0;

   for(int j=0;j<=k;j++)

       dp[s][j] = 0;

   

   set<pair<int,pair<int,int>>> pq;

   // {dist, node, coupons used (k)}

   pq.insert({0,{s,0}});

 

   while(!pq.empty()) {

       long long u = (pq.begin()->second).first, j = (pq.begin()->second).second;

       pq.erase(pq.begin());

 

       for(int i=0;i<g[u].size();i++) {

           long long v = g[u][i].first, w = g[u][i].second;

       

           if(dp[v][j] > dp[u][j] + w) {

               pq.erase({dp[v][j],{v,j}});

               dp[v][j] = dp[u][j] + w;    // from u,j we can either go to v,j state (spending no coupons)

               pq.insert({dp[v][j],{v,j}});

               

           }

           if(j!=k && dp[v][j+1] > dp[u][j]) {

               pq.erase({dp[v][j+1],{v,j+1}});

               dp[v][j+1] = dp[u][j];      // or reach v,j+1 state (spending 1 coupon)

               pq.insert({dp[v][j+1],{v,j+1}});

           }                

       }

   }

 

   for(int i=0;i<n;i++) {

       long long ans = dp[i][0];

       for(int j=1;j<=k;j++) {

           ans = min(ans,dp[i][j]);

       }

       cout<<ans<<" ";

   }

   cout<<endl;

   return 0;
}