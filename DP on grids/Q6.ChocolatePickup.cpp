#include <bits/stdc++.h> 
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &a, vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=c ||j2<0 || j2>=c) return -1e8;
    if(i==r-1){
        if(j1==j2) return a[i][j1];
        else return a[i][j1]+a[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    //exploring paths nowww (i+1,j-1), (i+1,j),(i+1,j+1) i to constant haii
    int maxi = -1e8;
    for(int js1 = -1; js1<=1; js1++){
        for(int js2 = -1; js2<=1; js2++){
            if(j1==j2) maxi = max(maxi,a[i][j1]+solve(i+1,j1+js1,j2+js2,r,c,a,dp));
            else maxi = max(maxi,a[i][j1]+a[i][j2]+solve(i+1,j1+js1,j2+js2,r,c,a,dp));
        }
    }
    return dp[i][j1][j2] = maxi;

}
int maximumChocolates(int r, int c, vector<vector<int>> &a) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,r,c,a,dp);
}