#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int knapsack(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != 0)
        return dp[n][W];
    if (wt[n - 1] <= W) {
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    } else {
        return dp[n][W] = knapsack(wt, val, W, n - 1);
    }
}
int knapsack_iterative(int wt[], int val[], int W, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int val[] = { 0 , 4 , 3 , 1 };
    int wt[] = { 2 , 6 , 5, 2 };
    int W = 4;
    int n = sizeof(wt) / sizeof(int);
    cout << knapsack(wt, val, W, n);
    return 0;
}