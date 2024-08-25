lass Solution {
public:
bool solve(int i, int k, vector<int> &arr,vector<vector<int>> &dp){
	if(k==0) return true;
	if(i==0) return arr[0]==k;
    if(k<0) return false;

	if(dp[i][k]!=-1) return dp[i][k];

	bool notTake = solve(i-1,k,arr,dp);
	bool take = false;

	if(arr[i]<=k) take = solve(i-1,k-arr[i],arr,dp);

	return dp[i][k]=take || notTake;
}

bool solve2(vector<int> &arr, int k ,int n){
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return solve(n-1,k,arr,dp);
}
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
	for(int i=0; i<n; i++) totalSum +=arr[i];
	if(totalSum%2) return false;
	int target = totalSum/2;

	return solve2(arr,target,n);
    }
};