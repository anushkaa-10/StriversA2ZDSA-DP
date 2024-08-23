class Solution {
public:
int solve(int i, vector<int> &nums,vector<int> &dp){
    if(i==0) return nums[i];
    if(i<0) return 0;

    if(dp[i]!=-1) return dp[i];
    int pick = nums[i] + solve(i-2,nums,dp);
    int npick = solve(i-1,nums,dp);

    return dp[i] = max(pick,npick);
}
int rob1(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(n-1,nums,dp);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> t1,t2;

        for(int i=0; i<n; i++){
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        return max(rob1(t1),rob1(t2));
    }
};