class Solution {
public:
    int Houses(vector<int>& nums, vector<int>& dp, int i){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int pick=nums[i]+Houses(nums, dp, i-2);
        int notpick=Houses(nums, dp, i-1);
        return dp[i]=max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, -1);
        return Houses(nums, dp, n-1);
        
    }
};