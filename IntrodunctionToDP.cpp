#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int mod=1e9+7;
    
    long long  int f(int n,vector<long long int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return  dp[n]=(f(n-1,dp)+f(n-2,dp))%mod;
     }
     
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
         return f(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1) return n;
        long int prev=1;
        long int prev2 =0;
        for(int i=2;i<=n;i++){
            long long int fibo=(prev+prev2)%mod;
            prev2=prev;
            prev=fibo;
        }
        return prev;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}