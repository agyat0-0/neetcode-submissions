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
        
        bitset<10001>dp;
        dp[0] = 1;
        for(int& num: nums)
        {
            dp |= dp << num;
        }
        return dp[target];
    }
};
