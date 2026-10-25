class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long totalSum = 0;
        for(int & num: nums)
        {
            totalSum += num;
        }
        if(totalSum % 2 !=0 )return false;
        int target = totalSum / 2;
        
        vector<int> dp(target + 1, false);
        dp[0] = true;
        for (int & num : nums)
        {
            for(int s = target; s >= num; s--)
            {
                if(dp[s-num])dp[s] = true;
            }
        }
        return dp[target];
    }
};
