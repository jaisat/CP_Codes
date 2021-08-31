#include<bits/stdc++.h>
using namespace std;
int n;
int ans_;
int dp[100005];
void max_P(int price[],int i,int n,int stock,int ans){
if(i ==  n){
    ans_ = max(ans_,ans);
}
// if(dp[i] != -1)
// return dp[i];
 max_P(price,i+1,n,stock+1,ans-price[i]);

for(int j=1;j<=stock;j++){
    max_P(price,i+1,n,stock-j,ans+price[i]*j);
}
max_P(price,i+1,n,stock,ans);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        int price[n];
        for(int i=0;i<n;++i){
            cin>>price[i];
        }
        max_P(price,0,n,0,0);
        cout<<ans_<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}