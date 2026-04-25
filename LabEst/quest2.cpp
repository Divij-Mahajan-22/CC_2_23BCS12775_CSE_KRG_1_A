class Solution {
public:
    vector<unordered_map<int,int>> dp;
    int solve(auto& nums,int idx,int t){
        if(idx==nums.size())
            return t==0;
        if(dp[idx].count(t))
            return dp[idx][t];
        int n_cnt=solve(nums,idx+1,t-nums[idx]);
        int p_cnt=solve(nums,idx+1,t+nums[idx]);
        return dp[idx][t]=n_cnt+p_cnt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size());
        return solve(nums,0,target);
    }
};
